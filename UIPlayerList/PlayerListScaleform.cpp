#include "PlayerListScaleform.h"
#include "../ScriptHookV/natives.h"
void CPlayerListScaleform::CLEAN()
{
    GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->handle);
}
CPlayerListScaleform::CPlayerListScaleform()
{
	this->handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE(this->SCALEFORM_TITLE_NAME.c_str());
    while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->handle)) {
        WAIT(0);
    }
    return;
}

void CPlayerListScaleform::DEBUG()
{
    return;
}

void CPlayerListScaleform::COLLAPSE()
{
    return;
}

void CPlayerListScaleform::SET_ICON(int index, int iconEnum, int rank)
{
    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->handle, "SET_ICON");
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(index);
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(iconEnum);
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(rank);
    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CPlayerListScaleform::DISPLAY_MIC()
{
    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->handle,"DISPLAY_MIC");
    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CPlayerListScaleform::SET_TITLE(string str, string str2, int icon)
{
    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->handle, "SET_TITLE");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(str.c_str());
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(str2.c_str());
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(icon);
    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CPlayerListScaleform::SET_DATA_SLOT(int viewIndex, int rank, const char* name, eHudColours colour, const char* crewTag, JPTypes jpType, const char* txdDict, const char* txdImg, char* relationToViewer, PlayerListIcons icon, int mugshotTxd, int jp)
{
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->handle,"SET_DATA_SLOT");

    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(viewIndex); // player index [0]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(rank); //rank [1]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(name); //name [2]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT((int)colour); // color [3]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT((int)icon);// icon image (rank globe, death X)
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(mugshotTxd); //mugshot txt[5]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(jp); //jp[6
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(crewTag); // crew after 4th index ? [7]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT((int)jpType); // Does JP appear [8]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(txdDict);// txddict[9]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(txdImg);  //txdimg[10]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(relationToViewer); // Friend Symbol (MINI-TEXT) [11]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(1); //UNK?
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(2); //UNK?
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(3); //UNK?

	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CPlayerListScaleform::UPDATE_SLOT(int viewIndex, int rank, const char* name, eHudColours colour, const char* crewTag, JPTypes jpType, const char* txdDict, const char* txdImg, char* relationToViewer, PlayerListIcons icon, int mugshotTxd, int jp)
{
    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->handle, "UPDATE_SLOT");

    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(viewIndex); // player index [0]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(rank); //rank [1]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(name); //name [2]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(116); // color [3]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(65);// icon image (rank globe, death X)
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(viewIndex); //mugshot txt[5]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(jp); //jp[6
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(crewTag); // crew after 4th index ? [7]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT((int)jpType); // Does JP appear [8]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING("");// txddict[9]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING("");  //txdimg[10]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(relationToViewer); // Friend Symbol (MINI-TEXT) [11]
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(1); //UNK?

    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void CPlayerListScaleform::DISPLAY_VIEW()
{
    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->handle, "DISPLAY_VIEW");
    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CPlayerListScaleform::SET_DATA_SLOT_EMPTY(int viewIndex, int itemIndex)
{
    GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->handle, "SET_DATA_SLOT_EMPTY");
    GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(viewIndex);
    GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CPlayerListScaleform::TXD_HAS_LOADED(const char* textDict, bool success, int uuid)
{
    return;
}

void CPlayerListScaleform::TXD_ALREADY_LOADED(const char* textdict, int uuid)
{
    return;
}

void CPlayerListScaleform::ADD_TXT_REF_RESPONSE(const char* textdict, int uuid, bool success)
{
    return;
}

int CPlayerListScaleform::getHandle()
{
	return this->handle;
}
