#include "internal_scaleform.h"
#include "..\Scaleform.h"
#include "../ScriptHookV/natives.h"
#define MODE_LIMIT 64
void HC_CREATE_STAT_WALL(int handle, char* wallID, char* bgColour, int sfxId) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CREATE_STAT_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(bgColour);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(sfxId);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_BKG_TO_WALL(int handle, char* wallID, int opacity, int moneyMesh) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_BACKGROUND_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(opacity);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(moneyMesh);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_MISS_RESULT(int handle, char* wallID, char* missionTextLbl, char* passFail, char* msgLabel) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_MISSION_RESULT_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(missionTextLbl); //textlabel
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(passFail); //passFail
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(msgLabel); // msgLabel
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMsgraw
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isPassFailRaw
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMissionTextRaw
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_COMPLETE_MESS_TO_WALL(int handle, char* wallID, char* missionTextLbl, char* passFail, char* msgLabel) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_MISSION_RESULT_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(missionTextLbl); //textlabel
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(passFail); //passFail
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(msgLabel); // msgLabel
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMsgraw
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isPassFailRaw
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE); //isMissionTextRaw
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_CREATE_STAT_TABLE(int handle, char* wallID, char* statID, int sfxID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CREATE_STAT_TABLE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(sfxID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_STAT_TO_WALL(int handle, char* wallID, char* statId, char* name, char* val, BOOL_t isTotalRow, BOOL_t isValTime, char* COLID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_STAT_TO_TABLE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statId);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(name);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(val);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isTotalRow);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isValTime);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(COLID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_STAT_TABLE_TO_WALL(int handle, char* wallID, char* statId) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_STAT_TABLE_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statId);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_SHOW_STAT_WALL(int handle, char* wallID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SHOW_STAT_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_CREATE_INCREMENTAL_CASH_ANIM(int handle, char* wallID, char* stepID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CREATE_INCREMENTAL_CASH_ANIMATION");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(stepID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_INCREMENTAL_CASH_WON_STEP(int handle, char* wallID, char* stepID, float startDol, float finishDol, char* topTxt, char* bottomTxt, char* handStat, BOOL_t handico, int soundType) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_INCREMENTAL_CASH_WON_STEP");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(stepID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(startDol); //startVal
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(finishDol); //finVal
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(topTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(bottomTxt);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(handStat); // rightHandStat
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(handico); //rightHandIco
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(soundType);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_INCREMENTAL_CASH_TO_WALL(int handle, char* wallID, char* stepID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_INCREMENTAL_CASH_ANIMATION_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(stepID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_JP(int handle, char* wallID, int pts, BOOL_t xAlign) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_JOB_POINTS_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(pts);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(xAlign);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_RP_AND_BAR(int handle, char* wallID, int repGained, int startRep, int minRepForRank, int maxRepForRank, int currentRank, int nextRank, char* rnk1txt, char* ranktxt2) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_REP_POINTS_AND_RANK_BAR_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID); // wallid
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(repGained); //repGain
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(startRep); //start
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(minRepForRank);  //minRepForRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(maxRepForRank);  //maxRepForRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(currentRank);  //currentRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(nextRank);  //nextRank
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(rnk1txt); // rnktxt1
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(ranktxt2);// rnktxt2
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
//IMPORTANT
void HC_ADD_CASH_DEDUCTION(int handle, char* wallID, char* title, char* desc, int val) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_CASH_DEDUCTION");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(title);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(desc);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(val); 
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_CASH_WON_TO_WALL(int handle, char* wallID, char* statLbl, int finVal, int startVal, BOOL_t xAlign, BOOL_t isRawTxt) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_CASH_WON_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(statLbl);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(startVal); // reg
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(finVal);//potent?
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(xAlign);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(isRawTxt);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_ADD_CASH_TO_WALL(int handle, char* wallID, float val, BOOL_t xAlign) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "ADD_CASH_TO_WALL");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(val);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(xAlign);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_CLEANUP(int handle, char* wallID) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CLEANUP");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
int GET_TIME(int handle) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "GET_TOTAL_WALL_DURATION");
	int retHandle = GRAPHICS::END_SCALEFORM_MOVIE_METHOD_RETURN_VALUE();
	while (!GRAPHICS::IS_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_READY(retHandle)) WAIT(0);
	int time = GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT(retHandle);
	return time;
}
#define SCL_LIMIT 3
typedef struct table_s {
	char tableID[MODE_LIMIT];
	int numOfData;
	size_t sizeOfData;
	void* data;
}TableStruct;
typedef struct {
	Scaleform scl[SCL_LIMIT];
	int startCash, endCash, currentRank, nextRank, minRPforNext, maxRPforNext, rpGained;
	char wallID[MODE_LIMIT / 4], firstLine[MODE_LIMIT/4], largeTxt[MODE_LIMIT/4], deathTxt[MODE_LIMIT/2];
	CelebrationTypes types;
	TableStruct table;
	int opacity;
}HeistCelebration;
TableHandle* tb_Create(char* tableID, int numOfData, size_t _DATA_SIZE_, void* data) {
	TableStruct* table = (TableStruct*)malloc(sizeof(TableStruct));
	if (table == NULL) return NULL;
	if (_DATA_SIZE_ != sizeof(data))return NULL;
	strncpy(table->tableID, tableID, MODE_LIMIT-2);
	table->tableID[MODE_LIMIT-1] = '\0';
	table->sizeOfData = _DATA_SIZE_;
	table->numOfData = numOfData;
	table->data = data; // No write operations on Data?
	return (TableHandle*)table;
}
void tb_AddData(TableHandle* tableHandle, void* data) {
	if (tableHandle == NULL) return;
	TableStruct* tb_ = (TableStruct*)tableHandle;
	tb_->numOfData++;
	tb_->data = data;
}
void tb_Destroy(TableHandle* t_handle) {
	if (t_handle == NULL) return;
	TableStruct* tb = (TableStruct*)t_handle;
	free(tb->data);
	tb->numOfData = NULL;
	tb->sizeOfData = NULL;
	free(tb);
}
HeistCelebHandle* heistceleb_Create(char firstLine[MODE_LIMIT / 4], char largeText[MODE_LIMIT / 4], char deathText[MODE_LIMIT / 2], CelebrationTypes type, int opacity, int startMoney, int endMoney, int startRank, int endRank) {
	if (firstLine == NULL) firstLine = "NULL";
	if (largeText == NULL) largeText = "NULL";
	if (deathText == NULL) deathText = "NULL";

	HeistCelebration* celeb = (HeistCelebration*)malloc(sizeof(HeistCelebration));
	if (celeb == NULL) return NULL;
	//Pre-init vals.
	strncpy(celeb->scl[0].name, "HEIST_CELEBRATION\0", strnlen("HEIST_CELEBRATION\0", 64));
	strncpy(celeb->scl[1].name, "HEIST_CELEBRATION_BG\0", strnlen("HEIST_CELEBRATION_BG\0", 64));
	strncpy(celeb->scl[2].name, "HEIST_CELEBRATION_FG\0", strnlen("HEIST_CELEBRATION_FG\0", 64));
	strncpy(celeb->wallID, "OUTRO", 16);

	strncpy(celeb->firstLine, firstLine, 16);
	strncpy(celeb->largeTxt, largeText, 16);
	strncpy(celeb->deathTxt, deathText, 32);
	celeb->opacity = opacity;
	celeb->types = type;
	celeb->currentRank = startRank;
	celeb->nextRank = endRank;
	celeb->startCash = startMoney;
	celeb->endCash = endMoney;
	return (CelebHandle*)celeb;
}
void heistceleb_Destroy(HeistCelebHandle* inst) {
	HeistCelebration* hc = (HeistCelebration*)inst;
	free(hc);
}
void HC_PAUSE(int handle, char* wallID, int duration) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "PAUSE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(duration);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_CREATE_SEQUENCE(int handle, char* wallID, int sfxID, int colourId) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "createSequence");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(colourId);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(sfxID);
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(wallID);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void HC_example(HeistCelebHandle* inst) {
	HeistCelebration* h = (HeistCelebration*)inst;
	h->scl[2].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION_BG");
	h->scl[1].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION_FG");
	h->scl[0].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION");
	for (int i = 0; i < 3; i++) {
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(h->scl[i].handle)) WAIT(0);
		HC_CLEANUP(h->scl[i].handle, h->wallID);
		HC_CREATE_STAT_WALL(h->scl[i].handle, h->wallID, "HUD_COLOUR_HSHARD", 100);
		HC_ADD_COMPLETE_MESS_TO_WALL(h->scl[i].handle, h->wallID, "HEIST", "PASSED", "");
		HC_CREATE_STAT_TABLE(h->scl[i].handle, h->wallID, "table", 3);
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player1", "PLATNUM", FALSE, FALSE, "HUD_COLOUR_PLATINUM");
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player2", "GOLD", FALSE, FALSE, "HUD_COLOUR_GOLD");
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player3", "SILVER", FALSE, FALSE, "HUD_COLOUR_SILVER");
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player4", "BRONZE", FALSE, FALSE,  "HUD_COLOUR_BRONZE");
		HC_ADD_STAT_TABLE_TO_WALL(h->scl[i].handle, h->wallID, "table");
		HC_CREATE_INCREMENTAL_CASH_ANIM(h->scl[i].handle, h->wallID, "ID");
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", 0, 1875000, "POTENTIAL TAKE", "", "", -1, 3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", 1875000, 1805205, "ACTUAL TAKE", "", "",-1,3);
		int x = 1805205 * .25;
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", 1805205, x, "25% CUT OF TAKE", "", "", -1,3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", x, x, "ELITE CHALLENGE", "COMPLETE IN UNDER 10:15 MINS", "15:26", 2,3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", x, x, "ELITE CHALLENGE", "NOOSE NOT CALLED", "", 2,3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", x, x, "ELITE CHALLENGE", "NOBODY GETS WASTED", "", 1,3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", x, x, "ELITE CHALLENGE INCOMPLETE", "", "", -1,3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", x, x + 999749, "ALL IN ORDER CHALLENGE BONUS", "COMPLETE ALL HEIST SETUPS AND FINALES IN ORDER", "", 0,3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", x + 999749, x + 999749 + 10000000, "CRIMINAL MASTERMIND CHALLENGE BONUS", "COMPLETE ALL HEIST SETUPS AND FINALES, IN ORDER, WITH THE SAME TEAM, WITHOUT LOSING ANY LIVES", "", 0,3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", x + 999749 + 10000000, x + 999749 + 10000000, "TOTAL CASH EARNED", "", "", -1,3);
		HC_ADD_INCREMENTAL_CASH_TO_WALL(h->scl[i].handle, h->wallID, "ID");
		HC_PAUSE(h->scl[i].handle, h->wallID, 5 * 6);
		HC_ADD_JP(h->scl[i].handle, h->wallID, 15, FALSE);
		HC_ADD_RP_AND_BAR(h->scl[i].handle, h->wallID, 200, 1500, 16, 17, 1500, 2000, "NICE", "RANKUP!");
		HC_ADD_BKG_TO_WALL(h->scl[i].handle, h->wallID, h->opacity, h->types);
		HC_SHOW_STAT_WALL(h->scl[i].handle, h->wallID);
		HC_CREATE_SEQUENCE(h->scl[i].handle, h->wallID, 1,1);
	}
	int startTime = MISC::GET_GAME_TIMER();
	int time = 48000;
	int endTime = startTime + time;
	AUDIO::PLAY_SOUND_FRONTEND(-1, "CHECKPOINT_PERFECT", "HUD_MINI_GAME_SOUNDSET", 1);
	while (MISC::GET_GAME_TIMER() < endTime) {
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
	GRAPHICS::ANIMPOSTFX_PLAY("HeistCelebToast", 0, FALSE);
	heistceleb_Destroy(inst);
	return;
}

/*No example free(s) the memory after the use case which is why this returns a Handle obj.*/
HeistCelebHandle* EX_HC_FAILED(int startRep, int currentRank, int nextRank, int minNext, int maxNext, int rpToNext, int rpGain, int jp) {
	HeistCelebration* h = (HeistCelebration*)heistceleb_Create("HEIST", "FAILED", "", CelebType_SHARD, 70, 0, 0, 0, 0);
	h->scl[2].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION_BG");
	h->scl[1].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION_FG");
	h->scl[0].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION");
	for (int i = 0; i < 3; i++) {
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(h->scl[i].handle)) WAIT(0);
		HC_CLEANUP(h->scl[i].handle, h->wallID);
		HC_CREATE_STAT_WALL(h->scl[i].handle, h->wallID, "HUD_COLOUR_HSHARD", 1);
		HC_ADD_COMPLETE_MESS_TO_WALL(h->scl[i].handle, h->wallID, h->firstLine, h->largeTxt, h->deathTxt);
		HC_ADD_JP(h->scl[i].handle, h->wallID, jp, FALSE);
		HC_ADD_RP_AND_BAR(h->scl[i].handle, h->wallID, rpGain, startRep, minNext, maxNext, currentRank, nextRank, "NICE", "RANKUP!");
		HC_ADD_BKG_TO_WALL(h->scl[i].handle, h->wallID, h->opacity, h->types);
		HC_SHOW_STAT_WALL(h->scl[i].handle, h->wallID);
		HC_CREATE_SEQUENCE(h->scl[i].handle, h->wallID, 1, 1);
	}
	if (startRep + rpGain >= maxNext) {
		int startTime = MISC::GET_GAME_TIMER();
		int time = 11200;
		int endTime = startTime + time;
		AUDIO::PLAY_SOUND_FRONTEND(-1, "CHECKPOINT_PERFECT", "HUD_MINI_GAME_SOUNDSET", 1);
		while (MISC::GET_GAME_TIMER() < endTime) {
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
		GRAPHICS::ANIMPOSTFX_PLAY("HeistCelebToast", 0, FALSE);
		heistceleb_Destroy(h);
		return NULL;
	}
	else {
		int startTime = MISC::GET_GAME_TIMER();
		int time = 8299;
		int endTime = startTime + time;
		AUDIO::PLAY_SOUND_FRONTEND(-1, "CHECKPOINT_PERFECT", "HUD_MINI_GAME_SOUNDSET", 1);
		while (MISC::GET_GAME_TIMER() < endTime) {
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
		GRAPHICS::ANIMPOSTFX_PLAY("HeistCelebToast", 0, FALSE);
		heistceleb_Destroy(h);
		return NULL;
	}
}
/*
*No example free(s) the memory after the use case which is why this returns a Handle obj.
* Still cleans Scaleform for in game proformance and as well to make sure it doesn't fuck with the next one.
*/
HeistCelebHandle* EX_HC_PASS(int potentTake, int actualTake, float cut , int startRep ,int currentRank, int nextRank, int rpToNextRank, int rpGained, int jp) {
	HeistCelebration* h = (HeistCelebration*)heistceleb_Create("HEIST", "PASSED", "", CelebType_SHARD, 70, 0, 0, 0, 0);
	h->scl[2].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION_BG");
	h->scl[1].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION_FG");
	h->scl[0].handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("HEIST_CELEBRATION");
	for (int i = 0; i < 3; i++) {
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(h->scl[i].handle)) WAIT(0);
		HC_CLEANUP(h->scl[i].handle, h->wallID);
		HC_CREATE_STAT_WALL(h->scl[i].handle, h->wallID, "HUD_COLOUR_HSHARD", 3);
		HC_ADD_COMPLETE_MESS_TO_WALL(h->scl[i].handle, h->wallID, "HEIST", "PASSED", "");
		HC_CREATE_STAT_TABLE(h->scl[i].handle, h->wallID, "table", 3);
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player1", "PLATNUM", FALSE, FALSE, "HUD_COLOUR_PLATINUM");
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player2", "GOLD", FALSE, FALSE, "HUD_COLOUR_GOLD");
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player3", "SILVER", FALSE, FALSE, "HUD_COLOUR_SILVER");
		HC_ADD_STAT_TO_WALL(h->scl[i].handle, h->wallID, "table", "Player4", "BRONZE", FALSE, FALSE, "HUD_COLOUR_BRONZE");
		HC_ADD_STAT_TABLE_TO_WALL(h->scl[i].handle, h->wallID, "table");
		HC_CREATE_INCREMENTAL_CASH_ANIM(h->scl[i].handle, h->wallID, "ID");
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", 0, potentTake, "POTENTIAL TAKE", "", "", -1, 3);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", potentTake, actualTake, "ACTUAL TAKE", "", "", -1, 3);
		char* cutpercentinstr = util_IntToStr(cut);
		cutpercentinstr = (char*)realloc(cutpercentinstr, strlen(cutpercentinstr) + 13);
		strcat(cutpercentinstr, "% CUT OF TAKE\0");
		float finalCut = actualTake * (cut / 100);
		HC_ADD_INCREMENTAL_CASH_WON_STEP(h->scl[i].handle, h->wallID, "ID", actualTake, finalCut, cutpercentinstr, "", "", -1, 3);
		free(cutpercentinstr);
		HC_ADD_INCREMENTAL_CASH_TO_WALL(h->scl[i].handle, h->wallID, "ID");
		HC_ADD_JP(h->scl[i].handle, h->wallID, jp, FALSE);
		HC_ADD_RP_AND_BAR(h->scl[i].handle, h->wallID, 200, 100, 100, 4000, 199, 200, "NICE", "RANKUP!");
		HC_ADD_BKG_TO_WALL(h->scl[i].handle, h->wallID, h->opacity, h->types);
		HC_SHOW_STAT_WALL(h->scl[i].handle, h->wallID);
		HC_CREATE_SEQUENCE(h->scl[i].handle, h->wallID, 1, 1);
	}
	int startTime = MISC::GET_GAME_TIMER();
	int time = 26600;
	int endTime = startTime + time;
	AUDIO::PLAY_SOUND_FRONTEND(-1, "CHECKPOINT_PERFECT", "HUD_MINI_GAME_SOUNDSET", 1);
	while (MISC::GET_GAME_TIMER() < endTime) {
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
	GRAPHICS::ANIMPOSTFX_PLAY("HeistCelebToast", 0, FALSE);
	heistceleb_Destroy(h);
	return NULL;
}
