#include "Blips.h"

Blip_S* blip_Create(int b, char* name, Vector3_t vec)
{
	Blip_S* ret = (Blip_S*)malloc(sizeof(Blip_S));
	if (ret == NULL) return NULL;

	ret->baseBlipHandle = b;

	strncpy(ret->name, name, 62);
	ret->name[63] = '\0';

	ret->vec = vec;
	return ret;
}

void blip_Free(Blip_S* ptr)
{
	free(ptr);
}
#define NATIVE_H
#ifdef NATIVE_H
#include "..\ScriptHooKV/natives.h"
void blip_Draw(Blip_S* ptr)
{
	if (!HUD::DOES_BLIP_EXIST(ptr->baseBlipHandle)) {
		HUD::ADD_BLIP_FOR_COORD(ptr->vec.x, ptr->vec.y, ptr->vec.z);
		HUD::SET_BLIP_SPRITE(ptr->baseBlipHandle, 64);
		return;
	}
	return;
}
#endif //NATIVE_H
#undef NATIVE_H
