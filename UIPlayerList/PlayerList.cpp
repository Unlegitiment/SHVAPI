#include "PlayerList.h"
#include "../ScriptHookV/natives.h"
#include "../UI.h"
CList<CListPlayer> CPlayerList::m_Players = CList<CListPlayer>();

//CPlayerList& CPlayerList::GetInstance()
//{
//	
//	return CPlayerList::m_Instance;
//}

CPlayerList::CPlayerList(CListPlayer& player) :
	CPlayerList()
{
	this->m_Players.add(player);
	return;
}
void CPlayerList::Update()
{
	this->i_Draw();
}
CPlayerList::CPlayerList() :
	m_UIPlayerList(new CPlayerListScaleform)
{

}
void CPlayerList::setupDraw() {
	m_UIPlayerList->SET_TITLE("GTA Online (Public, " + std::to_string(this->m_Players.getSize()) + ")", "(1/2)", 24);
	for (int i = 0; i < m_Players.getSize(); i++) {
		CListPlayer curPlayer = this->m_Players.getList()[i];
		this->m_UIPlayerList->SET_DATA_SLOT_EMPTY(i,0);
		m_UIPlayerList->SET_DATA_SLOT(i, curPlayer.m_Rank.m_Rank, curPlayer.m_Name.c_str(), (eHudColours)116, curPlayer.m_CrewTag.toStr().c_str(), CPlayerListScaleform::JPTypes::JPSYMBOL, "", "", (char*)curPlayer.relationtoPlayer.c_str(), CPlayerListScaleform::PlayerListIcons::RANK_FREEMODE, i + 1, 15);
		m_UIPlayerList->SET_ICON(i, 66, 66);
	}
	m_UIPlayerList->DISPLAY_VIEW(); //make it ready for draw
	
}

void CPlayerList::i_Draw()
{
	this->setupDraw();
	GRAPHICS::DRAW_SCALEFORM_MOVIE(this->m_UIPlayerList->getHandle(), 0.16,0.4,0.32,0.68,255,255,255,255,0);
	return;
}

