#pragma once
#include "..\utils.h"
typedef int SCLHANDLE;
#define MAX_BUFF 128
typedef struct scaleform_t{
	SCLHANDLE handle;
	char name[MAX_BUFF];
}Scaleform;
#undef MAX_BUFF

