#pragma once
#include <string>
#include "../CharacterSwitch/CTxd.h"
#include "../Scaleform/HUD_COLOUR.h"
using std::string;
class CVoteItem {
public:
	CVoteItem();
	CVoteItem(string title, CTxd txd, int rpMult, int cashMult, int apMult, HudColour iconCol);
	//enum TextureLoadType {

	//};
	//enum eIconType {

	//};
	string m_Title;
	CTxd m_TXD;
	bool m_bVerifType, m_bCheck, m_bDisabled;
	int m_rpMult, m_cashMult, m_apMult;
	HudColour m_iconCol;
private:
	
};