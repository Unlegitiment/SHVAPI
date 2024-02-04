#pragma once
#include "CButtonUI.h"
class MouseEvents {
public:
	virtual void HandleMouseEvents(int pad, int ctrl) = 0;
};
class KeyboardEvents {
public:
	virtual void HandleKeyboardNative(int pad, int KEY) = 0;
	virtual void HandleKeyboard(DWORD key) = 0;
};


class CButtonMgr : private MouseEvents, private KeyboardEvents{
public:
	void Ticker(); //call this in the button's draw or? 
private:
	void HandleKeyboardNative(int pad, int KEY);
	void HandleKeyboard(DWORD key);
	void HandleMouseEvents(CButtonUI& button, int pad, int ctrl);
};