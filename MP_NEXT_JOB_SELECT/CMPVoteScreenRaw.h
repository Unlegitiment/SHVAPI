#pragma once
#include "../Scaleform/BaseScaleform.h"
#include <string>
using std::string;
class CMPVoteScreenRaw : protected CBaseScaleform {
public:
	CMPVoteScreenRaw();
	void SET_TITLE(string sTitle, string sVotes);
	void SHOW_PLAYER_VOTE(int i, string sGamerName, int r, int g, int b);
	void SET_GRID_ITEM(int i, string sTitle, string sTXD, string sTXN, int textureLoadType, int verifiedType, int eIcon, int bCheck, int rpMult, int cashMult, int bDisabled, int iconCol, int apMult);
	void SET_GRID_ITEM_VOTE(int i, int iNumVotes, int voteBGColour, int bShowCheckMark, int bFlashBG);
	void SET_SELECTION(int i, string sTitle, string sDetails, int bHideHighlight);
	void SET_HOVER(int itemIndex, int hideHover);
	void SET_DETAILS_ITEM(int detailIndex);
	void SET_LOBBY_LIST_VISIBILITY(int bShowList);
	void SET_LOBBY_LIST_DATA_SLOT();
	void UPDATE_LOBBY_LIST_DATA_SLOT();
	void DISPLAY_LOBBY_LIST_VIEW();
	void SET_LOBBY_LIST_HIGHLIGHT();
	void SET_LOBBY_LIST_DATA_SLOT_EMPTY();
	void INIT_LOBBY_LIST_SCROLL();
	void SET_LOBBY_LIST_SCROLL();
	void CLEANUP_MOVIE();
	void SET_ITEMS_GREYED_OUT(int value);
	void Draw();

protected: // No state change here. 
private://All methods that are either internal or don't work with the program properly.
	void MP_NEXT_JOB_SELECTION();
	void INITIALISE(int mc);
	void TXD_HAS_LOADED(string sTXD, int& success, int uID);
	void TXD_ALREADY_LOADED(string sTXD, int uID);
	void ADD_TXD_REF_RESPONSE(string sTXD, int uID, int success);
};