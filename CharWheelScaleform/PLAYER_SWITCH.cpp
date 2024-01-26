#include "PLAYER_SWITCH.h"
#include "../ScriptHookV/natives.h"
CPLAYER_SWITCH::CPLAYER_SWITCH()
	: CBaseScaleform("PLAYER_SWITCH")
{

}

void CPLAYER_SWITCH::SET_SWITCH_VISIBLE(bool vis)
{
	BeginFunction("SET_SWITCH_VISIBLE");
	IntegerPush(vis);
	EndFunction();
}

void CPLAYER_SWITCH::SET_SWITCH_SLOT(int index, int stateEnum, int charEnum, bool selected, std::string pedheadshot_txt_string)
{
	BeginFunction("SET_SWITCH_SLOT");
	IntegerPush(index);
	IntegerPush(stateEnum);
	IntegerPush(charEnum);
	IntegerPush(selected);
	LitStrPush(pedheadshot_txt_string);
	EndFunction();
}

void CPLAYER_SWITCH::SET_MULTIPLAYER_HEAD(std::string _newTXD)
{
	BeginFunction("SET_MULTIPLAYER_HEAD");
	LitStrPush(_newTXD);
	EndFunction();
}

void CPLAYER_SWITCH::SET_SWITCH_HINTED(int index, bool hinted)
{
	BeginFunction("SET_SWITCH_HINTED");
	IntegerPush(index);
	IntegerPush(hinted);
	EndFunction();
}

void CPLAYER_SWITCH::SET_SWITCH_HINTED_ALL(bool hinted0, bool hinted1, bool hinted2, bool hinted3)
{
	BeginFunction("SET_SWITCH_HINTED_ALL");
	IntegerPush(hinted0);
	IntegerPush(hinted1);
	IntegerPush(hinted2);
	IntegerPush(hinted3);
	EndFunction();
}

void CPLAYER_SWITCH::SET_PLAYER_DAMAGE(int index, bool bVisible, bool bFlash)
{
	BeginFunction("SET_PLAYER_DAMAGE");
	IntegerPush(index);
	IntegerPush(bVisible);
	IntegerPush(bFlash);
	EndFunction();
}

void CPLAYER_SWITCH::SET_SWITCH_COUNTER_ALL(int count0, int count1, int count2, int count3)
{
	BeginFunction("SET_SWITCH_COUNTER_ALL");
	IntegerPush(count0);
	IntegerPush(count1);
	IntegerPush(count2);
	IntegerPush(count3);
	EndFunction();
}

void CPLAYER_SWITCH::SET_PLAYER_SELECTED(int sindex)
{
	BeginFunction("SET_PLAYER_SELECTED");
	IntegerPush(sindex);
	EndFunction();
}

void CPLAYER_SWITCH::SET_MP_LABEL(std::string str)
{
	BeginFunction("SET_MP_LABEL");
	LitStrPush(str);
	EndFunction();
}
int CPLAYER_SWITCH::GET_SWITCH_SELECTED_NO_HIJACK() {
	BeginFunction("GET_SWITCH_SELECTED");
	int retHandle = EndFunctionWithReturn();
	if (!this->isScaleformReadyToReturn(retHandle)) { WAIT(0); }
	return this->GetScaleformValueInt(retHandle);
}
int CPLAYER_SWITCH::GET_SWITCH_SELECTED()
{
	BeginFunction("GET_SWITCH_SELECTED");
	int retHandle = EndFunctionWithReturn();
	while (!this->isScaleformReadyToReturn(retHandle)) {
		WAIT(0);
	}
	return (this->GetScaleformValueInt(retHandle));
}

void CPLAYER_SWITCH::ADD_TXD_REF_RESPONSE(std::string txd, int uniqueStr, bool success)
{
	BeginFunction("ADD_TXD_REF_RESPONSE");
	LitStrPush(txd);
	IntegerPush(uniqueStr);
	IntegerPush(success);
	EndFunction();
}

void CPLAYER_SWITCH::debug()
{
	BeginFunction("debug");
	EndFunction();
}

void CPLAYER_SWITCH::Draw()
{
	GRAPHICS::DRAW_SCALEFORM_MOVIE(m_Scaleform, 0.5, 0.5, 1, 1, 255, 255, 255, 255, 0);
}
