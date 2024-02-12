#pragma once
#include "../../BoxDraw/CBoxUI.h" //Should reference Text Lib?
#include "../../TextDraw/Text.h"
#include "../Menu.h"
class CArrowButton {
public:
	enum eArrowBtn {
		AB_LEFT		= 1,
		AB_RIGHT	= 2,
		AB_UP		= 3,
		AB_DWN		= 4
	};
	CArrowButton(CVector2& drawPos, eArrowBtn arrowBtn);
	CArrowButton(CBox* box, CTextUI* text, CVector2 drawPos, eArrowBtn arrowBtn);
	CBox& GetBox();
	CTextUI& GetText();
	void SetText(CTextUI* _text);
	void SetBox(CBox* _box);
	~CArrowButton(); 
private:
	CBox*		box; 
	CTextUI*		text;
};
class CArrowView {
public:
	void Draw(CTextUI& text, CBox& box); // Thing that we are doing here is getting the button and drawing it.   
private:
};

class CArrowContrller {
public:
	CArrowContrller(CArrowButton button, CArrowView view);
	void HandleMouse(CMenuCntrllr& menuToHandle); // Get Click?
	//A keyboard can physically never reach these buttons? 
private:
	CArrowButton&	button;
	CArrowView&		view;
};
