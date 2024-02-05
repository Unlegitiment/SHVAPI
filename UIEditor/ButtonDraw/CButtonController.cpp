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
