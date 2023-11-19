#define _CRT_SECURE_NO_WARNINGS
#include "../ScriptHookV/nativeCaller.h"
#undef TRUE
#undef FALSE
#include "..\utils.h"
TXD* txd_Create(char* dictionary, char* name) {
	if (dictionary == NULL || name == NULL) {
		dictionary = "";
		name = "";
	}
	TXD* txd = (TXD*)malloc(sizeof(TXD));
	if (txd == NULL) return NULL;
	strncpy(txd->txdDict, dictionary, sizeof(txd->txdDict));
	strncpy(txd->txdName, name, sizeof(txd->txdName));
	txd->txdDict[63] = '\0';
	txd->txdName[63] = '\0';
	txd->isDictRequested = FALSE_;
	return txd;
}
void txd_Destroy(TXD* tPtr) {
	free(tPtr);
	return;
}
BOOL_t txd_Comp(TXD* one, TXD* two) {
	if (strcmp(one->txdDict, two->txdDict) == 0 &&
		strcmp(one->txdName, two->txdName) == 0 &&
		one->isDictRequested == two->isDictRequested) {
		return TRUE_;
	}
	else return FALSE_;
}
void txd_Init(TXD* tPtr) {
	tPtr->isDictRequested = TRUE_;
	if (tPtr->txdDict == NULL || tPtr->txdName == NULL) {
		tPtr->isDictRequested = FALSE_;
		return;
	}
	invoke<DWORD>(0xDFA2EF8E04127DD5, tPtr->txdDict, tPtr->isDictRequested);
	return;
}
BOOL_t txd_isRequested(const TXD* tPtr) {
	return tPtr->isDictRequested;
}
#define NATIVE_H
#ifdef NATIVE_H
#include "../ScriptHookV/natives.h"
TXD* GetHeadShot(Entity e)
{
	int handle = PED::REGISTER_PEDHEADSHOT(e);
	while (!PED::IS_PEDHEADSHOT_READY(handle) || !PED::IS_PEDHEADSHOT_VALID(handle)) {
		WAIT(0);
	}
	const char* txdz = PED::GET_PEDHEADSHOT_TXD_STRING(handle);
	TXD* txd = txd_Create((char*)txdz, (char*)txdz);
	return txd;
}
#endif // NATIVE_H
#undef NATIVE_H
#undef MAX_BUFF
#undef _CRT_SECURE_NO_WARNINGS