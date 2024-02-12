#pragma once
#include <string>
#include "../../../ScriptHookV/types.h"
#include "./CMTxd.h"
/*
* This will act as a top part of the menu. In relative terms its basically the banner for the menu.
*/
class CMenuHeader {
public:
	CMenuHeader(CRGBA solidBackground);
	CMenuHeader(std::string txd);
private:
	CMTxd& menuTXD;
	CRGBA& SolidRGBAColor;
	std::string& mainStr;
	std::string& menuItems;
	std::string& currentMenu; // 
};
class CMenuHView {
public:
	void DrawTxd(std::string& mainStr, std::string& currentMenu, std::string& menuIndex, CMTxd& color, CVector2& drawPos);
	void DrawCol(std::string& mainStr, std::string& currentMenu, std::string& menuIndex, CRGBA& color, CVector2& drawPos);
};
class CMenuHeaderController {
public:
	CMenuHeaderController(CMenuHeader& _header, CMenuHView _view);
	void Update(); 
private:
	CMenuHView& view;
	CMenuHeader& header;
};
