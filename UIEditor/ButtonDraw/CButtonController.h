#pragma once
#include "CButtonUI.h"
class CButtonView { //Current display to user. 
public:
	CButtonView();
	void Draw( CButtonUI& const button);
private:
};
class CButtonMgr {
public:
	CButtonMgr(CButtonUI& buttonToSetup);
	//CButtonMgr(const CBox& box, const CTextUI* ltextUI);
	void handleMouse(CRGBA highlightColour, float mousePosX, float mousePosY);
	void UpdateDrawPos(CVector2 drawPosition);
	void UpdateButtonAtIndex(int index);
	void SetHeight(float _height);
	void SetWidth(float _width);
	void Update(); 
private:
	CButtonUI& button;
	CButtonView view;
};