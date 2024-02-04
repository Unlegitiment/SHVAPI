#pragma once
#include "../../ScriptHookV/types.h"
class CBox {
public:
	enum Corner {
		TOPLEFT,
		TOPRIGHT,
		BOTTOMLEFT,
		BOTTOMRIGHT,
		CORNER_MAX
	};
	CBox(CVector2 drawPos, CRGBA colour, float length, float height);
	void SetNewDrawPos(CVector2 drawPos);
	void SetWidth(float Width);
	void SetHeight(float height);
	float GetWidth();
	float GetHeight();
	void Draw();
	CVector2& GetDrawPos();
	CVector2& GetCornerPos(Corner cornerToGet);
	CRGBA& GetColour();
	void SetColour(CRGBA __newColour__);
	void ShowDebugInfo();
private:
	void UpdateCornerPos();
	CVector2 drawPos;
	CVector2 corners[CORNER_MAX];
	CRGBA colour;
	float width, height;

};