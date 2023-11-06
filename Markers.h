#pragma once
//#include "E:\ScriptHookV\inc\types.h"
#include "Markers/m_Markers_internal.h"
extern MissionMarker* m_CreateMarker(
	Vector3_t mLoc,
	Vector3_t mDir,
	Vector3_t mRot,
	Vector3_t mScale,
	Vector3_t switchFinalLoc,
	RGBA_t* rgba,
	enum eMarkerType mType,
	JobType jType,
	MissionData* mData,
	MissionCallback mSrc
);
//extern void m_Destroy(MissionMarker* mPtr, size_t size); - REMOVAL: Purpose changed.
extern void m_ChangeLocation(MissionMarker* marker, Vector3_t newLocation);
extern MissionData* md_Create(char* name, int reqPlayers, int raw_rating);
extern void md_Apply(MissionMarker* marker, MissionData* Data); 
extern void m_Destroy(MissionMarker* ptr);
extern void md_DisplayMarkerData(MissionData* const mD, int proximity = 7);
extern void m_DisplayMarker(MissionMarker* const marker);
// Likely will do both operations of previous two functions within on
extern void m_DisplayMarkerEx(MissionMarker* const marker, MissionData* mD);