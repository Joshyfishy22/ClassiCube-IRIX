// This file includes the following root certificates:
//  - DigiCert Global Root (dropbox.com)
//  - DigiCert Global Root G2 (resources.download.minecraft.net)
//  - ISRG Root X1 (catbox.moe)
//  - ISRG Root X2 (123dmwm.com, garbage.loan)
//  - Baltimore CyberTrust Root (classicube.net)
//  - USERTrust RSA (imgur.com)
// Generated using "brssl -ta [cert 1] [cert 2].." from BearSSL

static const unsigned char TA0_DN[] = {
	0x30, 0x61, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x55, 0x53, 0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x13, 0x0C, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74, 0x20, 0x49,
	0x6E, 0x63, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13,
	0x10, 0x77, 0x77, 0x77, 0x2E, 0x64, 0x69, 0x67, 0x69, 0x63, 0x65, 0x72,
	0x74, 0x2E, 0x63, 0x6F, 0x6D, 0x31, 0x20, 0x30, 0x1E, 0x06, 0x03, 0x55,
	0x04, 0x03, 0x13, 0x17, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74,
	0x20, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x20, 0x52, 0x6F, 0x6F, 0x74,
	0x20, 0x43, 0x41
};

static const unsigned char TA0_RSA_N[] = {
	0xE2, 0x3B, 0xE1, 0x11, 0x72, 0xDE, 0xA8, 0xA4, 0xD3, 0xA3, 0x57, 0xAA,
	0x50, 0xA2, 0x8F, 0x0B, 0x77, 0x90, 0xC9, 0xA2, 0xA5, 0xEE, 0x12, 0xCE,
	0x96, 0x5B, 0x01, 0x09, 0x20, 0xCC, 0x01, 0x93, 0xA7, 0x4E, 0x30, 0xB7,
	0x53, 0xF7, 0x43, 0xC4, 0x69, 0x00, 0x57, 0x9D, 0xE2, 0x8D, 0x22, 0xDD,
	0x87, 0x06, 0x40, 0x00, 0x81, 0x09, 0xCE, 0xCE, 0x1B, 0x83, 0xBF, 0xDF,
	0xCD, 0x3B, 0x71, 0x46, 0xE2, 0xD6, 0x66, 0xC7, 0x05, 0xB3, 0x76, 0x27,
	0x16, 0x8F, 0x7B, 0x9E, 0x1E, 0x95, 0x7D, 0xEE, 0xB7, 0x48, 0xA3, 0x08,
	0xDA, 0xD6, 0xAF, 0x7A, 0x0C, 0x39, 0x06, 0x65, 0x7F, 0x4A, 0x5D, 0x1F,
	0xBC, 0x17, 0xF8, 0xAB, 0xBE, 0xEE, 0x28, 0xD7, 0x74, 0x7F, 0x7A, 0x78,
	0x99, 0x59, 0x85, 0x68, 0x6E, 0x5C, 0x23, 0x32, 0x4B, 0xBF, 0x4E, 0xC0,
	0xE8, 0x5A, 0x6D, 0xE3, 0x70, 0xBF, 0x77, 0x10, 0xBF, 0xFC, 0x01, 0xF6,
	0x85, 0xD9, 0xA8, 0x44, 0x10, 0x58, 0x32, 0xA9, 0x75, 0x18, 0xD5, 0xD1,
	0xA2, 0xBE, 0x47, 0xE2, 0x27, 0x6A, 0xF4, 0x9A, 0x33, 0xF8, 0x49, 0x08,
	0x60, 0x8B, 0xD4, 0x5F, 0xB4, 0x3A, 0x84, 0xBF, 0xA1, 0xAA, 0x4A, 0x4C,
	0x7D, 0x3E, 0xCF, 0x4F, 0x5F, 0x6C, 0x76, 0x5E, 0xA0, 0x4B, 0x37, 0x91,
	0x9E, 0xDC, 0x22, 0xE6, 0x6D, 0xCE, 0x14, 0x1A, 0x8E, 0x6A, 0xCB, 0xFE,
	0xCD, 0xB3, 0x14, 0x64, 0x17, 0xC7, 0x5B, 0x29, 0x9E, 0x32, 0xBF, 0xF2,
	0xEE, 0xFA, 0xD3, 0x0B, 0x42, 0xD4, 0xAB, 0xB7, 0x41, 0x32, 0xDA, 0x0C,
	0xD4, 0xEF, 0xF8, 0x81, 0xD5, 0xBB, 0x8D, 0x58, 0x3F, 0xB5, 0x1B, 0xE8,
	0x49, 0x28, 0xA2, 0x70, 0xDA, 0x31, 0x04, 0xDD, 0xF7, 0xB2, 0x16, 0xF2,
	0x4C, 0x0A, 0x4E, 0x07, 0xA8, 0xED, 0x4A, 0x3D, 0x5E, 0xB5, 0x7F, 0xA3,
	0x90, 0xC3, 0xAF, 0x27
};

static const unsigned char TA0_RSA_E[] = {
	0x01, 0x00, 0x01
};

static const unsigned char TA1_DN[] = {
	0x30, 0x61, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x55, 0x53, 0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x13, 0x0C, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74, 0x20, 0x49,
	0x6E, 0x63, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13,
	0x10, 0x77, 0x77, 0x77, 0x2E, 0x64, 0x69, 0x67, 0x69, 0x63, 0x65, 0x72,
	0x74, 0x2E, 0x63, 0x6F, 0x6D, 0x31, 0x20, 0x30, 0x1E, 0x06, 0x03, 0x55,
	0x04, 0x03, 0x13, 0x17, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74,
	0x20, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x20, 0x52, 0x6F, 0x6F, 0x74,
	0x20, 0x47, 0x32
};

static const unsigned char TA1_RSA_N[] = {
	0xBB, 0x37, 0xCD, 0x34, 0xDC, 0x7B, 0x6B, 0xC9, 0xB2, 0x68, 0x90, 0xAD,
	0x4A, 0x75, 0xFF, 0x46, 0xBA, 0x21, 0x0A, 0x08, 0x8D, 0xF5, 0x19, 0x54,
	0xC9, 0xFB, 0x88, 0xDB, 0xF3, 0xAE, 0xF2, 0x3A, 0x89, 0x91, 0x3C, 0x7A,
	0xE6, 0xAB, 0x06, 0x1A, 0x6B, 0xCF, 0xAC, 0x2D, 0xE8, 0x5E, 0x09, 0x24,
	0x44, 0xBA, 0x62, 0x9A, 0x7E, 0xD6, 0xA3, 0xA8, 0x7E, 0xE0, 0x54, 0x75,
	0x20, 0x05, 0xAC, 0x50, 0xB7, 0x9C, 0x63, 0x1A, 0x6C, 0x30, 0xDC, 0xDA,
	0x1F, 0x19, 0xB1, 0xD7, 0x1E, 0xDE, 0xFD, 0xD7, 0xE0, 0xCB, 0x94, 0x83,
	0x37, 0xAE, 0xEC, 0x1F, 0x43, 0x4E, 0xDD, 0x7B, 0x2C, 0xD2, 0xBD, 0x2E,
	0xA5, 0x2F, 0xE4, 0xA9, 0xB8, 0xAD, 0x3A, 0xD4, 0x99, 0xA4, 0xB6, 0x25,
	0xE9, 0x9B, 0x6B, 0x00, 0x60, 0x92, 0x60, 0xFF, 0x4F, 0x21, 0x49, 0x18,
	0xF7, 0x67, 0x90, 0xAB, 0x61, 0x06, 0x9C, 0x8F, 0xF2, 0xBA, 0xE9, 0xB4,
	0xE9, 0x92, 0x32, 0x6B, 0xB5, 0xF3, 0x57, 0xE8, 0x5D, 0x1B, 0xCD, 0x8C,
	0x1D, 0xAB, 0x95, 0x04, 0x95, 0x49, 0xF3, 0x35, 0x2D, 0x96, 0xE3, 0x49,
	0x6D, 0xDD, 0x77, 0xE3, 0xFB, 0x49, 0x4B, 0xB4, 0xAC, 0x55, 0x07, 0xA9,
	0x8F, 0x95, 0xB3, 0xB4, 0x23, 0xBB, 0x4C, 0x6D, 0x45, 0xF0, 0xF6, 0xA9,
	0xB2, 0x95, 0x30, 0xB4, 0xFD, 0x4C, 0x55, 0x8C, 0x27, 0x4A, 0x57, 0x14,
	0x7C, 0x82, 0x9D, 0xCD, 0x73, 0x92, 0xD3, 0x16, 0x4A, 0x06, 0x0C, 0x8C,
	0x50, 0xD1, 0x8F, 0x1E, 0x09, 0xBE, 0x17, 0xA1, 0xE6, 0x21, 0xCA, 0xFD,
	0x83, 0xE5, 0x10, 0xBC, 0x83, 0xA5, 0x0A, 0xC4, 0x67, 0x28, 0xF6, 0x73,
	0x14, 0x14, 0x3D, 0x46, 0x76, 0xC3, 0x87, 0x14, 0x89, 0x21, 0x34, 0x4D,
	0xAF, 0x0F, 0x45, 0x0C, 0xA6, 0x49, 0xA1, 0xBA, 0xBB, 0x9C, 0xC5, 0xB1,
	0x33, 0x83, 0x29, 0x85
};

static const unsigned char TA1_RSA_E[] = {
	0x01, 0x00, 0x01
};

static const unsigned char TA2_DN[] = {
	0x30, 0x4F, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x55, 0x53, 0x31, 0x29, 0x30, 0x27, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x13, 0x20, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x65, 0x74, 0x20, 0x53,
	0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x20, 0x52, 0x65, 0x73, 0x65,
	0x61, 0x72, 0x63, 0x68, 0x20, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x31, 0x15,
	0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0C, 0x49, 0x53, 0x52,
	0x47, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x58, 0x31
};

static const unsigned char TA2_RSA_N[] = {
	0xAD, 0xE8, 0x24, 0x73, 0xF4, 0x14, 0x37, 0xF3, 0x9B, 0x9E, 0x2B, 0x57,
	0x28, 0x1C, 0x87, 0xBE, 0xDC, 0xB7, 0xDF, 0x38, 0x90, 0x8C, 0x6E, 0x3C,
	0xE6, 0x57, 0xA0, 0x78, 0xF7, 0x75, 0xC2, 0xA2, 0xFE, 0xF5, 0x6A, 0x6E,
	0xF6, 0x00, 0x4F, 0x28, 0xDB, 0xDE, 0x68, 0x86, 0x6C, 0x44, 0x93, 0xB6,
	0xB1, 0x63, 0xFD, 0x14, 0x12, 0x6B, 0xBF, 0x1F, 0xD2, 0xEA, 0x31, 0x9B,
	0x21, 0x7E, 0xD1, 0x33, 0x3C, 0xBA, 0x48, 0xF5, 0xDD, 0x79, 0xDF, 0xB3,
	0xB8, 0xFF, 0x12, 0xF1, 0x21, 0x9A, 0x4B, 0xC1, 0x8A, 0x86, 0x71, 0x69,
	0x4A, 0x66, 0x66, 0x6C, 0x8F, 0x7E, 0x3C, 0x70, 0xBF, 0xAD, 0x29, 0x22,
	0x06, 0xF3, 0xE4, 0xC0, 0xE6, 0x80, 0xAE, 0xE2, 0x4B, 0x8F, 0xB7, 0x99,
	0x7E, 0x94, 0x03, 0x9F, 0xD3, 0x47, 0x97, 0x7C, 0x99, 0x48, 0x23, 0x53,
	0xE8, 0x38, 0xAE, 0x4F, 0x0A, 0x6F, 0x83, 0x2E, 0xD1, 0x49, 0x57, 0x8C,
	0x80, 0x74, 0xB6, 0xDA, 0x2F, 0xD0, 0x38, 0x8D, 0x7B, 0x03, 0x70, 0x21,
	0x1B, 0x75, 0xF2, 0x30, 0x3C, 0xFA, 0x8F, 0xAE, 0xDD, 0xDA, 0x63, 0xAB,
	0xEB, 0x16, 0x4F, 0xC2, 0x8E, 0x11, 0x4B, 0x7E, 0xCF, 0x0B, 0xE8, 0xFF,
	0xB5, 0x77, 0x2E, 0xF4, 0xB2, 0x7B, 0x4A, 0xE0, 0x4C, 0x12, 0x25, 0x0C,
	0x70, 0x8D, 0x03, 0x29, 0xA0, 0xE1, 0x53, 0x24, 0xEC, 0x13, 0xD9, 0xEE,
	0x19, 0xBF, 0x10, 0xB3, 0x4A, 0x8C, 0x3F, 0x89, 0xA3, 0x61, 0x51, 0xDE,
	0xAC, 0x87, 0x07, 0x94, 0xF4, 0x63, 0x71, 0xEC, 0x2E, 0xE2, 0x6F, 0x5B,
	0x98, 0x81, 0xE1, 0x89, 0x5C, 0x34, 0x79, 0x6C, 0x76, 0xEF, 0x3B, 0x90,
	0x62, 0x79, 0xE6, 0xDB, 0xA4, 0x9A, 0x2F, 0x26, 0xC5, 0xD0, 0x10, 0xE1,
	0x0E, 0xDE, 0xD9, 0x10, 0x8E, 0x16, 0xFB, 0xB7, 0xF7, 0xA8, 0xF7, 0xC7,
	0xE5, 0x02, 0x07, 0x98, 0x8F, 0x36, 0x08, 0x95, 0xE7, 0xE2, 0x37, 0x96,
	0x0D, 0x36, 0x75, 0x9E, 0xFB, 0x0E, 0x72, 0xB1, 0x1D, 0x9B, 0xBC, 0x03,
	0xF9, 0x49, 0x05, 0xD8, 0x81, 0xDD, 0x05, 0xB4, 0x2A, 0xD6, 0x41, 0xE9,
	0xAC, 0x01, 0x76, 0x95, 0x0A, 0x0F, 0xD8, 0xDF, 0xD5, 0xBD, 0x12, 0x1F,
	0x35, 0x2F, 0x28, 0x17, 0x6C, 0xD2, 0x98, 0xC1, 0xA8, 0x09, 0x64, 0x77,
	0x6E, 0x47, 0x37, 0xBA, 0xCE, 0xAC, 0x59, 0x5E, 0x68, 0x9D, 0x7F, 0x72,
	0xD6, 0x89, 0xC5, 0x06, 0x41, 0x29, 0x3E, 0x59, 0x3E, 0xDD, 0x26, 0xF5,
	0x24, 0xC9, 0x11, 0xA7, 0x5A, 0xA3, 0x4C, 0x40, 0x1F, 0x46, 0xA1, 0x99,
	0xB5, 0xA7, 0x3A, 0x51, 0x6E, 0x86, 0x3B, 0x9E, 0x7D, 0x72, 0xA7, 0x12,
	0x05, 0x78, 0x59, 0xED, 0x3E, 0x51, 0x78, 0x15, 0x0B, 0x03, 0x8F, 0x8D,
	0xD0, 0x2F, 0x05, 0xB2, 0x3E, 0x7B, 0x4A, 0x1C, 0x4B, 0x73, 0x05, 0x12,
	0xFC, 0xC6, 0xEA, 0xE0, 0x50, 0x13, 0x7C, 0x43, 0x93, 0x74, 0xB3, 0xCA,
	0x74, 0xE7, 0x8E, 0x1F, 0x01, 0x08, 0xD0, 0x30, 0xD4, 0x5B, 0x71, 0x36,
	0xB4, 0x07, 0xBA, 0xC1, 0x30, 0x30, 0x5C, 0x48, 0xB7, 0x82, 0x3B, 0x98,
	0xA6, 0x7D, 0x60, 0x8A, 0xA2, 0xA3, 0x29, 0x82, 0xCC, 0xBA, 0xBD, 0x83,
	0x04, 0x1B, 0xA2, 0x83, 0x03, 0x41, 0xA1, 0xD6, 0x05, 0xF1, 0x1B, 0xC2,
	0xB6, 0xF0, 0xA8, 0x7C, 0x86, 0x3B, 0x46, 0xA8, 0x48, 0x2A, 0x88, 0xDC,
	0x76, 0x9A, 0x76, 0xBF, 0x1F, 0x6A, 0xA5, 0x3D, 0x19, 0x8F, 0xEB, 0x38,
	0xF3, 0x64, 0xDE, 0xC8, 0x2B, 0x0D, 0x0A, 0x28, 0xFF, 0xF7, 0xDB, 0xE2,
	0x15, 0x42, 0xD4, 0x22, 0xD0, 0x27, 0x5D, 0xE1, 0x79, 0xFE, 0x18, 0xE7,
	0x70, 0x88, 0xAD, 0x4E, 0xE6, 0xD9, 0x8B, 0x3A, 0xC6, 0xDD, 0x27, 0x51,
	0x6E, 0xFF, 0xBC, 0x64, 0xF5, 0x33, 0x43, 0x4F
};

static const unsigned char TA2_RSA_E[] = {
	0x01, 0x00, 0x01
};

static const unsigned char TA3_DN[] = {
	0x30, 0x4F, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x55, 0x53, 0x31, 0x29, 0x30, 0x27, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x13, 0x20, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x65, 0x74, 0x20, 0x53,
	0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x20, 0x52, 0x65, 0x73, 0x65,
	0x61, 0x72, 0x63, 0x68, 0x20, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x31, 0x15,
	0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0C, 0x49, 0x53, 0x52,
	0x47, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x58, 0x32
};

static const unsigned char TA3_EC_Q[] = {
	0x04, 0xCD, 0x9B, 0xD5, 0x9F, 0x80, 0x83, 0x0A, 0xEC, 0x09, 0x4A, 0xF3,
	0x16, 0x4A, 0x3E, 0x5C, 0xCF, 0x77, 0xAC, 0xDE, 0x67, 0x05, 0x0D, 0x1D,
	0x07, 0xB6, 0xDC, 0x16, 0xFB, 0x5A, 0x8B, 0x14, 0xDB, 0xE2, 0x71, 0x60,
	0xC4, 0xBA, 0x45, 0x95, 0x11, 0x89, 0x8E, 0xEA, 0x06, 0xDF, 0xF7, 0x2A,
	0x16, 0x1C, 0xA4, 0xB9, 0xC5, 0xC5, 0x32, 0xE0, 0x03, 0xE0, 0x1E, 0x82,
	0x18, 0x38, 0x8B, 0xD7, 0x45, 0xD8, 0x0A, 0x6A, 0x6E, 0xE6, 0x00, 0x77,
	0xFB, 0x02, 0x51, 0x7D, 0x22, 0xD8, 0x0A, 0x6E, 0x9A, 0x5B, 0x77, 0xDF,
	0xF0, 0xFA, 0x41, 0xEC, 0x39, 0xDC, 0x75, 0xCA, 0x68, 0x07, 0x0C, 0x1F,
	0xEA
};

static const unsigned char TA4_DN[] = {
	0x30, 0x5A, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x49, 0x45, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x13, 0x09, 0x42, 0x61, 0x6C, 0x74, 0x69, 0x6D, 0x6F, 0x72, 0x65, 0x31,
	0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x0A, 0x43, 0x79,
	0x62, 0x65, 0x72, 0x54, 0x72, 0x75, 0x73, 0x74, 0x31, 0x22, 0x30, 0x20,
	0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x19, 0x42, 0x61, 0x6C, 0x74, 0x69,
	0x6D, 0x6F, 0x72, 0x65, 0x20, 0x43, 0x79, 0x62, 0x65, 0x72, 0x54, 0x72,
	0x75, 0x73, 0x74, 0x20, 0x52, 0x6F, 0x6F, 0x74
};

static const unsigned char TA4_RSA_N[] = {
	0xA3, 0x04, 0xBB, 0x22, 0xAB, 0x98, 0x3D, 0x57, 0xE8, 0x26, 0x72, 0x9A,
	0xB5, 0x79, 0xD4, 0x29, 0xE2, 0xE1, 0xE8, 0x95, 0x80, 0xB1, 0xB0, 0xE3,
	0x5B, 0x8E, 0x2B, 0x29, 0x9A, 0x64, 0xDF, 0xA1, 0x5D, 0xED, 0xB0, 0x09,
	0x05, 0x6D, 0xDB, 0x28, 0x2E, 0xCE, 0x62, 0xA2, 0x62, 0xFE, 0xB4, 0x88,
	0xDA, 0x12, 0xEB, 0x38, 0xEB, 0x21, 0x9D, 0xC0, 0x41, 0x2B, 0x01, 0x52,
	0x7B, 0x88, 0x77, 0xD3, 0x1C, 0x8F, 0xC7, 0xBA, 0xB9, 0x88, 0xB5, 0x6A,
	0x09, 0xE7, 0x73, 0xE8, 0x11, 0x40, 0xA7, 0xD1, 0xCC, 0xCA, 0x62, 0x8D,
	0x2D, 0xE5, 0x8F, 0x0B, 0xA6, 0x50, 0xD2, 0xA8, 0x50, 0xC3, 0x28, 0xEA,
	0xF5, 0xAB, 0x25, 0x87, 0x8A, 0x9A, 0x96, 0x1C, 0xA9, 0x67, 0xB8, 0x3F,
	0x0C, 0xD5, 0xF7, 0xF9, 0x52, 0x13, 0x2F, 0xC2, 0x1B, 0xD5, 0x70, 0x70,
	0xF0, 0x8F, 0xC0, 0x12, 0xCA, 0x06, 0xCB, 0x9A, 0xE1, 0xD9, 0xCA, 0x33,
	0x7A, 0x77, 0xD6, 0xF8, 0xEC, 0xB9, 0xF1, 0x68, 0x44, 0x42, 0x48, 0x13,
	0xD2, 0xC0, 0xC2, 0xA4, 0xAE, 0x5E, 0x60, 0xFE, 0xB6, 0xA6, 0x05, 0xFC,
	0xB4, 0xDD, 0x07, 0x59, 0x02, 0xD4, 0x59, 0x18, 0x98, 0x63, 0xF5, 0xA5,
	0x63, 0xE0, 0x90, 0x0C, 0x7D, 0x5D, 0xB2, 0x06, 0x7A, 0xF3, 0x85, 0xEA,
	0xEB, 0xD4, 0x03, 0xAE, 0x5E, 0x84, 0x3E, 0x5F, 0xFF, 0x15, 0xED, 0x69,
	0xBC, 0xF9, 0x39, 0x36, 0x72, 0x75, 0xCF, 0x77, 0x52, 0x4D, 0xF3, 0xC9,
	0x90, 0x2C, 0xB9, 0x3D, 0xE5, 0xC9, 0x23, 0x53, 0x3F, 0x1F, 0x24, 0x98,
	0x21, 0x5C, 0x07, 0x99, 0x29, 0xBD, 0xC6, 0x3A, 0xEC, 0xE7, 0x6E, 0x86,
	0x3A, 0x6B, 0x97, 0x74, 0x63, 0x33, 0xBD, 0x68, 0x18, 0x31, 0xF0, 0x78,
	0x8D, 0x76, 0xBF, 0xFC, 0x9E, 0x8E, 0x5D, 0x2A, 0x86, 0xA7, 0x4D, 0x90,
	0xDC, 0x27, 0x1A, 0x39
};

static const unsigned char TA4_RSA_E[] = {
	0x01, 0x00, 0x01
};

static const unsigned char TA5_DN[] = {
	0x30, 0x81, 0x88, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
	0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04,
	0x08, 0x13, 0x0A, 0x4E, 0x65, 0x77, 0x20, 0x4A, 0x65, 0x72, 0x73, 0x65,
	0x79, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x0B,
	0x4A, 0x65, 0x72, 0x73, 0x65, 0x79, 0x20, 0x43, 0x69, 0x74, 0x79, 0x31,
	0x1E, 0x30, 0x1C, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x15, 0x54, 0x68,
	0x65, 0x20, 0x55, 0x53, 0x45, 0x52, 0x54, 0x52, 0x55, 0x53, 0x54, 0x20,
	0x4E, 0x65, 0x74, 0x77, 0x6F, 0x72, 0x6B, 0x31, 0x2E, 0x30, 0x2C, 0x06,
	0x03, 0x55, 0x04, 0x03, 0x13, 0x25, 0x55, 0x53, 0x45, 0x52, 0x54, 0x72,
	0x75, 0x73, 0x74, 0x20, 0x52, 0x53, 0x41, 0x20, 0x43, 0x65, 0x72, 0x74,
	0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x41, 0x75,
	0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79
};

static const unsigned char TA5_RSA_N[] = {
	0x80, 0x12, 0x65, 0x17, 0x36, 0x0E, 0xC3, 0xDB, 0x08, 0xB3, 0xD0, 0xAC,
	0x57, 0x0D, 0x76, 0xED, 0xCD, 0x27, 0xD3, 0x4C, 0xAD, 0x50, 0x83, 0x61,
	0xE2, 0xAA, 0x20, 0x4D, 0x09, 0x2D, 0x64, 0x09, 0xDC, 0xCE, 0x89, 0x9F,
	0xCC, 0x3D, 0xA9, 0xEC, 0xF6, 0xCF, 0xC1, 0xDC, 0xF1, 0xD3, 0xB1, 0xD6,
	0x7B, 0x37, 0x28, 0x11, 0x2B, 0x47, 0xDA, 0x39, 0xC6, 0xBC, 0x3A, 0x19,
	0xB4, 0x5F, 0xA6, 0xBD, 0x7D, 0x9D, 0xA3, 0x63, 0x42, 0xB6, 0x76, 0xF2,
	0xA9, 0x3B, 0x2B, 0x91, 0xF8, 0xE2, 0x6F, 0xD0, 0xEC, 0x16, 0x20, 0x90,
	0x09, 0x3E, 0xE2, 0xE8, 0x74, 0xC9, 0x18, 0xB4, 0x91, 0xD4, 0x62, 0x64,
	0xDB, 0x7F, 0xA3, 0x06, 0xF1, 0x88, 0x18, 0x6A, 0x90, 0x22, 0x3C, 0xBC,
	0xFE, 0x13, 0xF0, 0x87, 0x14, 0x7B, 0xF6, 0xE4, 0x1F, 0x8E, 0xD4, 0xE4,
	0x51, 0xC6, 0x11, 0x67, 0x46, 0x08, 0x51, 0xCB, 0x86, 0x14, 0x54, 0x3F,
	0xBC, 0x33, 0xFE, 0x7E, 0x6C, 0x9C, 0xFF, 0x16, 0x9D, 0x18, 0xBD, 0x51,
	0x8E, 0x35, 0xA6, 0xA7, 0x66, 0xC8, 0x72, 0x67, 0xDB, 0x21, 0x66, 0xB1,
	0xD4, 0x9B, 0x78, 0x03, 0xC0, 0x50, 0x3A, 0xE8, 0xCC, 0xF0, 0xDC, 0xBC,
	0x9E, 0x4C, 0xFE, 0xAF, 0x05, 0x96, 0x35, 0x1F, 0x57, 0x5A, 0xB7, 0xFF,
	0xCE, 0xF9, 0x3D, 0xB7, 0x2C, 0xB6, 0xF6, 0x54, 0xDD, 0xC8, 0xE7, 0x12,
	0x3A, 0x4D, 0xAE, 0x4C, 0x8A, 0xB7, 0x5C, 0x9A, 0xB4, 0xB7, 0x20, 0x3D,
	0xCA, 0x7F, 0x22, 0x34, 0xAE, 0x7E, 0x3B, 0x68, 0x66, 0x01, 0x44, 0xE7,
	0x01, 0x4E, 0x46, 0x53, 0x9B, 0x33, 0x60, 0xF7, 0x94, 0xBE, 0x53, 0x37,
	0x90, 0x73, 0x43, 0xF3, 0x32, 0xC3, 0x53, 0xEF, 0xDB, 0xAA, 0xFE, 0x74,
	0x4E, 0x69, 0xC7, 0x6B, 0x8C, 0x60, 0x93, 0xDE, 0xC4, 0xC7, 0x0C, 0xDF,
	0xE1, 0x32, 0xAE, 0xCC, 0x93, 0x3B, 0x51, 0x78, 0x95, 0x67, 0x8B, 0xEE,
	0x3D, 0x56, 0xFE, 0x0C, 0xD0, 0x69, 0x0F, 0x1B, 0x0F, 0xF3, 0x25, 0x26,
	0x6B, 0x33, 0x6D, 0xF7, 0x6E, 0x47, 0xFA, 0x73, 0x43, 0xE5, 0x7E, 0x0E,
	0xA5, 0x66, 0xB1, 0x29, 0x7C, 0x32, 0x84, 0x63, 0x55, 0x89, 0xC4, 0x0D,
	0xC1, 0x93, 0x54, 0x30, 0x19, 0x13, 0xAC, 0xD3, 0x7D, 0x37, 0xA7, 0xEB,
	0x5D, 0x3A, 0x6C, 0x35, 0x5C, 0xDB, 0x41, 0xD7, 0x12, 0xDA, 0xA9, 0x49,
	0x0B, 0xDF, 0xD8, 0x80, 0x8A, 0x09, 0x93, 0x62, 0x8E, 0xB5, 0x66, 0xCF,
	0x25, 0x88, 0xCD, 0x84, 0xB8, 0xB1, 0x3F, 0xA4, 0x39, 0x0F, 0xD9, 0x02,
	0x9E, 0xEB, 0x12, 0x4C, 0x95, 0x7C, 0xF3, 0x6B, 0x05, 0xA9, 0x5E, 0x16,
	0x83, 0xCC, 0xB8, 0x67, 0xE2, 0xE8, 0x13, 0x9D, 0xCC, 0x5B, 0x82, 0xD3,
	0x4C, 0xB3, 0xED, 0x5B, 0xFF, 0xDE, 0xE5, 0x73, 0xAC, 0x23, 0x3B, 0x2D,
	0x00, 0xBF, 0x35, 0x55, 0x74, 0x09, 0x49, 0xD8, 0x49, 0x58, 0x1A, 0x7F,
	0x92, 0x36, 0xE6, 0x51, 0x92, 0x0E, 0xF3, 0x26, 0x7D, 0x1C, 0x4D, 0x17,
	0xBC, 0xC9, 0xEC, 0x43, 0x26, 0xD0, 0xBF, 0x41, 0x5F, 0x40, 0xA9, 0x44,
	0x44, 0xF4, 0x99, 0xE7, 0x57, 0x87, 0x9E, 0x50, 0x1F, 0x57, 0x54, 0xA8,
	0x3E, 0xFD, 0x74, 0x63, 0x2F, 0xB1, 0x50, 0x65, 0x09, 0xE6, 0x58, 0x42,
	0x2E, 0x43, 0x1A, 0x4C, 0xB4, 0xF0, 0x25, 0x47, 0x59, 0xFA, 0x04, 0x1E,
	0x93, 0xD4, 0x26, 0x46, 0x4A, 0x50, 0x81, 0xB2, 0xDE, 0xBE, 0x78, 0xB7,
	0xFC, 0x67, 0x15, 0xE1, 0xC9, 0x57, 0x84, 0x1E, 0x0F, 0x63, 0xD6, 0xE9,
	0x62, 0xBA, 0xD6, 0x5F, 0x55, 0x2E, 0xEA, 0x5C, 0xC6, 0x28, 0x08, 0x04,
	0x25, 0x39, 0xB8, 0x0E, 0x2B, 0xA9, 0xF2, 0x4C, 0x97, 0x1C, 0x07, 0x3F,
	0x0D, 0x52, 0xF5, 0xED, 0xEF, 0x2F, 0x82, 0x0F
};

static const unsigned char TA5_RSA_E[] = {
	0x01, 0x00, 0x01
};

static const br_x509_trust_anchor TAs[6] = {
	{
		{ (unsigned char *)TA0_DN, sizeof TA0_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_RSA,
			{ .rsa = {
				(unsigned char *)TA0_RSA_N, sizeof TA0_RSA_N,
				(unsigned char *)TA0_RSA_E, sizeof TA0_RSA_E,
			} }
		}
	},
	{
		{ (unsigned char *)TA1_DN, sizeof TA1_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_RSA,
			{ .rsa = {
				(unsigned char *)TA1_RSA_N, sizeof TA1_RSA_N,
				(unsigned char *)TA1_RSA_E, sizeof TA1_RSA_E,
			} }
		}
	},
	{
		{ (unsigned char *)TA2_DN, sizeof TA2_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_RSA,
			{ .rsa = {
				(unsigned char *)TA2_RSA_N, sizeof TA2_RSA_N,
				(unsigned char *)TA2_RSA_E, sizeof TA2_RSA_E,
			} }
		}
	},
	{
		{ (unsigned char *)TA3_DN, sizeof TA3_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_EC,
			{ .ec = {
				BR_EC_secp384r1,
				(unsigned char *)TA3_EC_Q, sizeof TA3_EC_Q,
			} }
		}
	},
	{
		{ (unsigned char *)TA4_DN, sizeof TA4_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_RSA,
			{ .rsa = {
				(unsigned char *)TA4_RSA_N, sizeof TA4_RSA_N,
				(unsigned char *)TA4_RSA_E, sizeof TA4_RSA_E,
			} }
		}
	},
	{
		{ (unsigned char *)TA5_DN, sizeof TA5_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_RSA,
			{ .rsa = {
				(unsigned char *)TA5_RSA_N, sizeof TA5_RSA_N,
				(unsigned char *)TA5_RSA_E, sizeof TA5_RSA_E,
			} }
		}
	}
};

#define TAs_NUM 6