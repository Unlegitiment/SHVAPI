#pragma once
#include "../BoxDraw/CBoxUI.h"
#include "../TextDraw/Text.h"
/*
* No Tick Method because if you're rendering a button it should be upto the user to control how the code works.
* Tick methods are only used for updating internal values. such as like backend stuff. I.E native controlled stuff.
* If you NEED a tick method than you probably have something else wrong. Never really use a tick method unless it signifies that an internal value should be changed.
* I.E CMenu(s) should have a Tick() method because they need to A) update the buttons and boxes around them but also in general you want that. 
* tl;dr Tick should be used in cases where LARGE groups of logic needs to be grouped and updated every GameTick. 
* 
* Also unless a Tick() method is specified as a backend (via comment) than don't bother using. Tick backgrounds should go on a seperate thread because they do more stuff more in track with updating weird background values.
* Also Menu(s) should likely use a (static CList<CButtonUI> buttons) So that the values can change and flash so that a value will remain after. Like Green Box and Text should stick.
* 
*/ 
class CButtonUI {
public:
	friend class CButtonMgr;
public://FACTORY
	CButtonUI(CTextUI& leftText, CTextUI& rightText, CBox& button);
	static CButtonUI CreateDraw(); //Quick Creation and Drawing used in whileLoop
public:
	enum eText{
		ETEXT_LEFT,
		ETEXT_MIDDLE,
		ETEXT_RIGHT,
		ETEXT_MAX
	};

	CTextUI* GetText(eText textToReq);
	void SetText(eText textToSet, CTextUI* textToInput);
	
private:
	CTextUI*	m_Buttons[ETEXT_MAX]; //specified max buttonTypes LUT?
	CBox		m_Box;
};