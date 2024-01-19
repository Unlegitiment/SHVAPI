#include "PlayerSwitchWrapper.h"
#include "../ScriptHookV/natives.h"
#include "../UI.h"
PlayerSwitchWrapper g_Switcher = PlayerSwitchWrapper();
PlayerSwitchWrapper::PlayerSwitchWrapper() :
	m_rawSwitch(CPLAYER_SWITCH()),
	m_selected(-1),
	m_SPCharacterInfo{ CCharacterInfoSP(), CCharacterInfoSP(), CCharacterInfoSP() },
	m_MPCharacterInfo()
{

}


int PlayerSwitchWrapper::GetSwitchIndex()
{
	return -2;
}
#include "../keyboard.h"
void PlayerSwitchWrapper::Tick()
{
	NativeTick();
	/*
	* Perform mouse logic on different thread.
	*/
	if (IsKeyJustUp(VK_ADD)) {
		m_selected++;
	}
	if (IsKeyJustUp(VK_DIVIDE)) {
		m_selected--;
	}
	if (m_selected > 3) {
		m_selected = -1;
	}
	if (m_selected < -1) {
		m_selected = 3;
	}
}
void PlayerSwitchWrapper::Update() {
	Tick();
}

void PlayerSwitchWrapper::NativeTick()
{
	this->m_rawSwitch.SET_SWITCH_VISIBLE(false);
	this->m_rawSwitch.SET_PLAYER_SELECTED(m_selected);	//SLOT	//state					//char		//selected					//headtxd
	this->m_rawSwitch.SET_SWITCH_SLOT(CCharacterInfo::ST_MICHAEL, m_SPCharacterInfo[0].state, CCharacterInfo::CE_MICHAEL, m_SPCharacterInfo[m_selected].isSelected, "");
	this->m_rawSwitch.SET_SWITCH_SLOT(CCharacterInfo::ST_FRANKLIN, m_SPCharacterInfo[1].state, CCharacterInfo::CE_FRANKLIN, m_SPCharacterInfo[m_selected].isSelected, "");
	this->m_rawSwitch.SET_SWITCH_SLOT(CCharacterInfo::ST_TREVOR, m_SPCharacterInfo[2].state, CCharacterInfo::CE_TREVOR, m_SPCharacterInfo[m_selected].isSelected, "");
	this->m_rawSwitch.SET_SWITCH_SLOT(CCharacterInfo::ST_MP_SLOT, m_MPCharacterInfo.state, CCharacterInfo::CE_ONLINE, m_MPCharacterInfo.isSelected, "");
	this->m_rawSwitch.SET_MP_LABEL(m_MPLABEL); //Depricated
	this->m_rawSwitch.SET_SWITCH_HINTED_ALL(
		m_SPCharacterInfo[0].isHinted,
		m_SPCharacterInfo[1].isHinted,
		m_SPCharacterInfo[2].isHinted,
		m_MPCharacterInfo.isHinted);
	this->m_rawSwitch.SET_PLAYER_DAMAGE(0, m_SPCharacterInfo[0].Damage.notify, m_SPCharacterInfo[0].Damage.flash);
	this->m_rawSwitch.SET_PLAYER_DAMAGE(1, m_SPCharacterInfo[1].Damage.notify, m_SPCharacterInfo[1].Damage.flash);
	this->m_rawSwitch.SET_PLAYER_DAMAGE(2, m_SPCharacterInfo[2].Damage.notify, m_SPCharacterInfo[2].Damage.flash);
	this->m_rawSwitch.SET_SWITCH_COUNTER_ALL(
		m_SPCharacterInfo[0].missionCounter,
		m_SPCharacterInfo[1].missionCounter,
		m_SPCharacterInfo[2].missionCounter,
		0);

	this->m_rawSwitch.SET_SWITCH_VISIBLE(true);
	this->m_rawSwitch.Draw();
}







//Char enum is mean to represent the character's displayed.
// 0 is michael
// 1 is Trevor
// 2 is Franklin
// 3 is Online
// 4,5,6 is Chop However in different spaces
// 7,8,9,10 Chop with different colours
//state enum is the locked requirement between each.
// 1 is Unlocked
// 2 is Unable To swap 
// 3 is Locked/Character Unknown.
// For the online character however this Changes:
// 0,1,2 is a Nullcharacter with a label type thing
// 3 is a Nullcharacter with out the label.
//Selected is A lie in a sorta way.
//Selected is actually not an index instead it is the sector around the player
//Head txd Might work but not sure.

