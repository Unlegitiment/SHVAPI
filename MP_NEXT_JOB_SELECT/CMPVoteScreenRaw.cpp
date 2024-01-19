#include "CMPVoteScreenRaw.h"

CMPVoteScreenRaw::CMPVoteScreenRaw():
	CBaseScaleform("MP_NEXT_JOB_SELECTION")
{

}
void CMPVoteScreenRaw::SET_TITLE(string sTitle, string sVotes)
{
	BeginFunction("SET_TITLE");
	LitStrPush(sTitle);
	LitStrPush(sVotes);
	EndFunction();
}

void CMPVoteScreenRaw::SHOW_PLAYER_VOTE(int i, string sGamerName, int r, int g, int b)
{
	BeginFunction("SHOW_PLAYER_VOTE");
	IntegerPush(i);
	LitStrPush(sGamerName);
	IntegerPush(r);
	IntegerPush(g);
	IntegerPush(b);
	EndFunction();
}

void CMPVoteScreenRaw::SET_GRID_ITEM(int i, string sTitle, string sTXD, string sTXN, int textureLoadType, int verifiedType, int eIcon, int bCheck, int rpMult, int cashMult, int bDisabled, int iconCol, int apMult)
{
	BeginFunction("SET_GRID_ITEM");
	IntegerPush(i);
	LitStrPush(sTitle);
	LitStrPush(sTXD);
	LitStrPush(sTXN);
	IntegerPush(textureLoadType);
	IntegerPush(verifiedType);
	IntegerPush(eIcon);
	IntegerPush(bCheck);
	IntegerPush(rpMult);
	IntegerPush(cashMult);
	IntegerPush(bDisabled);
	IntegerPush(iconCol);
	IntegerPush(apMult);
	EndFunction();
}

void CMPVoteScreenRaw::SET_GRID_ITEM_VOTE(int i, int iNumVotes, int voteBGColour, int bShowCheckMark, int bFlashBG)
{
	BeginFunction("SET_GRID_ITEM_VOTE");
	IntegerPush(i);
	IntegerPush(iNumVotes);
	IntegerPush(voteBGColour);
	IntegerPush(bShowCheckMark);
	IntegerPush(bFlashBG);
	EndFunction();
}

void CMPVoteScreenRaw::SET_SELECTION(int i, string sTitle, string sDetails, int bHideHighlight)
{
	BeginFunction("SET_SELECTION");
	IntegerPush(i);
	LitStrPush(sTitle);
	LitStrPush(sDetails);
	IntegerPush(bHideHighlight);
	EndFunction();
}

void CMPVoteScreenRaw::SET_HOVER(int itemIndex, int hideHover)
{
	BeginFunction("SET_HOVER");
	IntegerPush(itemIndex);
	IntegerPush(hideHover);
	EndFunction();
}

void CMPVoteScreenRaw::SET_DETAILS_ITEM(int detailIndex)
{
	BeginFunction("SET_DETAILS_ITEM");
	IntegerPush(detailIndex);
	EndFunction();
}

void CMPVoteScreenRaw::SET_LOBBY_LIST_VISIBILITY(int bShowList)
{
	BeginFunction("SET_LOBBY_LIST_VISIBILITY");
	IntegerPush(bShowList);
	EndFunction();
}

void CMPVoteScreenRaw::SET_LOBBY_LIST_DATA_SLOT()
{
	BeginFunction("SET_LOBBY_LIST_DATA_SLOT");
	EndFunction();
}

void CMPVoteScreenRaw::UPDATE_LOBBY_LIST_DATA_SLOT()
{
	BeginFunction("UPDATE_LOBBY_LIST_DATA_SLOT");
	EndFunction();
}

void CMPVoteScreenRaw::DISPLAY_LOBBY_LIST_VIEW()
{
	BeginFunction("DISPLAY_LOBBY_LIST_VIEW");
	EndFunction();
}

void CMPVoteScreenRaw::SET_LOBBY_LIST_HIGHLIGHT()
{
	BeginFunction("SET_LOBBY_LIST_HIGHLIGHT");
	EndFunction();
}

void CMPVoteScreenRaw::SET_LOBBY_LIST_DATA_SLOT_EMPTY()
{
	BeginFunction("SET_LOBBY_LIST_DATA_SLOT_EMPTY");
	EndFunction();
}

void CMPVoteScreenRaw::INIT_LOBBY_LIST_SCROLL()
{
	BeginFunction("INIT_LOBBY_LIST_SCROLL");
	EndFunction();
}

void CMPVoteScreenRaw::SET_LOBBY_LIST_SCROLL()
{
	BeginFunction("SET_LOBBY_LIST_SCROLL");
	EndFunction();
}

void CMPVoteScreenRaw::CLEANUP_MOVIE()
{
	BeginFunction("CLEANUP_MOVIE");
	EndFunction();
}

void CMPVoteScreenRaw::SET_ITEMS_GREYED_OUT(int value)
{
	BeginFunction("SET_ITEMS_GREYED_OUT");
	IntegerPush(value);
	EndFunction();
}

void CMPVoteScreenRaw::MP_NEXT_JOB_SELECTION()
{
	BeginFunction("MP_NEXT_JOB_SELECTION");
	EndFunction();
}

void CMPVoteScreenRaw::INITIALISE(int mc)
{
	BeginFunction("INITIALISE");
	IntegerPush(mc);
	EndFunction();
}

void CMPVoteScreenRaw::TXD_HAS_LOADED(string sTXD, int& success, int uID)
{
	BeginFunction("TXD_HAS_LOADED");
	LitStrPush(sTXD);
	IntegerPush(success);
	IntegerPush(uID);
	EndFunction();
}

void CMPVoteScreenRaw::TXD_ALREADY_LOADED(string sTXD, int uID)
{
	BeginFunction("TXD_ALREADY_LOADED");
	LitStrPush(sTXD);
	IntegerPush(uID);
	EndFunction();
}

void CMPVoteScreenRaw::ADD_TXD_REF_RESPONSE(string sTXD, int uID, int success)
{
	BeginFunction("ADD_TXD_REF_RESPONSE");
	LitStrPush(sTXD);
	IntegerPush(uID);
	IntegerPush(success);
	EndFunction();
}
#include "../ScriptHookV/natives.h"
void CMPVoteScreenRaw::Draw()
{
	GRAPHICS::DRAW_SCALEFORM_MOVIE(this->m_Scaleform, 0.5, 0.5, 1, 1, 255, 255, 255, 255, 0);
}
