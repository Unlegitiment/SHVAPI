#include "Text.h"
#include "../../ScriptHookV/natives.h"
CTextUI::CTextUI(string text, CVector2 position, float size, int font, CRGBA colour,CTextDropshadow _dropShadow_, TextJustify* _justification_, bool _hasOutline_) :
	text(text),
	pos(position),
	size(size),
	font(font),
	colour(colour),
	dropShadow(_dropShadow_),
	textJustification(_justification_),
	hasOutline(_hasOutline_)
{ // state shit
	this->isDrawn = false;
}

CTextUI::CTextUI() :
	CTextUI("", CVector2(1,1), CRGBA(0,0,0,0))
{
}

CTextUI::CTextUI(string text, CVector2 position, CRGBA colour)
	: CTextUI(text, position, 0.3609, 0, colour, CTextDropshadow(1, CRGBA(0, 0, 0, 125)), new CLeftJustify(), false)
{ }

CTextUI CTextUI::operator=(CTextUI & other)
{
	return CTextUI(other.text, other.pos,other.size,other.font,other.colour,other.dropShadow, other.textJustification, other.hasOutline);
}

CTextUI::~CTextUI()
{
	delete textJustification;
}

float CTextUI::CharacterHeight(float iLead)
{
	int scrHeight = 0;
	int scrWidth = 0;
	GRAPHICS::GET_SCREEN_RESOLUTION(&scrWidth, &scrHeight);
	return ((size + iLead) / scrHeight) * 10;
}

void CTextUI::Draw() 
{
	this->textJustification->SetupText();
	HUD::SET_TEXT_FONT(this->font);
	HUD::SET_TEXT_SCALE(0.48f, this->size);
	this->dropShadow.NativeCall();
	if (this->hasOutline) HUD::SET_TEXT_OUTLINE();
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

void CTextUI::SetTextJustification(TextJustify* newJustification)
{
	this->textJustification = newJustification;
	return;
}

void CTextUI::DrawDebugInfo(float x, float yOffset)
{
	DrawDebugText("STR: " + text, x, yOffset, 2);
	DrawDebugText("POS: " + pos.toStr(), x, yOffset, 3);
	DrawDebugText("COL: " + colour.toStr(), x, yOffset,4);
	DrawDebugText("SIZ: " + std::to_string(size), x, yOffset, 5);
	DrawDebugText("FNT: " + std::to_string(font), x, yOffset, 6);
}

void CTextUI::DrawDebugText(const std::string& debugText, float x, float yOffset, int lineIndex)
{
	CTextUI debugTextUI(debugText, CVector2(x, (0.1f + yOffset * lineIndex) /900.0F), CRGBA(255, 255, 255, 200));
	
	debugTextUI.Draw();
}

void CTextUI::setDrawn(bool drawState)
{
	this->isDrawn = drawState;
}
