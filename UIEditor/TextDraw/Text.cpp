#include "Text.h"
#include "../../ScriptHookV/natives.h"
CTextUI::CTextUI(string text, CVector2 position, float size, int font, CRGBA colour, s_TextConfig& textConfig) :
	text(text),
	pos(position),
	size(size),
	font(font),
	colour(colour),
	config(textConfig)
{ // state shit
	this->isDrawn = false;
}

CTextUI::CTextUI(string text, CVector2 position, CRGBA colour)
	: CTextUI(text, position, 1, 0, colour, s_TextConfig(CTextDropshadow(1, CRGBA(0, 0, 0, 125)), CLeftJustify(), false))
{ }

void CTextUI::Draw() 
{
	this->config.textJustification.SetupText();
}

bool CTextUI::getIsDrawn()
{
	return this->isDrawn;
}

void CTextUI::setDrawn(bool drawState)
{
	this->isDrawn = drawState;
}
