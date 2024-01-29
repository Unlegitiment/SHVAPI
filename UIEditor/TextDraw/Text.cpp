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
	: CTextUI(text, position, 0.3609, 0, colour, s_TextConfig(CTextDropshadow(1, CRGBA(0, 0, 0, 125)), CLeftJustify(), false))
{ }

CTextUI CTextUI::operator=(CTextUI & other)
{
	return CTextUI(other.text, other.pos,other.size,other.font,other.colour,other.config);
}

void CTextUI::Draw() 
{
	this->config.textJustification.SetupText();
	HUD::SET_TEXT_FONT(this->font);
	HUD::SET_TEXT_SCALE(1.0f, this->size);
	this->config.dropShadow.NativeCall();
	if (this->config.hasOutline) HUD::SET_TEXT_OUTLINE();
	HUD::SET_TEXT_LEADING(1);
	HUD::SET_TEXT_COLOUR(this->colour.r, this->colour.g, this->colour.b, this->colour.a);
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(this->text.c_str());
	HUD::END_TEXT_COMMAND_DISPLAY_TEXT(this->pos.x, this->pos.y, 0);
}

bool CTextUI::getIsDrawn()
{
	return this->isDrawn;
}

void CTextUI::setDrawn(bool drawState)
{
	this->isDrawn = drawState;
}
