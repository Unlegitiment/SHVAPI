#pragma once
#include "..\Utils.h"

typedef struct {
	int baseBlipHandle;
	char name[64];
	Vector3_t vec;
}Blip_S;

Blip_S* blip_Create(int b, char* name, Vector3_t vec);
void blip_Free(Blip_S* ptr);
void blip_Draw(Blip_S* ptr);
