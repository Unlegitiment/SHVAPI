#include "ArrowButton.h"
#define scriptAssert(cond) do{  }while(cond);
void CArrowView::Draw(CTextUI& text, CBox& box)
{

	//text.SetTextJustification(new CMiddleJustify());
	box.Draw(); 
	text.Draw();
}

CArrowButton::CArrowButton(CVector2& drawPos, eArrowBtn arrowBtn) :
	/*
	* The issue with the following code is that it runs out of scope thus creating an issue with memory I likely could use shared_ptr because 
	* it would be more beneifical I just need to do more research to the lifetime of a shared_ptr because I am not sure when they actually end.
	*/
	text(new CTextUI(
		std::to_string(arrowBtn),
		drawPos,
		0.512f,
		3, 
		CRGBA(255,255,255,255), 
		CTextDropshadow(0,CRGBA(0,0,0,0)),
		new CMiddleJustify(),
		false
	)),
	box(new CBox(drawPos, CRGBA(0, 0, 0, 120), 0.1, 0.1))
{
}

CArrowButton::CArrowButton(CBox* box, CTextUI* text, CVector2 drawPos, eArrowBtn arrowBtn):
	box(box),
	text(text)
{
}

CBox& CArrowButton::GetBox()
{
	return *box;
}

CTextUI& CArrowButton::GetText()
{
	return *text;
}

void CArrowButton::SetText(CTextUI* _text)
{
	this->text = _text;
}

void CArrowButton::SetBox(CBox* _box)
{
	this->box = _box;
}

CArrowButton::~CArrowButton()
{
	delete text;
	delete box;
}


