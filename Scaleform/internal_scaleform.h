/*
* Reading this file isn't meant to make sense. 
* This is meant to confuse you because you are not meant to be using these functions unless you are extending the data base of Scaleforms in which case tis permitted.
* I've been nice by using enums and various other data types however I could just use integers and really confuse you.
* Fail Codes are documented in the first enum within the NATIVE_H define.
*/
#pragma once



typedef int SCLHANDLE;
#define MAX_BUFF 128

typedef struct scaleform_t{
	SCLHANDLE handle;
	char name[MAX_BUFF];
}Scaleform;

#define SCL_FAILED -0x00100010

#define NATIVE_H
#ifdef NATIVE_H
#include "..\ScriptHookV\natives.h"
using namespace GRAPHICS;
/*Hud Movie is Ignored Because it requires different implementation.*/

typedef enum eRequestType_t {
	TYPE_REQUEST_NORMAL = 0xff,
	TYPE_REQUEST_INSTANCE = 0xd2,
	TYPE_REQUEST_HUD_MOVIE = 0xd1,
	TYPE_REQUEST_IGNORE_WIDESCREEN = 0xc8,
	TYPE_REQUEST_WHILE_PAUSED = 0xc7,
}__eRequestType__;
/*
* Base for Requesting Not meant to be used by public access.
* @param name - The name of the Scaleform Used.
* @param type - The type of Request Issued.
* @return Handle for Scaleform. 
*/
inline int __SCL_REQUEST__(char* name, __eRequestType__ type) {
	int handle = NULL;
	switch (type) {
	case TYPE_REQUEST_NORMAL:
		handle = REQUEST_SCALEFORM_MOVIE(name);
		break;
	case TYPE_REQUEST_INSTANCE:
		handle = REQUEST_SCALEFORM_MOVIE_INSTANCE(name);
		break;
	case TYPE_REQUEST_IGNORE_WIDESCREEN:
		handle = REQUEST_SCALEFORM_MOVIE_WITH_IGNORE_SUPER_WIDESCREEN(name);
		break;
	case TYPE_REQUEST_WHILE_PAUSED:
		handle = REQUEST_SCALEFORM_MOVIE_SKIP_RENDER_WHILE_PAUSED(name);
		break;
	default:
		return NULL-1; // IF ALL OTHER FAIL.
	}
	/*Confiscate Thread Briefly.*/
	while (!HAS_SCALEFORM_MOVIE_LOADED(handle)) {
		WAIT(0);
	}
	return handle;
}
#endif // NATIVE_H
#undef NATIVE_H

inline void __SCL_INIT__(Scaleform* ptr, char* name, int handle = NULL) {
	
	size_t rawLen = strnlen_s(name, MAX_BUFF);
	
	if (name == NULL) name = "";
	if (handle == NULL) handle = 0x00000000000000000;
	
	strncpy(ptr->name, name, MAX_BUFF - 2);
	
	ptr->name[MAX_BUFF - 1] = '\0';

	ptr->handle = handle;

	return;
}



#undef MAX_BUFF


