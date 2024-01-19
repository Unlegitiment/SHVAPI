#pragma once
typedef struct rgba_t{
	float r, g, b, a;
}RGBA_t;
typedef enum {
	VECTOR_3_X = 0,
	VECTOR_3_Y = 1,
	VECTOR_3_Z = 2,
	VECTOR_3_PADDINGX = 0x45,
	VECTOR_3_PADDINGY = 0x46,
	VECTOR_3_PADDINGZ = 0x47
}Vector3Type;
typedef struct {
	float x;
	unsigned long long _paddingX_;
	float y;
	unsigned long long _paddingY_;
	float z;
	unsigned long long _paddingZ_;
}Vector3_t;
typedef struct {
	float x;
	unsigned long long _paddingX_;
	float y; 
	unsigned long long _paddingY_;
}Vector2_t;
typedef unsigned char BOOL_t;
typedef unsigned long long DWORD_t;
#define TRUE_ 1
#define FALSE_ 0
#define MAX_BUFF 64
typedef struct {
	char txdDict[MAX_BUFF];
	char txdName[MAX_BUFF];
	bool isDictRequested;
}TXD;

typedef struct noti_t{
	TXD* txd;
	int handle;
	bool isHeadshot : 1;
	char TITLE[MAX_BUFF];
	char HEADER[MAX_BUFF];
	char TEXT[MAX_BUFF];
}Notification;
#undef MAX_BUFF

