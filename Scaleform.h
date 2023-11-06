#pragma once
#include "utils.h"
typedef void CelebHandle;
typedef void MidSizedHandle;
typedef enum {
	CM_INTRO = 0,
	CM_OUTRO = 1,
	CM_CUSTOM = 2
}CelebMode;
typedef enum CelebrationTypes {
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
extern CelebHandle* celeb_Intro_Create(
										char missionName[MODE_LIMIT],
										char missionType[MODE_LIMIT],
										char modeType[MODE_LIMIT],
										CelebrationTypes type,
										BOOL_t chalTextLabel,
										BOOL_t tarTypeTextLabel,
										BOOL_t modeLabelIsStringLiteral = TRUE_,
										int opacity = 0
);
#undef MODE_LIMIT