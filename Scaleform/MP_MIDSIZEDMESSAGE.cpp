#include "..\Scaleform.h"
#define MAX_BUFF 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[MAX_BUFF];
}MidSizedMessage;
MidSizedHandle* mz_Create(char* msg) {
	if (msg == NULL) msg = "";
	MidSizedMessage* z = (MidSizedMessage*)malloc(sizeof(MidSizedMessage));
	if (z == NULL) return NULL;
	strncpy(z->name, msg, MAX_BUFF-2);
	z->name[MAX_BUFF-1] = '\0';
	return (MidSizedHandle*)z;
}
void mz_Print(MidSizedHandle* scl) {

}