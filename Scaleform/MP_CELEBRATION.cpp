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

CelebHandle* celeb_Outro_Create(
	char firstLine[MODE_LIMIT / 4],
	char largeText[MODE_LIMIT / 4],
	char deathText[MODE_LIMIT / 2],
	CelebrationTypes type,
	int opacity,
	int startMoney,
	int endMoney,
	int startRank,
	int endRank
	) {
	if (firstLine == NULL) firstLine = "NULL";
	if (largeText == NULL) largeText = "NULL";
	if (deathText == NULL) deathText = "NULL";

	MP_CELEB* celeb = (MP_CELEB*)malloc(sizeof(MP_CELEB));
	if (celeb == NULL) return NULL;
	//Pre-init vals.
	strncpy(celeb->scl[0].name, "MP_CELEBRATION\0", strnlen("MP_CELEBRATION\0", 64));
	strncpy(celeb->scl[1].name, "MP_CELEBRATION_BG\0", strnlen("MP_CELEBRATION_BG\0", 64));
	strncpy(celeb->scl[2].name, "MP_CELEBRATION_FG\0", strnlen("MP_CELEBRATION_FG\0", 64));
	strncpy(celeb->wallID, "OUTRO", wallid_LIMIT);

	strncpy(celeb->outro.littlePass, firstLine, 16);
	strncpy(celeb->outro.bigPass, largeText, 16);
	strncpy(celeb->outro.playerDied, deathText, 32);
	celeb->opacity = opacity;
	celeb->cT = CM_OUTRO;
	celeb->type = type;
	celeb->outro.startRank = startRank;
	celeb->outro.endRank = endRank;
	celeb->outro.startMoney = startMoney;
	celeb->outro.endMoney = endMoney;

	return (CelebHandle*)celeb;
}

void celeb_Destroy(CelebHandle* handle) {
	free(handle);
}

int getIndexOfScl(CelebHandle* handle) {
	MP_CELEB* celeb = (MP_CELEB*)handle;
	for (int i = 0; i < 3; i++) {
		if (strcmp(celeb->scl[i].name, "MP_CELEBRATION") == 0) return i;
	}
}
int getIndexOfSclBG(CelebHandle* handle) {
	MP_CELEB* celeb = (MP_CELEB*)handle;
	for (int i = 0; i < 3; i++) {
		if (strcmp(celeb->scl[i].name, "MP_CELEBRATION_BG") == 0) return i;
	}
}
int getIndexOfSclFG(CelebHandle* handle) {
	MP_CELEB* celeb = (MP_CELEB*)handle;
	for (int i = 0; i < 3; i++) {
		if (strcmp(celeb->scl[i].name, "MP_CELEBRATION_FG") == 0) return i;
	}
}
/*
* @param int offset - Some scaleforms are too long for the program thus this is created to subtract from the base time.
* BOOL_t isOffsetPositive - By default set to FALSE_ because you basically never need more time for a scaleform however im not here to judge boo.
*/

#define NATIVE_H
#ifdef NATIVE_H
#include "../ScriptHookV/natives.h"
void displayOorI(CelebHandle* handle, int offset = 0, BOOL_t isOffsetPositive = FALSE_) {
	MP_CELEB* celeb = (MP_CELEB*)handle;
	int startTime = MISC::GET_GAME_TIMER();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(celeb->scl[getIndexOfScl(handle)].handle, "GET_TOTAL_WALL_DURATION");
	int retHandle = GRAPHICS::END_SCALEFORM_MOVIE_METHOD_RETURN_VALUE();
	while (!GRAPHICS::IS_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_READY(retHandle)) {
		WAIT(0);
	}
	int time = GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT(retHandle);
	int endTime = startTime + time;
	if (isOffsetPositive) {
		while (MISC::GET_GAME_TIMER() < endTime + offset) {
			GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(celeb->scl[getIndexOfSclBG(handle)].handle, celeb->scl[getIndexOfSclFG(handle)].handle, 255, 255, 255, 100);
			GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(celeb->scl[getIndexOfScl(handle)].handle, 255, 255, 255, 255, 0);
			HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
			//PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
			WAIT(0);
		}
	}
	else {

	}


}
void celeb_Draw(CelebHandle* celeb) {
	if (celeb == NULL) { return; }
	MP_CELEB* c = (MP_CELEB*)celeb;

	int celebz = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION");
	int celeb_fg = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_FG");
	int celeb_bg = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_BG");
	int x[3] = { celebz, celeb_fg, celeb_bg};

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
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(c->scl[2].handle, c->scl[1].handle, 255, 255, 255, 100);
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(c->scl[0].handle, 255, 255, 255, 255, 0);
		HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
		PAD::DISABLE_ALL_CONTROL_ACTIONS(2);
	}
	PAD::ENABLE_ALL_CONTROL_ACTIONS(2);
	for (int i = 0; i < 3; i++) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&x[i]);
	}
	celeb_Destroy(celeb);
	return;
}
void Outro_Draw(CelebHandle* cIns) {
	MP_CELEB* o = (MP_CELEB*)cIns;
	//CELEB -> BG->FG [0][1][2]
	for (int i = 0; i < 3; i++) {
		using namespace GRAPHICS;

		BEGIN_SCALEFORM_MOVIE_METHOD(o->scl[i].handle, "CLEANUP");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(o->wallID);
		END_SCALEFORM_MOVIE_METHOD();

		o->scl[i].handle = REQUEST_SCALEFORM_MOVIE(o->scl[i].name);
		while (!HAS_SCALEFORM_MOVIE_LOADED(o->scl[i].handle)) WAIT(0);

		BEGIN_SCALEFORM_MOVIE_METHOD(o->scl[i].handle, "CREATE_STAT_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(o->wallID);
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING("HUD_COLOUR_BLACK");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(o->opacity);
		END_SCALEFORM_MOVIE_METHOD();



		BEGIN_SCALEFORM_MOVIE_METHOD(o->scl[i].handle, "ADD_MISSION_RESULT_TO_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(o->wallID);
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(o->outro.littlePass); //textlabel
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(o->outro.bigPass); //passFail
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(o->outro.playerDied); // msgLabel
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMsgraw
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isPassFailRaw
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMissionTextRaw
		END_SCALEFORM_MOVIE_METHOD();


		BEGIN_SCALEFORM_MOVIE_METHOD(o->scl[i].handle, "ADD_BACKGROUND_TO_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(o->wallID);
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(70);
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT((float)-1);
		END_SCALEFORM_MOVIE_METHOD();

		BEGIN_SCALEFORM_MOVIE_METHOD(o->scl[i].handle, "SHOW_STAT_WALL");
		SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(o->wallID);
		END_SCALEFORM_MOVIE_METHOD();

		WAIT(0);
	}
	o->startTime = MISC::GET_GAME_TIMER();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(o->scl[0].handle, "GET_TOTAL_WALL_DURATION");
	int retHandle = GRAPHICS::END_SCALEFORM_MOVIE_METHOD_RETURN_VALUE();
	while (!GRAPHICS::IS_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_READY(retHandle)) WAIT(0);
	o->duration = GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT(retHandle);
	o->endTime = (o->startTime + o->duration);
	while (MISC::GET_GAME_TIMER() < o->endTime) {
		WAIT(0);
		//utils_DrawMissionText((char*)uTil_int_to_string_conversion(iPtr->endTime));
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(o->scl[2].handle, o->scl[1].handle, 255, 255, 255, 100);
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(o->scl[0].handle, 255, 255, 255, 255, 0);
		HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
		PAD::DISABLE_ALL_CONTROL_ACTIONS(2);
	}
	PAD::ENABLE_ALL_CONTROL_ACTIONS(2);
	for (int i = 0; i < 3; i++) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&o->scl[i].handle);
	}
	celeb_Destroy(cIns);
}
void CELEB_MISS_RESULT(int handle, const char* wallId, const char* textLabel, const char* bigPass, const char* playerDied) {
	if (textLabel == NULL) textLabel = "NULL";
	if (bigPass == NULL) bigPass = "NULL";
	if (playerDied == NULL) playerDied = "NULL";
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_MISSION_RESULT_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallId);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(textLabel); //textlabel
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(bigPass); //passFail
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(playerDied); // msgLabel
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMsgraw
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isPassFailRaw
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMissionTextRaw
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
/*
* @brief NEEDS DOCUMENTATION THIS IS VERY CONFUSING.
*/
void CELEB_ADD_WINNER_TO_WALL(int handle, const char* wallID, BOOL_t isInFlow, const char* largeLabel, const char* playerName, const char* crewName, const char* teamName, int bet) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_WINNER_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(largeLabel);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(playerName);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(crewName);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(bet);//bet
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isInFlow); //isinFlow?
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(teamName);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //gamerNameLabel
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CELEB_ADD_INTRO_CARD(int handle, char* wallid, char* modeName, char* jobName, char* chalPartText, BOOL doExtend, BOOL doChalText) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_INTRO_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallid); // walid
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(modeName); // mode name
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(jobName); //job name
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(doChalText); // chal text
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(chalPartText); // chalPartText
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(doExtend); // tarTextType
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING("CONTRACT HEIST"); // tarVal
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(0); // delay
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING("CONTRACT HEIST"); // tarValPrefix
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); // is
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING("HUD_COLOUR_YELLOWLIGHT");
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CELEB_CREATE_INCREMENT_CASH_ANIM(int handle, char* wallID, char* cashID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CREATE_INCREMENTAL_CASH_ANIMATION");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(cashID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
/*
* RightHandIco 0 = Nothing; 1 = CHECK; 2 = CROSS; 3 = Nothing.
*/
void CELEB_ADD_INCREMENT_CASH_ANIM(int handle, char* wallID, char* cashID, float startVal, float endVal, char* __completetxt__, char* __taskComplete__, char* rightHandStat, int rightHandIco) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_INCREMENTAL_CASH_WON_STEP");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(cashID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(startVal); //startVal
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(endVal); //finVal
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(__completetxt__);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(__taskComplete__);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(rightHandStat); // rightHandStat
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(rightHandIco); //rightHandIco
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_INCREMENT_CASH_TO_WALL(int handle, char* wallID, char* cashID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_INCREMENTAL_CASH_ANIMATION_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(cashID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void ADD_BREAKPOINT(int handle, char* wallID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_BREAKPOINT");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void RESUME_FROM_BREAKPOINT(int handle, char* wallID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "RESUME_FROM_BREAKPOINT");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_OBJ_TO_WALL(int handle, char* wallID, char* objTitle, char* objText) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_OBJECTIVE_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(objTitle);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(objText);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); // NO IDEA?
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_CASH_TO_WALL(int handle, char* wallID, int incrementCash, BOOL_t unknown = TRUE) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_CASH_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(incrementCash);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(unknown);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_JP_TO_WALL(int handle, char* wallID, float JP, BOOL_t unknown = FALSE) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_JOB_POINTS_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(JP);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(unknown);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_RP_AND_BAR_TO_WALL(int handle, char* wallID, float start, float repGain, float currentRnk, float nextRnk, float minRepForRnk, float maxRepForRank, char* rnkTxt, char*rnkTxt2) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_REP_POINTS_AND_RANK_BAR_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID); // wallid
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(repGain); //repGain
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(start); //start
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(minRepForRnk);  //minRepForRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(maxRepForRank);  //maxRepForRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(currentRnk);  //currentRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(nextRnk);  //nextRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(rnkTxt); // rnktxt1
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(rnkTxt2);// rnktxt2
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_READY(int handle, char* wallID, BOOL_t unknown) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_READY_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(unknown);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_CHAL_WINNER_TO_WALL(int handle, char* wallID, char* subTxt, char* winLose, char* crew, char* challLabel, float bet, BOOL_t isFlow) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_CHALLENGE_WINNER_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(subTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(winLose);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(crew);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(challLabel);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(bet);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isFlow); //flow
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //winner
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //mission
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //winloseRaw
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(""); // VALUE BEFORE chalLabel takes over
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_BKG_TO_WALL(int handle, char* wallID, float opacity, int unknown = -1) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_BACKGROUND_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(opacity);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(unknown);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_SHOW_STAT_WALL(int handle, char* wallID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SHOW_STAT_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
int CELEB_GET_INT_RESULT(int handle) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "GET_TOTAL_WALL_DURATION");
	int retHandle = GRAPHICS::END_SCALEFORM_MOVIE_METHOD_RETURN_VALUE();
	while (!GRAPHICS::IS_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_READY(retHandle)) WAIT(0);
	int time = GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT(retHandle);
	return time;
}
void CELEB_CREATE_STAT_WALL(int handle, char* wallID, char* hudColour, int opacity) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CREATE_STAT_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(hudColour);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(opacity);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_CLEANUP(int handle, char* wallID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CLEANUP");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_CREATE_STAT_TABLE(int handle, char* wallID, char* tableID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CREATE_STAT_TABLE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(tableID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_STAT_TO_STAT_TABLE(int handle, char* wallID, char* tableID, char* statTxt, char* statVal, BOOL isStatTXTRaw, BOOL isStatValRaw, BOOL isTotalRow, BOOL isStatTime, char* colour){
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_STAT_TO_TABLE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(tableID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statVal);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isStatTXTRaw);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isStatValRaw);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isTotalRow);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isStatTime);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(colour);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_STAT_TABLE_TO_WALL(int handle, char* wallID, char* tableID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_STAT_TABLE_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(tableID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_SCORE_TO_WALL(int handle, char* wallID, char* txtlb, char* score) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_SCORE_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(txtlb);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(score);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_POS_TO_WALL(int handle, char* wallID, char* pos, char* posLabel, BOOL isRaw, BOOL isScore) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_POSITION_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(pos);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(posLabel);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isRaw);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isScore);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
typedef enum {
	CURRENTCY_CASH		= 1,
	CURRENTCY_RP		= 2,
	CURRENTCY_JP		= 3,
	CURRENTCY_AP		= 4,
	CURRENTCY_COPREP	= 5,
	CURRENTCY_CRIMRP	= 6,
	CURRENTCY_COPTOK	= 7,
	CURRENTCY_CRIMTOK	= 8
}Currency;
void CELEB_ADD_POINTS_TO_WALL(int handle, char* wallID, int points, Currency type, char* prefix, BOOL xAlign, BOOL marginTop, BOOL noAnims){
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_POINTS_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(points);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(type);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(prefix);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(xAlign);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(marginTop);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(noAnims);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CELEB_ADD_STAT_NUMERIC_TO_WALL(int handle, char* wallID, char* statLBL, char* statVal, BOOL xAlign, BOOL isRaw) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_STAT_NUMERIC_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statLBL);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statVal);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(xAlign);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isRaw);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CELEB_ADD_CASH_WON_TO_WALL(int handle, char* wallID, int statVal, int potentVal, BOOL xAlign, BOOL isRaw) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_CASH_WON_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(xAlign);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(statVal); // reg
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(potentVal);//potent?
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isRaw);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_WAVE_REACHED_TO_WALL(int handle, char* wallID, char* waveTxt, char* reachedLbl) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_WAVE_REACHED_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(waveTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(reachedLbl);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_WR_TO_WALL(int handle, char* wallID, char* time) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_WORLD_RECORD_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(time);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_TOURN_TO_WALL(int handle, char* wallID, char* playListName, char* qualificationLabel, char* resultTxt, BOOL isResultRaw, char* resultVal) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_TOURNAMENT_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(playListName);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(qualificationLabel);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(resultTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isResultRaw);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(resultVal);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_UNLOCK_CASH_TO_WALL(int handle, char* wallID, int cshAmm, BOOL xAlign) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_POST_UNLOCK_CASH_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(cshAmm);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(xAlign);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_ADD_CHAL_PART_TO_WALL(int handle, char* wallID, char* winLoseLabel, char* chalPartsLabel) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_CHALLENGE_PART_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(winLoseLabel);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(chalPartsLabel);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_PAUSE(int handle, char* wallID, int duration) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "PAUSE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(duration);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CELEB_DRAW(int handle, int handle_bg, int handle_fg, int offset, BOOL_t offsetNeg) {
	if (offsetNeg) {
		offset = -offset;
	}
	int startTime = MISC::GET_GAME_TIMER();
	int time = CELEB_GET_INT_RESULT(handle);
	int endTime = startTime + time;
	while (MISC::GET_GAME_TIMER() < endTime + offset) {
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(handle_bg, handle_fg, 255, 255, 255, 100);
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(handle, 255, 255, 255, 255, 0);
		HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
		//PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
		WAIT(0);
	}
	GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&handle);
	GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&handle_fg);
	GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&handle_bg);
}
int* CELEB_OUTRO_DRAW(CelebHandle *handle) {
	MP_CELEB* h = (MP_CELEB*)handle;
	h->scl[2].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_BG");
	h->scl[1].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_FG");
	h->scl[0].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION");
	for (int i = 0; i < 3; i++) {
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(h->scl[i].handle)) WAIT(0);
		CELEB_CLEANUP(h->scl[i].handle, h->wallID);
		CELEB_CREATE_STAT_WALL(h->scl[i].handle, h->wallID, "HUD_COLOUR_HSHARD", 100);
		CELEB_MISS_RESULT(h->scl[i].handle, h->wallID, "HEIST", "PASSED", "");
		CELEB_CREATE_STAT_TABLE(h->scl[i].handle, h->wallID, "table");
		CELEB_ADD_STAT_TO_STAT_TABLE(h->scl[i].handle, h->wallID, "table", "Player1", "PLATNUM", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_PLATINUM");
		CELEB_ADD_STAT_TO_STAT_TABLE(h->scl[i].handle, h->wallID, "table", "Player2", "GOLD", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_GOLD");
		CELEB_ADD_STAT_TO_STAT_TABLE(h->scl[i].handle, h->wallID, "table", "Player3", "SILVER", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_SILVER");
		CELEB_ADD_STAT_TO_STAT_TABLE(h->scl[i].handle, h->wallID, "table", "Player4", "BRONZE", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_BRONZE");
		CELEB_ADD_STAT_TABLE_TO_WALL(h->scl[i].handle, h->wallID, "table");
		CELEB_CREATE_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID");
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 0, 1875000, "POTENTIAL TAKE", "", "", 0);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 1875000, 1805205, "ACTUAL TAKE", "", "", 0);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 1805205, 451301, "25% CUT OF TAKE", "", "", 0);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 451301, 451301, "ELITE CHALLENGE", "COMPLETE IN UNDER 10:15 MINS", "15:26", 2);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 451301, 451301, "ELITE CHALLENGE", "NOOSE NOT CALLED", "", 2);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 451301, 451301, "ELITE CHALLENGE", "NOBODY GETS WASTED", "", 1);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 451301, 451301, "ELITE CHALLENGE INCOMPLETE", "", "", 0);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 451301, 1451050, "ALL IN ORDER CHALLENGE BONUS", "COMPLETE ALL HEIST SETUPS AND FINALES IN ORDER", "", 0);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 1451050, 11451050, "CRIMINAL MASTERMIND CHALLENGE BONUS", "COMPLETE ALL HEIST SETUPS AND FINALES, IN ORDER, WITH THE SAME TEAM, WITHOUT LOSING ANY LIVES", "", 0);
		CELEB_ADD_INCREMENT_CASH_ANIM(h->scl[i].handle, h->wallID, "ID", 11451050, 11451050, "TOTAL CASH EARNED", "", "", 0);
		CELEB_ADD_INCREMENT_CASH_TO_WALL(h->scl[i].handle, h->wallID, "ID");
		CELEB_PAUSE(h->scl[i].handle, h->wallID, 5*6);
		CELEB_ADD_JP_TO_WALL(h->scl[i].handle, h->wallID, 15, 1);
		CELEB_ADD_RP_AND_BAR_TO_WALL(h->scl[i].handle, h->wallID, 200, 1500, 16, 17, 1500, 2000, "RNK", "RNK2");
		CELEB_ADD_BKG_TO_WALL(h->scl[i].handle, h->wallID, h->opacity, h->type);
		CELEB_SHOW_STAT_WALL(h->scl[i].handle, h->wallID);
	}
	int startTime = MISC::GET_GAME_TIMER();
	int time = CELEB_GET_INT_RESULT(h->scl[0].handle);
	int endTime = startTime + time;

	while (MISC::GET_GAME_TIMER() < endTime+3000) {
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(h->scl[2].handle, h->scl[1].handle, 255, 255, 255, 100);
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(h->scl[0].handle, 255, 255, 255, 255, 0);
		HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
		//PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
		WAIT(0);
	}
	WAIT(0);
	for (int i = 0; i < 3; i++) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&h->scl[i].handle);
	}
	celeb_Destroy(handle);
	int x = 0;
	return &x;
}
/*
* Bonus' goes as follows
* 1 = Just CriminalMasterMind
* 2 = Just Elite Challenge;
* 3 = Both
*/
void exampleOutro(CelebHandle* handle) {
	MP_CELEB* a = (MP_CELEB*)handle;
	if (a == NULL) return;
	a->scl[2].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_BG");
	a->scl[1].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION_FG");
	a->scl[0].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_CELEBRATION");
	for (int i = 0; i < SCL_LIMIT; i++) {
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(a->scl[i].handle)) WAIT(0);
		CELEB_CLEANUP(a->scl[i].handle, a->wallID);
		CELEB_CREATE_STAT_WALL(a->scl[i].handle, a->wallID, "HUD_COLOUR_HSHARD", 100);
		CELEB_MISS_RESULT(a->scl[i].handle, a->wallID, "HEIST", "PASSED", "");
		CELEB_CREATE_STAT_TABLE(a->scl[i].handle, a->wallID, "table");
		CELEB_ADD_STAT_TO_STAT_TABLE(a->scl[i].handle, a->wallID, "table", "Player1", "PLATNUM", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_PLATINUM");
		CELEB_ADD_STAT_TO_STAT_TABLE(a->scl[i].handle, a->wallID, "table", "Player2", "GOLD", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_GOLD");
		CELEB_ADD_STAT_TO_STAT_TABLE(a->scl[i].handle, a->wallID, "table", "Player3", "SILVER", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_SILVER");
		CELEB_ADD_STAT_TO_STAT_TABLE(a->scl[i].handle, a->wallID, "table", "Player4", "BRONZE", TRUE, TRUE, FALSE, FALSE, "HUD_COLOUR_BRONZE");
		CELEB_ADD_STAT_TABLE_TO_WALL(a->scl[i].handle, a->wallID, "table");
		CELEB_CREATE_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID");
		a->outro.startMoney = 0;
		a->outro.endMoney = 1875000;
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.startMoney, a->outro.endMoney, "POTENTIAL TAKE", "", "", 0);
		a->outro.startMoney = a->outro.endMoney;
		a->outro.endMoney = 1805205;
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.startMoney, a->outro.endMoney, "ACTUAL TAKE", "", "", 0);
		a->outro.startMoney = a->outro.endMoney;
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.startMoney, a->outro.endMoney *= .25, "25% CUT OF TAKE", "", "", 0);
		a->outro.startMoney = a->outro.endMoney;
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.endMoney, a->outro.endMoney, "ELITE CHALLENGE", "COMPLETE IN UNDER 10:15 MINS", "15:26", 2);
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.endMoney, a->outro.endMoney, "ELITE CHALLENGE", "NOOSE NOT CALLED", "", 2);
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.endMoney, a->outro.endMoney, "ELITE CHALLENGE", "NOBODY GETS WASTED", "", 1);
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.endMoney, a->outro.endMoney, "ELITE CHALLENGE INCOMPLETE", "", "", 0);
		a->outro.startMoney = a->outro.endMoney;
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.startMoney, a->outro.endMoney += 999749, "ALL IN ORDER CHALLENGE BONUS", "COMPLETE ALL HEIST SETUPS AND FINALES IN ORDER", "", 0);
		a->outro.startMoney = a->outro.endMoney;

		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.startMoney, a->outro.endMoney += 10000000, "CRIMINAL MASTERMIND CHALLENGE BONUS", "COMPLETE ALL HEIST SETUPS AND FINALES, IN ORDER, WITH THE SAME TEAM, WITHOUT LOSING ANY LIVES", "", 0);
		CELEB_ADD_INCREMENT_CASH_ANIM(a->scl[i].handle, a->wallID, "ID", a->outro.endMoney, a->outro.endMoney, "TOTAL CASH EARNED", "", "", 0);
		CELEB_ADD_INCREMENT_CASH_TO_WALL(a->scl[i].handle, a->wallID, "ID");
		CELEB_PAUSE(a->scl[i].handle, a->wallID, 5 * 6);
		CELEB_ADD_JP_TO_WALL(a->scl[i].handle, a->wallID, 15, 1);
		CELEB_ADD_RP_AND_BAR_TO_WALL(a->scl[i].handle, a->wallID, 200, 1500, 16, 17, 1500, 2000, "RNK", "RNK2");
		CELEB_ADD_BKG_TO_WALL(a->scl[i].handle, a->wallID, a->opacity, a->type);
		CELEB_SHOW_STAT_WALL(a->scl[i].handle, a->wallID);
	}
	CELEB_DRAW(a->scl[0].handle, a->scl[2].handle, a->scl[1].handle, 2000, FALSE);
	celeb_Destroy(handle);
}
#endif
#undef NATIVE_H
