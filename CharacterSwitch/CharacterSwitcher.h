#pragma once
#include "../ScriptHookV/types.h"
#include "CharacterSwitchNative.h"
/*Wrapper Class for Teleporting the player with Switches
Not A Single Instance. 
*/
class TeleportCameraSwitch{
public:
	enum SwitchState {
		SWITCH_PROG_STEP_1 = 1,
		SWITCH_PROG_STEP_2 = 2,
		SWITCH_PROG_STEP_3 = 3,
		SWITCH_PROG_TRANSITION = 8,
		SWITCH_PROG_DECENT = 10,
		SWITCH_PROG_FINALIZE = 12
	};
	TeleportCameraSwitch(Vector3 newPosition, signed flags);
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