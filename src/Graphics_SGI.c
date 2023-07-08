#include "Core.h"
#if defined CC_BUILD_GL && defined CC_BUILD_IRIX
#include "_GraphicsBase.h"
#include "Errors.h"
#include "Logger.h"
#include "Window.h"

#include <GL/gl.h>

typedef enum {
	NONE,
	TEXTURE,
	VARRAY,
	IARRAY
} ResourceType;

typedef struct GLResource {
	ResourceType type;
	union {
		GLuint texId;
		void *ptr;
	} data;
	int count;
} GLResource;

static cc_uint16 gl_indices[GFX_MAX_INDICES];
static GLResource *activeIndexArray = NULL;
static GLResource *activeVertexArray = NULL;

int sgitexbinds = 0;
int sgidrawcalls = 0;

#include "_GLShared.h"

#define TEXTURE_BUF_SIZE (64 * 64 * 4)
static unsigned char TexBuf[TEXTURE_BUF_SIZE];

GfxResourceID Gfx_CreateTexture(struct Bitmap* bmp, cc_uint8 flags, cc_bool mipmaps) {
	GLuint texId;
	unsigned char *srcp = (unsigned char *)bmp->scan0;
	unsigned char *dstp = (unsigned char *)TexBuf;
	int count = bmp->width * bmp->height * 4;
	unsigned char *newt;

	if (count > TEXTURE_BUF_SIZE) {
		dstp = Mem_Alloc(count, 1, "Gfx_CreateTexture temp");
	}

	newt = dstp;

	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (!Math_IsPowOf2(bmp->width) || !Math_IsPowOf2(bmp->height)) {
		Logger_Abort("Textures must have power of two dimensions");
	}
	if (Gfx.LostContext) return 0;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	for (int y = 0; y < bmp->height; y++) {
		for (int x = 0; x < bmp->width; x++) {
			dstp[0] = srcp[1];
			dstp[1] = srcp[2];
			dstp[2] = srcp[3];
			dstp[3] = srcp[0];
			dstp += 4;
			srcp += 4;
		}
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bmp->width, bmp->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, newt);

	if (count > TEXTURE_BUF_SIZE) Mem_Free(newt);

	GLResource *resource = (GLResource *)Mem_Alloc(1, sizeof(GLResource), "GL texture resource");
	resource->type = TEXTURE;
	resource->data.texId = texId;
	return resource;
}

void Gfx_UpdateTexture(GfxResourceID texId, int x, int y, struct Bitmap* part, int rowWidth, cc_bool mipmaps) {
	void* ptr = (void*)TexBuf;
	int count = part->width * part->height * 4;
	unsigned char *srcp;

	GLResource *resource = (GLResource *)texId;
	if (!resource) return;

	glBindTexture(GL_TEXTURE_2D, (GLuint)resource->data.texId);

	/* cannot allocate memory on the stack for very big updates */
	if (count > TEXTURE_BUF_SIZE) {
		ptr = Mem_Alloc(count, 1, "Gfx_UpdateTexture temp");
	}

	srcp = (unsigned char *)ptr;

	CopyTextureData(ptr, part->width << 2, part, rowWidth << 2);

	for (int y = 0; y < part->height; y++) {
		for (int x = 0; x < part->width; x++) {
			unsigned char t = srcp[0];
			srcp[0] = srcp[1];
			srcp[1] = srcp[2];
			srcp[2] = srcp[3];
			srcp[3] = t;
			srcp += 4;
		}
	}

	glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, part->width, part->height, GL_RGBA, GL_UNSIGNED_BYTE, ptr);

	if (count > TEXTURE_BUF_SIZE) Mem_Free(ptr);
}

void Gfx_DeleteTexture(GfxResourceID* texId) {
	GLResource *resource = (GLResource *)*texId;
	if (!resource) return;
	if (!resource->data.texId) return;
	glDeleteTextures(1, &resource->data.texId);
	Mem_Free(resource);
	*texId = 0;
}

typedef void (*GL_SetupVBFunc)(void);
typedef void (*GL_SetupVBRangeFunc)(int startVertex);
static GL_SetupVBFunc gfx_setupVBFunc;
static GL_SetupVBRangeFunc gfx_setupVBRangeFunc;
/* Current format and size of vertices */
static int gfx_stride, gfx_format = -1;

/*########################################################################################################################*
*-------------------------------------------------------Index buffers-----------------------------------------------------*
*#########################################################################################################################*/
static void GL_DelBuffer(GfxResourceID id) {
	GLResource *resource = (GLResource *)id;
	if (resource) {
		if (resource->type == VARRAY || resource->type == IARRAY) {
			if (resource->data.ptr) {
				Mem_Free(resource->data.ptr);
				resource->data.ptr = NULL;
			}
		}
		Mem_Free(resource);
	}
}

GfxResourceID Gfx_CreateIb2(int count, Gfx_FillIBFunc fillFunc, void* obj) {
	GLResource *resource = (GLResource *)Mem_Alloc(1, sizeof(GLResource), "GL buffer");
	resource->type = IARRAY;
	resource->data.ptr = (cc_uint16 *)Mem_Alloc(count, 2, "GL index array");
	resource->count = count;

	cc_uint32 size   = count * sizeof(cc_uint16);

	activeIndexArray = resource;

	fillFunc(resource->data.ptr, count, obj);
	return (GfxResourceID)resource;
}

void Gfx_BindIb(GfxResourceID ib) {
	GLResource *resource = (GLResource *)ib;

	activeIndexArray = resource;
}

void Gfx_DeleteIb(GfxResourceID* ib) {
	GL_DelBuffer(*ib);
	*ib = 0;
}


/*########################################################################################################################*
*------------------------------------------------------Vertex buffers-----------------------------------------------------*
*#########################################################################################################################*/
GfxResourceID Gfx_CreateVb(VertexFormat fmt, int count) {
	GLResource *resource = (GLResource *)Mem_Alloc(1, sizeof(GLResource), "GL buffer");
	resource->type = VARRAY;
	resource->data.ptr = Mem_Alloc(count, strideSizes[fmt], "GL vertex array");
	resource->count = count;

	activeVertexArray = resource;
	return (GfxResourceID)resource;
}

void Gfx_BindVb(GfxResourceID vb) { 
	GLResource *resource = (GLResource *)vb;
	activeVertexArray = resource;
}

void Gfx_DeleteVb(GfxResourceID* vb) {
	GL_DelBuffer(*vb);
	*vb = 0;
}

void* Gfx_LockVb(GfxResourceID vb, VertexFormat fmt, int count) {
	GLResource *resource = (GLResource *)vb;
	activeVertexArray = resource;
	return resource->data.ptr;
	//return FastAllocTempMem(count * strideSizes[fmt]);
}

void Gfx_UnlockVb(GfxResourceID vb) {
	GLResource *resource = (GLResource *)vb;
	//memcpy(resource->data.ptr, tmpData, tmpSize);
	activeVertexArray = resource;
}


/*########################################################################################################################*
*--------------------------------------------------Dynamic vertex buffers-------------------------------------------------*
*#########################################################################################################################*/
GfxResourceID Gfx_CreateDynamicVb(VertexFormat fmt, int maxVertices) {
	return Gfx_CreateVb(fmt, maxVertices);
}

void* Gfx_LockDynamicVb(GfxResourceID vb, VertexFormat fmt, int count) {
	return Gfx_LockVb(vb, fmt, count);
}

void Gfx_UnlockDynamicVb(GfxResourceID vb) {
	Gfx_UnlockVb(vb);
}

void Gfx_SetDynamicVbData(GfxResourceID vb, void* vertices, int vCount) {
	GLResource *resource = (GLResource *)vb;
	cc_uint32 size = vCount * gfx_stride;
	activeVertexArray = resource;
	memcpy(resource->data.ptr, vertices, size);
}

void Gfx_BindDynamicVb(GfxResourceID vb) {
	Gfx_BindVb(vb);
}

void Gfx_DeleteDynamicVb(GfxResourceID* vb) {
	Gfx_DeleteVb(vb);
}

/*########################################################################################################################*
*---------------------------------------------------------Textures--------------------------------------------------------*
*#########################################################################################################################*/
void Gfx_BindTexture(GfxResourceID texId) {
	GLResource *resource = (GLResource *)texId;
	if (resource) {
sgitexbinds++;
		glBindTexture(GL_TEXTURE_2D, (GLuint)resource->data.texId);
	}
}


/*########################################################################################################################*
*-----------------------------------------------------State management----------------------------------------------------*
*#########################################################################################################################*/
static PackedCol gfx_fogColor;
static float gfx_fogEnd = -1.0f, gfx_fogDensity = -1.0f;
static int gfx_fogMode  = -1;

void Gfx_SetFog(cc_bool enabled) {
	gfx_fogEnabled = enabled;
	if (enabled) { glEnable(GL_FOG); } else { glDisable(GL_FOG); }
}

void Gfx_SetFogCol(PackedCol color) {
	float rgba[4];
	if (color == gfx_fogColor) return;

	rgba[0] = PackedCol_R(color) / 255.0f; 
	rgba[1] = PackedCol_G(color) / 255.0f;
	rgba[2] = PackedCol_B(color) / 255.0f; 
	rgba[3] = PackedCol_A(color) / 255.0f;

	glFogfv(GL_FOG_COLOR, rgba);
	gfx_fogColor = color;
}

void Gfx_SetFogDensity(float value) {
	if (value == gfx_fogDensity) return;
	glFogf(GL_FOG_DENSITY, value);
	gfx_fogDensity = value;
}

void Gfx_SetFogEnd(float value) {
	if (value == gfx_fogEnd) return;
	glFogf(GL_FOG_END, value);
	gfx_fogEnd = value;
}

void Gfx_SetFogMode(FogFunc func) {
	static GLint modes[3] = { GL_LINEAR, GL_EXP, GL_EXP2 };
	if (func == gfx_fogMode) return;

	glFogi(GL_FOG_MODE, modes[func]);
	gfx_fogMode = func;
}

void Gfx_SetTexturing(cc_bool enabled) { }

void Gfx_SetAlphaTest(cc_bool enabled) { 
	if (enabled) { glEnable(GL_ALPHA_TEST); } else { glDisable(GL_ALPHA_TEST); }
}

void Gfx_DepthOnlyRendering(cc_bool depthOnly) {
	cc_bool enabled = !depthOnly;
	Gfx_SetColWriteMask(enabled, enabled, enabled, enabled);
	if (enabled) { glEnable(GL_TEXTURE_2D); } else { glDisable(GL_TEXTURE_2D); }
}


/*########################################################################################################################*
*---------------------------------------------------------Matrices--------------------------------------------------------*
*#########################################################################################################################*/
static GLenum matrix_modes[3] = { GL_PROJECTION, GL_MODELVIEW, GL_TEXTURE };
static int lastMatrix;

void Gfx_LoadMatrix(MatrixType type, const struct Matrix* matrix) {
	if (type != lastMatrix) { lastMatrix = type; glMatrixMode(matrix_modes[type]); }
	glLoadMatrixf((const float*)matrix);
}

void Gfx_LoadIdentityMatrix(MatrixType type) {
	if (type != lastMatrix) { lastMatrix = type; glMatrixMode(matrix_modes[type]); }
	glLoadIdentity();
}

static struct Matrix texMatrix = Matrix_IdentityValue;
void Gfx_EnableTextureOffset(float x, float y) {
	texMatrix.row4.X = x; texMatrix.row4.Y = y;
	Gfx_LoadMatrix(2, &texMatrix);
}

void Gfx_DisableTextureOffset(void) { Gfx_LoadIdentityMatrix(2); }


/*########################################################################################################################*
*-------------------------------------------------------State setup-------------------------------------------------------*
*#########################################################################################################################*/
static void Gfx_FreeState(void) { FreeDefaultResources(); }
static void Gfx_RestoreState(void) {
	InitDefaultResources();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	gfx_format = -1;
	glHint(GL_FOG_HINT, GL_NICEST);
	glAlphaFunc(GL_GREATER, 0.5f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
}

cc_bool Gfx_WarnIfNecessary(void) {
	cc_string renderer = String_FromReadonly((const char*)glGetString(GL_RENDERER));

#ifdef CC_BUILD_WIN
	Chat_AddRaw("&cTry downloading the Direct3D 9 build instead.");
#endif
	return true;
}


/*########################################################################################################################*
*-------------------------------------------------------Compatibility-----------------------------------------------------*
*#########################################################################################################################*/
static void GLBackend_Init(void) { 
	MakeIndices(gl_indices, GFX_MAX_INDICES, NULL);
}

/*########################################################################################################################*
*----------------------------------------------------------Drawing--------------------------------------------------------*
*#########################################################################################################################*/
#define VB_PTR ((cc_uint8 *)(activeVertexArray->data.ptr))
#define IB_PTR gl_indices
//((unsigned short *)gl_indices)
//((unsigned short *)activeIndexArray->data.ptr)

static void GL_SetupVbColoured(void) {
	glVertexPointer(3, GL_FLOAT,        SIZEOF_VERTEX_COLOURED, (void*)(VB_PTR + 0));
	glColorPointer(4, GL_UNSIGNED_BYTE, SIZEOF_VERTEX_COLOURED, (void*)(VB_PTR + 12));
}

static void GL_SetupVbTextured(void) {
	glVertexPointer(3, GL_FLOAT,        SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + 0));
	glColorPointer(4, GL_UNSIGNED_BYTE, SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + 12));
	glTexCoordPointer(2, GL_FLOAT,      SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + 16));
}

static void GL_SetupVbColoured_Range(int startVertex) {
	cc_uint32 offset = startVertex * SIZEOF_VERTEX_COLOURED;
	glVertexPointer(3, GL_FLOAT,          SIZEOF_VERTEX_COLOURED, (void*)(VB_PTR + offset));
	glColorPointer(4, GL_UNSIGNED_BYTE,   SIZEOF_VERTEX_COLOURED, (void*)(VB_PTR + offset + 12));
}

static void GL_SetupVbTextured_Range(int startVertex) {
	cc_uint32 offset = startVertex * SIZEOF_VERTEX_TEXTURED;
	glVertexPointer(3,  GL_FLOAT,         SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + offset));
	glColorPointer(4, GL_UNSIGNED_BYTE,   SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + offset + 12));
	glTexCoordPointer(2, GL_FLOAT,        SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + offset + 16));
}

void Gfx_SetVertexFormat(VertexFormat fmt) {
	if (fmt == gfx_format) return;
	gfx_format = fmt;
	gfx_stride = strideSizes[fmt];

	if (fmt == VERTEX_FORMAT_TEXTURED) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D);

		gfx_setupVBFunc      = GL_SetupVbTextured;
		gfx_setupVBRangeFunc = GL_SetupVbTextured_Range;
	} else {
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisable(GL_TEXTURE_2D);

		gfx_setupVBFunc      = GL_SetupVbColoured;
		gfx_setupVBRangeFunc = GL_SetupVbColoured_Range;
	}
}

void Gfx_DrawVb_Lines(int verticesCount) {
sgidrawcalls++;
	gfx_setupVBFunc();
	glDrawArrays(GL_LINES, 0, verticesCount);
}

void Gfx_DrawVb_IndexedTris_Range(int verticesCount, int startVertex) {
sgidrawcalls++;
	gfx_setupVBRangeFunc(startVertex);
	glDrawElements(GL_TRIANGLES, ICOUNT(verticesCount), GL_UNSIGNED_SHORT, IB_PTR);
}

void Gfx_DrawVb_IndexedTris(int verticesCount) {
sgidrawcalls++;
	gfx_setupVBFunc();
	glDrawElements(GL_TRIANGLES, ICOUNT(verticesCount), GL_UNSIGNED_SHORT, IB_PTR);
}

void Gfx_DrawIndexedTris_T2fC4b(int verticesCount, int startVertex) {
sgidrawcalls++;
	cc_uint32 offset = startVertex * SIZEOF_VERTEX_TEXTURED;
	glVertexPointer(3, GL_FLOAT,        SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + offset));
	glColorPointer(4, GL_UNSIGNED_BYTE, SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + offset + 12));
	glTexCoordPointer(2, GL_FLOAT,      SIZEOF_VERTEX_TEXTURED, (void*)(VB_PTR + offset + 16));
	glDrawElements(GL_TRIANGLES,        ICOUNT(verticesCount),   GL_UNSIGNED_SHORT, IB_PTR);
}
#endif
