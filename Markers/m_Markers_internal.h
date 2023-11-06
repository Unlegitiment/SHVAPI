#pragma once
#include "..\Utils.h"
#define MAX_BUFF 64
typedef void(*MissionCallback)(void*);
typedef struct {
	char name[MAX_BUFF];
	int reqPlayers;
	int raw_rating;
}MissionData;
#undef MAX_BUFF
typedef enum e_job_t {
	jType_Mission,
	jType_AirRace,
	jType_HSWRace,
	jType_LandRace,
	jType_BoatRace,
	jType_Rally,
	jType_TargetAssault,
	jType_StuntRace,
	jType_BikeRace,
	jType_OpenWheelRace,
	jType_CommSeries,
	jType_TeamDeathMatch,
	jType_DeathMatch,
	jType_VehDeathMatch,
	jType_ArenaDeathMatch,
	jType_GTACap,
	jType_ContendCap,
	jType_HoldCap,
	jType_RaidCap,
	jType_LTS,
	jType_KOTH,
	jType_Survival,
	jType_Versus,
	jType_Adversary,
	jType_Parachute,
	jType_OffVerfied
}JobType;
typedef struct mission_t {
	Vector3_t mLoc;
	Vector3_t mDir;
	Vector3_t mRot;
	Vector3_t mScale;
	RGBA_t rgba;
	enum eMarkerType mType;
	JobType jType;
	MissionData* mData;
	mission_t* internalCircle;
	MissionCallback mCallback;
}MissionMarker;

