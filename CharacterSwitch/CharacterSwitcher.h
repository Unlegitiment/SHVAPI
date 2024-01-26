#pragma once
#include "../ScriptHookV/types.h"
#include "CharacterSwitchNative.h"
/*Wrapper Class for Teleporting the player with Switches
Not A Single Instance. 
*/
class CTpSwitch{
public:
	CTpSwitch(Vector3 newPosition, signed flags);
	void Init();
	void SetupEstablishingShot(const char* wtv);
	void Tick();
	bool isTeleportActive();
private:
	CCharSwitcherNATIVE m_Native = CCharSwitcherNATIVE::GetInstance();
	
	Vector3 m_WarpPosition;
	signed m_tpFlags;
	int clonedPed;
};