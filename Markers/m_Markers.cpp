#define _CRT_SECURE_NO_WARNINGS
#include "..\Markers.h"
#include "..\utils.h"
MissionMarker* m_CreateMarker(Vector3_t mLoc,Vector3_t mDir,Vector3_t mRot,Vector3_t mScale,Vector3_t switchFinalLoc,RGBA_t* rgba,enum eMarkerType mType,JobType jType,MissionData* mData,MissionCallback mSrc){
	MissionMarker* x = (MissionMarker*)malloc(sizeof(MissionMarker));
	if (x == NULL) return NULL;
	x->mLoc = mLoc;
	x->mDir = mDir;
	x->mRot = mRot;
	x->mScale = mScale;
	x->rgba = *rgba;
	x->jType = jType;
	x->mType = mType;
	return x;
}
void m_ChangeLocation(MissionMarker* marker, Vector3_t newLocation)
{
	marker->mLoc = newLocation;
	return;
}
MissionData* md_Create(char* name, int reqPlayers, int raw_rating)
{
	MissionData* d = (MissionData*)malloc(sizeof(MissionData));
	if (d == NULL) return NULL;
	strncpy(d->name, name, sizeof(d->name));
	d->reqPlayers = reqPlayers;
	d->raw_rating = raw_rating;
	return d;
}
void md_Apply(MissionMarker* marker, MissionData* Data)
{
	marker->mData = Data;
}
void m_Destroy(MissionMarker* ptr) {
	free(ptr->mData);
	free(ptr);
	return;
}

#define NATIVE_H
#ifdef NATIVE_H
#include "E:\ScriptHookV\inc\natives.h"
/*
* @brief -Draws the Marker Data if within proximity 
  @brief -Default Prox = 7 units;
* @param MissionData * const mD = The Mission Data to Print
* @param int proximity = Default 7 however increases draw radius of scaleform.
*/
void md_DisplayMarkerData(MissionData* const mD, int proximity) {
	
}
//Draws the marker to the screen
void m_DisplayMarker(MissionMarker* const marker) {
	
}
// Likely will do both operations of previous two functions within one.
void m_DisplayMarkerEx(MissionMarker* const marker, MissionData* mD) {

}
#endif
#undef NATIVE_H