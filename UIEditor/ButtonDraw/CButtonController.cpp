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

CButtonController::CButtonController(CButtonUI buttonToSetup) :
	button(buttonToSetup),
	view(CButtonView())
{
	view.Draw();
}

CButtonController::CButtonController(const CBox& box, const CTextUI& ltextUI) :
	button(const_cast<CBox&>(box)),
	view(CButtonView())

{
	button.SetText(button.ETEXT_LEFT, const_cast<CTextUI&>(ltextUI));
}

void CButtonController::handleMouse(CRGBA highlightColour, float mousePosX, float mousePosY)
{
}

void CButtonController::handleKeyboard(CRGBA highlightColour)
{
}

void CButtonController::UpdateDrawPos(CVector2 drawPosition)
{
}

void CButtonController::SetHeight(float height)
{
}

void CButtonController::SetWidth(float width)
{
}

void CButtonView::Draw()
{
}
