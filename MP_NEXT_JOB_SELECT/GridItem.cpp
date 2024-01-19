#include "GridItem.h"

CVoteItem::CVoteItem() :
	m_Title		("Title"),
	m_TXD		("",""),
	m_rpMult	(2),
	m_cashMult	(2),
	m_apMult	(2),
	m_iconCol	(HUD_COLOUR_BLACK),
	m_bCheck	(false),
	m_bVerifType(false),
	m_bDisabled	(false)
{
}

CVoteItem::CVoteItem(string title, CTxd txd, int rpMult, int cashMult, int apMult, HudColour iconCol)
	: m_Title(title),
	m_TXD(txd),
	m_rpMult(rpMult),
	m_cashMult(cashMult),
	m_apMult(apMult),
	m_iconCol(iconCol),
	m_bCheck(false),
	m_bVerifType(false),
	m_bDisabled(false)
{
}
