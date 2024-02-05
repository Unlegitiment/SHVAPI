#pragma once
#include "CButtonUI.h"
class CButtonView { //Current display to user. 
public:
	void Draw();
private:
};
class CButtonController {
public:
	CButtonController(CButtonUI buttonToSetup);
	CButtonController(const CBox& box, const CTextUI& ltextUI);
	void handleMouse(CRGBA highlightColour, float mousePosX, float mousePosY);
	void handleKeyboard(CRGBA highlightColour);
	void UpdateDrawPos(CVector2 drawPosition);
	void SetHeight(float height);
	void SetWidth(float width);
private:
	CButtonUI button;
	CButtonView view;
};