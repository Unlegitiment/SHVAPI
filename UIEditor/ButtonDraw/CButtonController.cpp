/*
Notes for 2/6/24 ( and beyond ) :
	1.)Fix Logger ( Borke because file can't be found? ) 
	2.)Fix All Singleton(s)
	3.)Wrap Up products that I am doing (mainly like for example the NEXT_JOB_SELECT should be fixed;
	4.)Advance furthor into design pattern MVC/ MVVM
	5.)Maybe write or use a JSON Parser and download stuff from a webserver.
*/


#include "CButtonController.h"
#include "../../ScriptHookV/natives.h"
#define UNUSED_PARAM(x)

CButtonMgr::CButtonMgr(CButtonUI& buttonToSetup) :
	button(buttonToSetup),
	view(CButtonView())
{
	view.Draw(buttonToSetup);
}

//CButtonMgr::CButtonMgr(const CBox& box, const CTextUI* ltextUI) :
//	button(CButtonUI(const_cast<CBox&>(box))),
//	view(CButtonView())
//
//{
//	button.SetText(button.ETEXT_LEFT, ltextUI);
//}

void CButtonMgr::handleMouse(CRGBA highlightColour, float mousePosX, float mousePosY)
{
	CVector2 mousePos = CVector2(mousePosX, mousePosY);
	static CRGBA nonHighlighedColour = button.m_Box.GetColour(); // caches the colour so that we can check it.
	if (button.GetBox().GetIfPointIsInside(mousePos)) {
		button.GetBox().SetColour(highlightColour);
		return;
	}
	button.GetBox().SetColour(nonHighlighedColour);
}


void CButtonMgr::UpdateDrawPos(CVector2 drawPosition)
{
	button.SetNewDrawPos(drawPosition);
	Update();
}

void CButtonMgr::SetHeight(float _height)
{
	button.GetBox().SetHeight(_height);
	Update();
}

void CButtonMgr::SetWidth(float _width)
{
	button.GetBox().SetWidth(_width);
	Update();
}

void CButtonMgr::Update()
{
	for (int i = 0; i < button.ETEXT_MAX; i++) {
		if (button.GetText(static_cast<CButtonUI::eText>(i)) == NULL)continue;
		UpdateButtonAtIndex(i);
	}
}
void CButtonMgr::UpdateButtonAtIndex(int index) {
	if (index > button.ETEXT_MAX) return;
	button.IdealDraw(static_cast<CButtonUI::eText>(index), button.GetText(static_cast<CButtonUI::eText>(index)));
	
}

CButtonView::CButtonView()
{
}

void CButtonView::Draw(CButtonUI& const xd)
{
	xd.GetBox().Draw();
	for (int i = 0; i < xd.ETEXT_MAX; i++) {
		if (xd.GetText(static_cast<CButtonUI::eText>(i)) == NULL) continue;
		xd.GetText(static_cast<CButtonUI::eText>(i))->Draw();
		xd.GetText(static_cast<CButtonUI::eText>(i))->DrawDebugInfo((i * 0.3f)+0.01f);
	}
}
