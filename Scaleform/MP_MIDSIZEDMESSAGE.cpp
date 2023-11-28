
#include "..\Scaleform.h"
#include "internal_scaleform.h"
#define MAX_BUFF 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	mz_Type_Base = 0,
	mz_Type_Bridge = 1
}mz_Type;
typedef struct {
	Scaleform scl;
	char bigTxt[MAX_BUFF];
	char msgTxt[MAX_BUFF];
	HudColour colID;
	mz_Type mz_TYPE;
	BOOL_t useCondensed;
	BOOL_t useDarkerShards;
	struct BridgeAndKnife_t {
		int totalTodo;
		int totalComplete;
		char infoText[MAX_BUFF];
	}BridgeAndKnife;
}MidSizedMessage;

MidSizedHandle* mz_Create(char* bigTxt, char* descTxt, HudColour colour, BOOL_t useCondensed, BOOL_t useDarkerColour) {
	if (bigTxt == NULL) bigTxt = "";

	MidSizedMessage* z = (MidSizedMessage*)malloc(sizeof(MidSizedMessage));
	if (z == NULL) return NULL;

	strncpy(z->bigTxt, bigTxt, MAX_BUFF - 2);
	strncpy(z->msgTxt, descTxt, MAX_BUFF - 2);

	z->bigTxt[MAX_BUFF - 1]			= '\0';
	z->msgTxt[MAX_BUFF - 1]			= '\0';
	
	z->mz_TYPE						= mz_Type_Base;
	z->colID						= colour;
	
	z->useCondensed					= useCondensed;
	z->useDarkerShards				= useDarkerColour;

	z->BridgeAndKnife.totalComplete = 0;
	z->BridgeAndKnife.totalTodo		= 0;
	
	__SCL_INIT__(&z->scl, "MIDSIZED_MESSAGE", __SCL_REQUEST__("MIDSIZED_MESSAGE", TYPE_REQUEST_NORMAL));

	return (MidSizedHandle*)z;
}
void mz_Destroy(MidSizedHandle* handle) {
	if (handle == NULL) return;
	MidSizedMessage* msg = (MidSizedMessage*)handle;
	free(msg);
	return;
}
void mz_ApplyBridgeAndKnife(MidSizedHandle* handle, char* info, int totalTodo, int totalComplete) {
	if (handle == NULL) return;
	MidSizedMessage* ptr							= (MidSizedMessage*)handle;
	ptr->BridgeAndKnife.totalTodo					= totalTodo;
	ptr->BridgeAndKnife.totalComplete				= totalComplete;
	ptr->mz_TYPE									= mz_Type_Bridge;
	strncpy(ptr->BridgeAndKnife.infoText, info, MAX_BUFF-2);
	ptr->BridgeAndKnife.infoText[MAX_BUFF - 1]		= '\0';
	return;
}
void __mz_SHOW_MIDSIZED_MESSAGE_(int sclHandle, char* title, char* desc) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(sclHandle, "SHOW_MIDSIZED_MESSAGE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(title);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(desc);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	return;
}
/*
*	MIDSIZED_MESSAGE()
	INITIALISE(mc)
	SHOW_MIDSIZED_MESSAGE(title, description)
	SHOW_BRIDGES_KNIVES_PROGRESS(title, totalToDo, message, info, completed)
	SHOW_COND_SHARD_MESSAGE(bigText, msgText, colID, useDarkerShard)
	SHOW_SHARD_MIDSIZED_MESSAGE(bigText, msgText, colID, useDarkerShard, useCondensedShard)
	SHARD_SET_TEXT(bigText, msgText, useCondensedShard)
	SHARD_ANIM_OUT(colID, animTime)
	parseForGamerTagTitleFonts(tf, str, stdPtSize)
	getFontSizeFit(gamerName, fontSize, widthToFit)
*/
void __mz_SHOW_BRIDGES_KNIVES_PROGRESS(int sclHandle, char* title, int totalToDo, char* msg, char* info, int completed) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(sclHandle, "SHOW_BRIDGES_KNIVES_PROGRESS");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(title);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(totalToDo);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(msg);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(info);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(completed);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void __mz_SHOW_COND_SHARD_MESSAGE(int sclHandle, char* bigTxt, char* msgTxt, int colID, BOOL_t useDarkerShard, BOOL_t useCondensedShard) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(sclHandle, "SHOW_COND_SHARD_MESSAGE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(bigTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(msgTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(colID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(useDarkerShard);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(useCondensedShard);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void __mz_SHARD_SET_TEXT(int sclHandle, char* bigTxt, char* msgTxt, BOOL_t useCondensed) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(sclHandle, "SHARD_SET_TEXT");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(bigTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(msgTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(useCondensed);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void __mz_SHARD_ANIM_OUT(int sclHandle, int colID, int animTime) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(sclHandle, "SHARD_ANIM_OUT");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(colID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(animTime);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void mz_Tick(MidSizedHandle* scl) {
	if (scl == NULL) return;
	MidSizedMessage* ptr = (MidSizedMessage*)scl;
	

	switch (ptr->mz_TYPE) {
	case mz_Type_Base:
		__mz_SHOW_COND_SHARD_MESSAGE(ptr->scl.handle, ptr->bigTxt, ptr->msgTxt, ptr->colID, ptr->useDarkerShards, ptr->useCondensed);
		GRAPHICS::DRAW_SCALEFORM_MOVIE(ptr->scl.handle, 0.5, 0.5, 1, 1, 255, 255, 255, 255, 0);
		break;
	case mz_Type_Bridge:
		__mz_SHOW_BRIDGES_KNIVES_PROGRESS(ptr->scl.handle, ptr->bigTxt, ptr->BridgeAndKnife.totalTodo, ptr->msgTxt, ptr->BridgeAndKnife.infoText, ptr->BridgeAndKnife.totalComplete);
		GRAPHICS::DRAW_SCALEFORM_MOVIE(ptr->scl.handle, 0.5, 0.5, 1, 1, 255, 255, 255, 255, 0);
		break;
	default:
		__mz_SHOW_MIDSIZED_MESSAGE_(ptr->scl.handle, ptr->bigTxt, ptr->msgTxt);
		GRAPHICS::DRAW_SCALEFORM_MOVIE(ptr->scl.handle, 0.5, 0.5, 1, 1, 255, 255, 255, 255, 0);
		break;
	}

}