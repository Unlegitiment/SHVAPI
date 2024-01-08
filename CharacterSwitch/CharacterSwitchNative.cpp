#include "CharacterSwitchNative.h"
#include "../ScriptHookV/natives.h"
#include "string"
CCharSwitcherNATIVE CCharSwitcherNATIVE::sm_Instance				;
int					CCharSwitcherNATIVE::sm_OldPed			= 0		;
int					CCharSwitcherNATIVE::sm_NewPed			= 0		;
int					CCharSwitcherNATIVE::sm_SwitchState		= 0		;
int					CCharSwitcherNATIVE::sm_SwitchType		= 0		;
bool				CCharSwitcherNATIVE::sm_IsSwitchActive	= 0		;
std::string			CCharSwitcherNATIVE::sm_EstablishShot	= ""	;



int CCharSwitcherNATIVE::GetSwitchState()
{

	this->sm_SwitchState = STREAMING::GET_PLAYER_SWITCH_STATE();
	return this->sm_SwitchState;
}


void CCharSwitcherNATIVE::Init(int oldPed, int newPed, int SwitchType, signed flags)
{
	this->sm_IsSwitchActive		= FALSE;
	this->sm_NewPed				= newPed;
	this->sm_OldPed				= oldPed;
	this->sm_SwitchState		= 0;
	this->sm_SwitchType			= SwitchType;
	this->m_Flags				= flags;
}

void CCharSwitcherNATIVE::Start()
{
	STREAMING::START_PLAYER_SWITCH(sm_OldPed, sm_NewPed, m_Flags, sm_SwitchType);
	this->sm_IsSwitchActive = TRUE;
	this->sm_SwitchState	= STREAMING::GET_PLAYER_SWITCH_STATE();
	if (this->sm_EstablishShot.compare("") != 0) {
		STREAMING::SET_PLAYER_SWITCH_ESTABLISHING_SHOT(this->sm_EstablishShot.c_str());
	}
}
/*
* Quick dbg
*/
void CCharSwitcherNATIVE::StartWithParams(int oldPed, int newPed, int SwitchType, signed flags)
{
	STREAMING::START_PLAYER_SWITCH(oldPed, newPed, flags, SwitchType);
	this->sm_IsSwitchActive = TRUE;
	this->sm_SwitchState = STREAMING::GET_PLAYER_SWITCH_STATE();
}

void CCharSwitcherNATIVE::Stop(bool withClean)
{
	if (withClean) {
		PED::DELETE_PED(&this->sm_NewPed);
	}
	STREAMING::STOP_PLAYER_SWITCH();
	this->sm_IsSwitchActive = FALSE;
}

int CCharSwitcherNATIVE::GetIdealSwitch(float x1, float y1, float z1, float x2, float y2, float z2)
{
	STREAMING::GET_IDEAL_PLAYER_SWITCH_TYPE(x1, y1, z1, x2, y2, z2);
	return 0;
}

void CCharSwitcherNATIVE::SetEstablishingShot(std::string establishingShot)
{
	this->sm_EstablishShot = establishingShot;
	//STREAMING::SET_PLAYER_SWITCH_ESTABLISHING_SHOT(this->sm_EstablishShot.c_str());
}
