#include "internal_scaleform.h"
#include "..\scaleform.h"
#define SCL_LIMIT 3
#define wallid_LIMIT 16
#define MODE_LIMIT 64
struct INTRO_T_I {
	BOOL_t chalTextLabel, tarTypeTextLabel, modeLabelIsStringLiteral;
	char missionName[MODE_LIMIT];
	char missionType[MODE_LIMIT];
	char modeType[MODE_LIMIT];
};
struct OUTRO_T_I {
	char littlePass[MODE_LIMIT / 4];
	char bigPass[MODE_LIMIT / 4];
	char playerDied[MODE_LIMIT / 2];
	int startMoney, endMoney;
	int startRank, endRank; 
};
typedef struct MP_CELEB_t{
	Scaleform scl[SCL_LIMIT];
	char wallID[wallid_LIMIT];
	CelebMode cT;
	CelebrationTypes type;
	int startTime, endTime, duration, opacity, delay;
	union {
		struct INTRO_T_I intro;
		struct OUTRO_T_I outro;
	};
}MP_CELEB;
/*
* @brief Draws the MP_CELEBRATION Scaleform.
* @brief Also frees the memory occupied by MP_CELEB
* @param CelebHandle* celeb - The current instance wanted to be drawn
* @param CelebMode cT - The current mode you'd like for the celeb to draw. Represents multiple modes. (You have to make sure you are using the correct function call)
*/
CelebHandle* celeb_Intro_Create(
								char missionName[MODE_LIMIT],
								char missionType[MODE_LIMIT],
								char modeType[MODE_LIMIT],
								CelebrationTypes type,
								BOOL_t chalTextLabel, 
								BOOL_t tarTypeTextLabel, 
								BOOL_t modeLabelIsStringLiteral,
								int opacity
								) {
	if (missionName == NULL) missionName = "";
	if (missionType == NULL) missionType = "";
	if (modeType == NULL) modeType = "";

	MP_CELEB* celeb = (MP_CELEB*)malloc(sizeof(MP_CELEB));
	if (celeb == NULL) { return NULL; }
	celeb->cT = CM_INTRO;
	char* scaleform_n[3]{ "MP_CELEBRATION", "MP_CELEBRATION_FG", "MP_CELEBRATION_BG" }; 
	strncpy(celeb->wallID, "intro", sizeof(celeb->wallID));
	strncpy(celeb->intro.missionName, missionName, sizeof(celeb->intro.missionName));
	strncpy(celeb->intro.missionType, missionType, sizeof(celeb->intro.missionType));
	strncpy(celeb->intro.modeType, modeType, sizeof(celeb->intro.modeType));
	for (int i = 0; i < 3; i++) {
		strncpy(celeb->scl[i].name, scaleform_n[i], sizeof(celeb->scl[i].name));
	}
	celeb->type = type;
	celeb->intro.modeLabelIsStringLiteral = modeLabelIsStringLiteral;
	celeb->intro.chalTextLabel = chalTextLabel;
	celeb->intro.tarTypeTextLabel = tarTypeTextLabel;
	celeb->opacity = opacity;

	return (CelebHandle*)celeb;
}
void celeb_Intro_Destroy(CelebHandle* handle) {
	free(handle);
}
#define NATIVE_H
#ifdef NATIVE_H
#include "E:\ScriptHookV\inc\natives.h"
void celeb_Draw(CelebHandle* celeb) {
	if (celeb == NULL) { return; }
	MP_CELEB* c = (MP_CELEB*)celeb;

	int celebz = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION");
	int celeb_fg = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_FG");
	int celeb_bg = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_BG");
	int x[3] = {  celeb_bg, celeb_fg, celebz };

	for (int i = 0; i < 3; i++) {
		c->scl[i].handle = x[i];

		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(c->scl[i].handle, "CLEANUP");
		GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(c->wallID);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();

		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(c->scl[i].handle)) WAIT(0);
		using namespace GRAPHICS;

		BEGIN_SCALEFORM_MOVIE_METHOD(c->scl[i].handle, "CREATE_STAT_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(c->wallID);
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING("HUD_COLOUR_BLACK");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(100); // magic val check
		END_SCALEFORM_MOVIE_METHOD();

		BEGIN_SCALEFORM_MOVIE_METHOD(c->scl[i].handle, "SET_PAUSE_DURATION");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(3);
		END_SCALEFORM_MOVIE_METHOD();

		BEGIN_SCALEFORM_MOVIE_METHOD(c->scl[i].handle, "ADD_INTRO_TO_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(c->wallID); 
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(c->intro.missionType); //jType
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(c->intro.missionName); // name
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(c->intro.chalTextLabel); // challtextlab
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(c->intro.modeType); // chaltextstr
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(c->intro.tarTypeTextLabel); // expand
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING("S"); // idk
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(0); // not sure
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING("S"); //wtv
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(c->intro.modeLabelIsStringLiteral); // MUST BE TRUE
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING("HUD_COLOUR_WHITE");//txt-color
		END_SCALEFORM_MOVIE_METHOD();

		BEGIN_SCALEFORM_MOVIE_METHOD(c->scl[i].handle, "ADD_BACKGROUND_TO_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(c->wallID);
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(c->opacity);
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(c->type);
		END_SCALEFORM_MOVIE_METHOD();

		BEGIN_SCALEFORM_MOVIE_METHOD(c->scl[i].handle, "SHOW_STAT_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(c->wallID);
		END_SCALEFORM_MOVIE_METHOD();
	}
	BOOL_t running = FALSE_;
	c->startTime = MISC::GET_GAME_TIMER();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(c->scl[2].handle, "GET_TOTAL_WALL_DURATION");
	int retHandle = GRAPHICS::END_SCALEFORM_MOVIE_METHOD_RETURN_VALUE();
	while (!GRAPHICS::IS_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_READY(retHandle)) WAIT(0);
	c->duration = GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT(retHandle);
	c->endTime = (c->startTime + c->duration);
	while (MISC::GET_GAME_TIMER() < c->endTime - 7000) {
		WAIT(0);
		//utils_DrawMissionText((char*)uTil_int_to_string_conversion(iPtr->endTime));
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(c->scl[0].handle, c->scl[1].handle, 255, 255, 255, 100);
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(c->scl[2].handle, 255, 255, 255, 255, 0);
		HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
		PAD::DISABLE_ALL_CONTROL_ACTIONS(2);
	}
	PAD::ENABLE_ALL_CONTROL_ACTIONS(2);
	for (int i = 0; i < 3; i++) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&x[i]);
	}
	celeb_Intro_Destroy(celeb);
	return;
}
#endif
#undef NATIVE_H
