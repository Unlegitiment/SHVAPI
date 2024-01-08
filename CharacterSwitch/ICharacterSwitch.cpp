#include "ICharacterSwitch.h"
#include "../ScriptHookV/natives.h"
#include "../keyboard.h"
#include "../UI.h"
ICharacterSwitch::ICharacterSwitch(int oldPed, int newPed, ePlayerSwitchTypes playerSwitchType, signed flags) :
	m_Flags(flags),
	m_OldPed(oldPed),
	m_NewPed(newPed),
	m_JumpIndex(0),
	m_SwitchType(playerSwitchType)
{
	return;
}

void ICharacterSwitch::Start()
{
	
	STREAMING::START_PLAYER_SWITCH(m_OldPed, m_NewPed, m_Flags, m_SwitchType);
	
	while (STREAMING::IS_PLAYER_SWITCH_IN_PROGRESS()) {
		this->m_JumpIndex = STREAMING::GET_PLAYER_SWITCH_STATE();
		PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
		
		if(IsKeyJustUp(VK_ACCEPT)) this->End();
		UI_DrawText(util_IntToStr(m_JumpIndex), { 0.5F,0,0.5F,0 });
		WAIT(0);
	}
}

void ICharacterSwitch::End()
{
	STREAMING::STOP_PLAYER_SWITCH();
}
