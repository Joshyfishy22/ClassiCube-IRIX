C_SOURCES:=$(wildcard src/*.c)
C_OBJECTS:=$(patsubst %.c, %.o, $(C_SOURCES))
OBJECTS:=$(C_OBJECTS)
ENAME=ClassiCube
DEL=rm -f
CFLAGS=-g -pipe -fno-math-errno
LDFLAGS=-g -rdynamic

ifndef $(PLAT)
	ifeq ($(OS),Windows_NT)
		PLAT=mingw
	else
		PLAT=$(shell uname -s | tr '[:upper:]' '[:lower:]')
	endif
	
	ifeq ($(PLAT),darwin)
		ifeq ($(shell uname -m), x86_64)
			PLAT=mac_x64
		else
			PLAT=mac_x32
		endif
	endif
endif

ifeq ($(PLAT),web)
CC=emcc
OEXT=.html
CFLAGS=-g
LDFLAGS=-s WASM=1 -s NO_EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1
endif

ifeq ($(PLAT),mingw)
CC=gcc
OEXT=.exe
CFLAGS=-g -pipe -DUNICODE -fno-math-errno
LDFLAGS=-g
LIBS=-mwindows -lwinmm -limagehlp
endif

ifeq ($(PLAT),linux)
LIBS=-lX11 -lXi -lpthread -lGL -lm -ldl
endif

ifeq ($(PLAT),sunos)
CFLAGS=-g -pipe -fno-math-errno
LIBS=-lm -lsocket -lX11 -lXi -lGL
endif

ifeq ($(PLAT),mac_x32)
CFLAGS=-g -m32 -pipe -fno-math-errno
LIBS=
LDFLAGS=-rdynamic -framework Carbon -framework AGL -framework OpenGL -framework IOKit
endif

ifeq ($(PLAT),mac_x64)
OBJECTS+=src/interop_cocoa.o
CFLAGS=-g -m64 -pipe -fno-math-errno
LIBS=
LDFLAGS=-rdynamic -framework Cocoa -framework OpenGL -framework IOKit -lobjc
endif

ifeq ($(PLAT),freebsd)
CFLAGS=-g -pipe -I /usr/local/include -fno-math-errno
LDFLAGS=-L /usr/local/lib -rdynamic
LIBS=-lexecinfo -lGL -lX11 -lXi -lm -lpthread
endif

ifeq ($(PLAT),openbsd)
CFLAGS=-g -pipe -I /usr/X11R6/include -I /usr/local/include -fno-math-errno
LDFLAGS=-L /usr/X11R6/lib -L /usr/local/lib -rdynamic
LIBS=-lexecinfo -lGL -lX11 -lXi -lm -lpthread
endif

ifeq ($(PLAT),netbsd)
CFLAGS=-g -pipe -I /usr/X11R7/include -I /usr/pkg/include -fno-math-errno
LDFLAGS=-L /usr/X11R7/lib -L /usr/pkg/lib -rdynamic
LIBS=-lexecinfo -lGL -lX11 -lXi -lpthread
endif

ifeq ($(PLAT),dragonfly)
CFLAGS=-g -pipe -I /usr/local/include -fno-math-errno
LDFLAGS=-L /usr/local/lib -rdynamic
LIBS=-lexecinfo -lGL -lX11 -lXi -lm -lpthread
endif

ifeq ($(PLAT),haiku)
OBJECTS+=src/interop_BeOS.o
CFLAGS=-g -pipe -fno-math-errno
LDFLAGS=-g
LIBS=-lm -lGL -lnetwork -lstdc++ -lbe -lgame -ltracker
endif

ifeq ($(PLAT),beos)
OBJECTS+=src/interop_BeOS.o
CFLAGS=-g -pipe
LDFLAGS=-g
LIBS=-lGL -lnetwork -lstdc++ -lbe -lgame -ltracker
endif

ifeq ($(PLAT),serenityos)
LIBS=-lgl -lSDL2
endif

ifeq ($(PLAT),irix)
CC=gcc
LIBS=-lGL -lX11 -lXi -lm -lpthread -ldl 
LDFLAGS=-Wl,-rpath-link=/usr/lib32 -Wl,-rpath=/usr/lib32:/usr/sgug/lib32
endif

ifeq ($(PLAT),irix64)
CC=c99
CFLAGS=-O2 -n32 -mips3 -DCC_BUILD_GL11 -DCC_BUILD_NOSOUNDS -DCC_BUILD_NOMUSIC  
LIBS=-lGL -lX11 -lXi -lm -lpthread -ldl 
LDFLAGS=-mips3
endif

ifeq ($(OS),Windows_NT)
DEL=del
endif

default: $(PLAT)

web:
	$(MAKE) $(ENAME) PLAT=web
linux:
	$(MAKE) $(ENAME) PLAT=linux
mingw:
	$(MAKE) $(ENAME) PLAT=mingw
sunos:
	$(MAKE) $(ENAME) PLAT=sunos
mac_x32:
	$(MAKE) $(ENAME) PLAT=mac_x32
mac_x64:
	$(MAKE) $(ENAME) PLAT=mac_x64
freebsd:
	$(MAKE) $(ENAME) PLAT=freebsd
openbsd:
	$(MAKE) $(ENAME) PLAT=openbsd
netbsd:
	$(MAKE) $(ENAME) PLAT=netbsd
dragonfly:
	$(MAKE) $(ENAME) PLAT=dragonfly
haiku:
	$(MAKE) $(ENAME) PLAT=haiku
beos:
	$(MAKE) $(ENAME) PLAT=beos
serenityos:
	$(MAKE) $(ENAME) PLAT=serenityos
irix64:
	$(MAKE) $(ENAME) PLAT=irix64
irix:
	$(MAKE) $(ENAME) PLAT=irix
	
# consoles builds require special handling, so are moved to
#  separate makefiles to avoid having one giant messy makefile
psp:
	$(MAKE) -f src/Makefile_PSP PLAT=psp
3ds:
	$(MAKE) -f src/Makefile_3DS PLAT=3ds
wii:
	$(MAKE) -f src/Makefile_wii PLAT=wii
gamecube:
	$(MAKE) -f src/Makefile_gamecube PLAT=gamecube
xbox:
	$(MAKE) -f src/Makefile_xbox PLAT=xbox
vita:
	$(MAKE) -f src/Makefile_vita PLAT=vita
dreamcast:
	$(MAKE) -f src/Makefile_dreamcast PLAT=dreamcast
	
clean:
	$(DEL) $(OBJECTS)

$(ENAME): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@$(OEXT) $(OBJECTS) $(LIBS)

$(C_OBJECTS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
src/interop_cocoa.o: src/interop_cocoa.m
	$(CC) $(CFLAGS) -c $< -o $@
	
src/interop_BeOS.o: src/interop_BeOS.cpp
	$(CC) $(CFLAGS) -c $< -o $@
