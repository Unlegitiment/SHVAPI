#pragma once
#include "utils.h"
#include "Scaleform/HUD_COLOUR.h"
typedef void CelebHandle;
typedef void HeistCelebHandle;
typedef void TableHandle;


typedef void MidSizedHandle;
typedef void BigMsgHandle;

typedef enum {
	CM_INTRO = 0,
	CM_OUTRO = 1,
	CM_CUSTOM = 2
}CelebMode;
typedef enum CelebrationTypes {
	CelebType_Nothing = 0,
	CelebType_SHARD = 1,
	CelebType_RACEFLAG = 3,
	CelebType_GRID = 6,
	CelebType_TARGETASSAULT = 8,
	CelebType_REMIX1 = 10,
	CelebType_REMIX2 = 12,
	CelebType_REMIX3 = 14,
	CelebType_REMIX4 = 16,
	CelebType_REMIX5 = 18,
	CelebType_ARENAWAR = 20
}CelebT;

extern void celeb_Draw(CelebHandle* celeb);
#define MODE_LIMIT 64
extern CelebHandle* celeb_Intro_Create(char missionName[MODE_LIMIT],char missionType[MODE_LIMIT],char modeType[MODE_LIMIT],CelebrationTypes type,BOOL_t chalTextLabel,BOOL_t tarTypeTextLabel,BOOL_t modeLabelIsStringLiteral = TRUE_,int opacity = 0);

extern void Outro_Draw(CelebHandle* cIns);

extern CelebHandle* celeb_Outro_Create(char firstLine[MODE_LIMIT / 4],char largeText[MODE_LIMIT / 4],char deathText[MODE_LIMIT / 2],CelebrationTypes type,int opacity = 70,int startMoney = -1,int endMoney = -1,int startRank = -1,int endRank = -1);
extern int* CELEB_OUTRO_DRAW(CelebHandle* handle);
extern void exampleOutro(CelebHandle* handle);

extern HeistCelebHandle* heistceleb_Create(char firstLine[MODE_LIMIT / 4],char largeText[MODE_LIMIT / 4],char deathText[MODE_LIMIT / 2],CelebrationTypes type,int opacity = 70,int startMoney = -1,int endMoney = -1,int startRank = -1,int endRank = -1);
extern void heistceleb_Destroy(HeistCelebHandle* inst);
extern void HC_example(HeistCelebHandle *inst);


/*
* HEIST_CELEBRATION Scaleform Functions _RAW_:
* These Set of functions are the base that are used for the Scaleform you can find them on: https://www.vespura.com/fivem/scaleform/#HEIST_CELEBRATION
* 
* Parameters (REQUIRED):
*	int handle = The Handle returned by the Request to allow access to the data
*	char* wallID = The wallID that being used. Typically specified by HC_Struct->wallID
* 
*/

/*
* @param char* BG_COLOUR = Hud Colour
* @param int sfxID = 1 - 3 Sound Identifications to play through scaleform 1 = Unknown. 2 = Failed. 3 = Success.
*/
extern void HC_CREATE_STAT_WALL(int handle, char* wallID, char* bgColour, int sfxId);
extern void HC_ADD_BKG_TO_WALL(int handle, char* wallID, int opacity, int moneyMesh);
extern void HC_ADD_MISS_RESULT(int handle, char* wallID, char* missionTextLbl, char* passFail, char* msgLabel);
extern void HC_ADD_COMPLETE_MESS_TO_WALL(int handle, char* wallID, char* missionTextLbl, char* passFail, char* msgLabel);
extern void HC_CREATE_STAT_TABLE(int handle, char* wallID, char* statID, int sfxID);
extern void HC_ADD_STAT_TO_WALL(int handle, char* wallID, char* statId, char* name, char* val, BOOL_t isTotalRow, BOOL_t isValTime, char* COLID);
extern void HC_ADD_STAT_TABLE_TO_WALL(int handle, char* wallID, char* statId);
extern void HC_SHOW_STAT_WALL(int handle, char* wallID);
extern void HC_CREATE_INCREMENTAL_CASH_ANIM(int handle, char* wallID, char* stepID);
extern void HC_ADD_INCREMENTAL_CASH_WON_STEP(int handle, char* wallID, char* stepID, int startDol, int finishDol, char* topTxt, char* bottomTxt, char* handStat, BOOL_t handico, int soundType);
extern void HC_ADD_INCREMENTAL_CASH_TO_WALL(int handle, char* wallID, char* stepID);
extern void HC_ADD_JP(int handle, char* wallID, int pts, BOOL_t xAlign);
extern void HC_ADD_RP_AND_BAR(int handle, char* wallID, int repGained, int startRep, int minRepForRank, int maxRepForRank, int currentRank, int nextRank, char* rnk1txt, char* ranktxt2);
extern void HC_ADD_CASH_DEDUCTION(int handle, char* wallID, char* title, char* desc, int val);
extern void HC_ADD_CASH_WON_TO_WALL(int handle, char* wallID, char* statLbl, int finVal, int startVal, BOOL_t xAlign, BOOL_t isRawTxt);
extern void HC_ADD_CASH_TO_WALL(int handle, char* wallID, float val, BOOL_t xAlign);
extern void HC_CLEANUP(int handle, char* wallID);
extern void HC_CREATE_SEQUENCE(int handle, char* wallID, int sfxID, int colourId);


extern HeistCelebHandle* EX_HC_PASS(int potentTake, int actualTake, float cut = -1, int startRep = 0, int currentRank = 0, int nextRank = 0, int rpToNextRank = 0, int rpGained = 0, int jp = 0);
extern HeistCelebHandle* EX_HC_FAILED(int startRep, int currentRank, int nextRank, int minNext, int maxNext, int rpToNext, int rpGain, int jp);



/*
* MidSizedMessage Scaleform Commands (Does Not Include Native Scaleform Pushs rather a wrapper around it.
*/

extern MidSizedHandle* mz_Create(char* bigTxt, char* descTxt, HudColour colour, BOOL_t useCondensed, BOOL_t useDarkerColour);
extern void mz_Destroy(MidSizedHandle* handle);
extern void mz_ApplyBridgeAndKnife(MidSizedHandle* handle, char* info, int totalTodo, int totalComplete);
extern void mz_Tick(MidSizedHandle* scl);

/*
* MP_BIG_MESSAGE_FREEMODE Scaleform (Internals Not Documented For Final Release) 
*/

typedef enum VehicleHash {
	VEH_HASH_BUZZARD = 788747387,
	VEH_HASH_NOKOTA = 1036591958,
	VEH_HASH_SAVAGE = 4212341271,
	VEH_HASH_LAZER = 3013282534,
	VEH_HASH_HUNTER = 4252008158,
	VEH_HASH_AKULA = 1181327175,
	VEH_HASH_HYDRA = 970385471,
	VEH_HASH_PYRO = 2908775872,
	VEH_HASH_MOLOTOK = 1565978651,
	VEH_HASH_THRUSTER = 1489874736,
	VEH_HASH_ROGUE = 3319621991
}IcoVehHash;

extern BigMsgHandle* BIGMSG_Create(char* bigText, char* msgTxt);
extern void BIGMSG_ApplyWeapon(BigMsgHandle* handle, char* weapName, int weapHash, char* weapDesc);
extern void BIGMSG_ApplyPlane(BigMsgHandle* handle, char* planeName, VehicleHash planeHash);
extern void BIGMSG_Tick(const BigMsgHandle* handle);
extern void BIGMSG_Free(BigMsgHandle* handle);

extern void __MPBMF_SHOW_BUSTED_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_WASTED_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_RANKUP_MP_MESSAGE(int handle, char* bigText);
extern void __MPBMF_SHOW_CREW_RANKUP_MP_MESSAGE(int handle, char* titleStr, char* msgStr, int rankNumber, char* emblemTXD, char* emblemTXN, int alpha);
extern void __MPBMF_SHOW_LOCKED_UP_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_MISSION_END_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_MISSION_FAILED_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_MISSION_PASSED_MESSAGE(int handle);
extern void __MPBMF_SHOW_WEAPON_PURCHASED(int handle, char* bigMsg, char* weaponName, int weaponHash, char* weaponDesc, int alpha);
extern void __MPBMF_SHOW_PLANE_MESSAGE(int handle, char* bigMessage, char* planeName, int planeHash);
extern void __MPBMF_SHOW_TERRITORY_CHANGE_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_MP_MESSAGE_TOP(int handle);
extern void __MPBMF_SHOW_CENTERED_MP_MESSAGE_LARGE(int handle);
extern void __MPBMF_SHOW_CENTERED_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_CENTERED_TOP_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_BIG_MP_MESSAGE_WITH_STRAP_AND_RANK(int handle);
extern void __MPBMF_SHOW_BIG_MP_MESSAGE_WITH_STRAP(int handle);
extern void __MPBMF_SHOW_BIG_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_SHARD_CENTERED_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_SHARD_CENTERED_MP_MESSAGE_LARGE(int handle);
extern void __MPBMF_SHOW_SHARD_WASTED_MP_MESSAGE(int handle, char* bigTxt, char* msgTxt, HudColour colID, BOOL_t unusedBool, BOOL_t darkenBackground);
extern void __MPBMF_SHOW_SHARD_CENTERED_TOP_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_SHARD_RANKUP_MP_MESSAGE(int handle);
extern void __MPBMF_SHOW_SHARD_CREW_RANKUP_MP_MESSAGE(int handle);


#undef MODE_LIMIT