#pragma once
#include <string>
#include "../../ScriptHookV/types.h"
#include "TextJustify.h"
#include "TextDropshadow.h"
using std::string;
struct s_TextConfig {
	CTextDropshadow&	dropShadow;
	TextJustify&		textJustification;
	bool hasOutline;
	s_TextConfig(CTextDropshadow& _dropShadow, TextJustify& _textJustification, bool _hasOutline):
		dropShadow(_dropShadow),
		textJustification(_textJustification),
		hasOutline(_hasOutline)
	{

	}
};
class CTextUI {
public: // functions
	enum eFonts {
		FONT_CHALET_LONDON = 0,
		FONT_HOUSE_SCRIPT = 1,
		FONT_MONOSPACE = 2,
		FONT_CHALET_COMPRISE_COLOGNE= 4,
		FONT_PRICEDOWN = 7
	};
	CTextUI(string text,CVector2 position,float size,int font,CRGBA colour, s_TextConfig& textConfig);
	/*
	* @brief We'll handle most things. :)
	* @brief Uses a default size, font, and basic settings allowing more things to apply.
	*/
	CTextUI(string text, CVector2 position, CRGBA colour); 
	/// <summary>
	/// Similar to Tick method in other functions. 
	/// This goes within a thread main as it initalized every native call nessicary.
	/// </summary>
	void Draw();
	bool getIsDrawn();
public://variables 
	string text;
	CVector2 pos;
	CRGBA colour;
	float size;
	int font; //make font enum? (yes) 
	bool hasOutline; //For now this exists. Maybe write a text Outliner. ( Dont because its a toggle in the natives )
	s_TextConfig config;
protected://Subclasses (someday)
	void setDrawn(bool drawState);
private: // Variables
	bool isDrawn;
};