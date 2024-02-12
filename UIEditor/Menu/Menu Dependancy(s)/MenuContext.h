#pragma once
#include "../../TextDraw/Text.h"

class MenuContext {
public:
	MenuContext();
	void SetMenuContext(std::string& text);
	bool SetInfo();
	
	
	CTextUI& GetText();
	std::string& GetString() const;
	bool doesInfo();
private:
	CTextUI& text;
	bool hasInformationSymbol;
};