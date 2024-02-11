#pragma once
#include "../../GenericList/CList.h"
#include "MenuHeader.h"
#include "CMenuItem.h"
#include "../ButtonDraw/CButtonUI.h"
#define _BLIST_ CList<CBaseMenuItem> 
class CMenuUI {
public:
	CMenuUI();
	void addButton(CButtonUI _button);
	CButtonUI getButtonAtIndex(int index);
	bool isIndexValid();
	
private:

	_BLIST_ _bList_;
	CMenuHeader header;
};
#undef _BLIST_