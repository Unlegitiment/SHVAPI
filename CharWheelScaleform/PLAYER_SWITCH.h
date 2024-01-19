#pragma once
#include "../CharacterSwitch/OnlineLoad.h"
/*
* Mapping for native functions
*/
class CPLAYER_SWITCH : private CBaseScaleform{
public:
	CPLAYER_SWITCH();
	void SET_SWITCH_VISIBLE(bool vis);
	void SET_SWITCH_SLOT(int index, int stateEnum, int charEnum, bool selected, std::string pedheadshot_txt_string)	;
	void SET_MULTIPLAYER_HEAD(std::string _newTXD);
	void SET_SWITCH_HINTED(int index, bool hinted);
	void SET_SWITCH_HINTED_ALL(bool hinted0, bool hinted1, bool hinted2, bool hinted3);
	void SET_PLAYER_DAMAGE(int index, bool bVisible, bool bFlash);
	void SET_SWITCH_COUNTER_ALL(int count0, int count1, int count2, int count3);
	void SET_PLAYER_SELECTED(int sindex);
	void SET_MP_LABEL(std::string str);
	int GET_SWITCH_SELECTED_NO_HIJACK();
	/// <summary>
	/// Gets Switch Index
	/// </summary>
	/// <remarks>
	/// Temporarily Hijacks main thread.
	/// </remarks>
	int GET_SWITCH_SELECTED();
	void ADD_TXD_REF_RESPONSE(std::string txd, int uniqueStr, bool success);
	void debug();
	void Draw();
private:
};