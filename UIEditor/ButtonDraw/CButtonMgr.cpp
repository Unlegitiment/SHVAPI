#include "CButtonMgr.h"
#include "../../ScriptHookV/natives.h"
#define UNUSED_PARAM(x)
void CButtonMgr::Ticker()
{
}

void CButtonMgr::HandleKeyboardNative(int pad, int KEY)
{
}

void CButtonMgr::HandleKeyboard(DWORD key)
{
}

void CButtonMgr::HandleMouseEvents(CButtonUI& button, int UNUSED_PARAM(pad), int UNUSED_PARAM(ctrl))
{
	CVector2 mousePos = CVector2(PAD::GET_CONTROL_NORMAL(0, 239), PAD::GET_CONTROL_NORMAL(0, 240));
}
