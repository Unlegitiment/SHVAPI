#pragma once
#include <string>
#include "../../ScriptHookV/types.h"
/*
* This will act as a top part of the menu. In relative terms its basically the banner for the menu.
*/
class CMenuHeader {
public:
	CMenuHeader(CRGBA solidBackground);
	CMenuHeader(std::string txd);
private:
	
	std::string& menuTXD;
	CRGBA SolidRGBAColor;
	std::string& mainStr;
	
	std::string menuItems;
};
class CMenuHeaderController {
public:
	CMenuHeaderController(CMenuHeader header);
	void Update(); 
	CVector2& FetchPosition();

};
class CMenuHView {
	void Draw();


};