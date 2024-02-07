#include "CBoxUI.h"
#include "../../ScriptHookV/natives.h"
CBox::CBox(CVector2 drawPos, CRGBA colour, float width, float height):
	drawPos(drawPos),
	colour(colour),
	width(width),
	height(height),
	corners{CVector2(0,0),CVector2(0,0), CVector2(0,0), CVector2(0,0)}
{
	this->UpdateCornerPos();
	return;
}

void CBox::SetNewDrawPos(CVector2 drawPos)
{
	this->drawPos = drawPos;
	UpdateCornerPos();
}

void CBox::SetWidth(float Width)
{
	this->width = Width;
	UpdateCornerPos()  ;
}

void CBox::SetHeight(float height)
{
	this->height = height;
	UpdateCornerPos();
}

float CBox::GetWidth()
{
	return this->width;
}

float CBox::GetHeight()
{
	return this->height;
}

void CBox::Draw()
{
	GRAPHICS::DRAW_RECT(this->drawPos.x, this->drawPos.y, this->width, this->height, this->colour.r, this->colour.g, this->colour.b, this->colour.a, false);
}

CVector2& CBox::GetDrawPos()
{
	return this->drawPos;
}

CVector2& CBox::GetCornerPos(Corner cornerToGet)
{
	if (cornerToGet > Corner::CORNER_MAX - 1) cornerToGet = Corner::TOPLEFT;
	if (cornerToGet < Corner::TOPLEFT) cornerToGet = Corner::TOPLEFT;
	return corners[cornerToGet];
}

CRGBA& CBox::GetColour()
{
	return this->colour;
}

void CBox::SetColour(CRGBA __newColour__)
{
	this->colour = __newColour__;
}

void CBox::ShowDebugInfo()
{
}

bool CBox::GetIfPointIsInside(CVector2 point)
{
	if (point.x >= GetCornerPos(TOPLEFT).x && point.x <= GetCornerPos(TOPRIGHT).x) {
		if (point.y <= GetCornerPos(BOTTOMLEFT).y && point.y >= GetCornerPos(TOPLEFT).y) {
			return true;
		}
	}
	return false;
}

void CBox::UpdateCornerPos()
{
	this->corners[Corner::TOPLEFT].x = this->drawPos.x - (this->width / 2.0F);
	this->corners[Corner::TOPLEFT].y = this->drawPos.y - (this->height / 2.0F);

	this->corners[Corner::TOPRIGHT].x = this->corners[Corner::TOPLEFT].x + this->width;
	this->corners[Corner::TOPRIGHT].y = this->corners[Corner::TOPLEFT].y;

	this->corners[Corner::BOTTOMLEFT].x = this->corners[Corner::TOPLEFT].x;
	this->corners[Corner::BOTTOMLEFT].y = this->corners[Corner::TOPLEFT].y + this->height;

	this->corners[Corner::BOTTOMRIGHT].x = this->corners[Corner::TOPRIGHT].x;
	this->corners[Corner::BOTTOMRIGHT].y = this->corners[Corner::TOPRIGHT].y + this->height;
}
