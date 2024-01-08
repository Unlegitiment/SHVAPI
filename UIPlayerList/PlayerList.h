#pragma once
#include "../GenericList/CList.h"
#include "./ListPlayer.h"
#include "PlayerListScaleform.h"
#include <vector>
/*
* Should be a Singleton but fuck it. For some reason causes a clash with ScriptHookV
* "FATAL: Can find native 0x11FE353CF9733E6F" ?
*/
class CPlayerList {
public:
	//static CPlayerList& GetInstance();
	void Update();
	CPlayerList();
	CPlayerList(CListPlayer& player);
	static CList<CListPlayer> m_Players;
	
private:
	void setupDraw();
	void i_Draw();

	CPlayerListScaleform* m_UIPlayerList;
	
	//static CPlayerList m_Instance;
};