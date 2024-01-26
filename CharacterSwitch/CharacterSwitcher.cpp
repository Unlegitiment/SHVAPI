#include "CharacterSwitcher.h"
#include "../ScriptHookV/natives.h"
#include "../ScriptHookV/enums.h"
#include "../keyboard.h"
CTpSwitch::CTpSwitch(Vector3 newPosition, signed flags) :
	clonedPed(-1)
{
	this->m_WarpPosition = newPosition;
	this->m_tpFlags = flags;
}
/*
* Transfer thread? Or just use if statements and recursion?
*/

void CTpSwitch::Init()
{
	clonedPed = PED::CLONE_PED(PLAYER::PLAYER_PED_ID(), 0,0,1);
	ENTITY::SET_ENTITY_COORDS(clonedPed, this->m_WarpPosition.x, this->m_WarpPosition.y, this->m_WarpPosition.z, 1, 0, 0, 1);
	ENTITY::SET_ENTITY_VISIBLE(clonedPed, FALSE, 0);
	this->m_Native.Init(PLAYER::PLAYER_PED_ID(), clonedPed, ePlayerSwitchTypes::SWITCH_TYPE_LONG, m_tpFlags);
	this->m_Native.Start();
}

void CTpSwitch::SetupEstablishingShot(const char* wtv)
{
	this->m_Native.SetEstablishingShot(wtv);
}

void CTpSwitch::Tick()
{
	if (this->m_Native.GetSwitchState() == m_Native.SWITCH_PROG_TRANSITION) {
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), this->m_WarpPosition.x, this->m_WarpPosition.y, this->m_WarpPosition.z, 1, 0, 0, 1);
	}
	if (this->m_Native.GetSwitchState() == m_Native.SWITCH_PROG_DECENT) {
		PED::DELETE_PED(&this->clonedPed);
		m_Native.sm_IsSwitchActive = FALSE;
	}
#ifdef TEST
	if (IsKeyJustUp(VK_ADD)) { // BAIL CONDITION ( TEST ) 
		m_Native.Stop(true);
	}
#endif
}

bool CTpSwitch::isTeleportActive()
{
	return this->m_Native.isSwitchInProgress();
}