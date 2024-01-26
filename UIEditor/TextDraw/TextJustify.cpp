#include "TextJustify.h"
#include "../../ScriptHookV/natives.h"
void CLeftJustify::SetupText()
{
}

void CLeftJustify::NativeCaller()
{
	HUD::SET_TEXT_JUSTIFICATION(1);
}

void CLeftJustify::SetupText(float start, float end)
{
}

//CRightJustify::CRightJustify(float start, float end) 
//	:
//	m_Start(start),
//	m_End(end)
//{
//
//}

void CRightJustify::SetupText(float start, float end)
{
	if (start > 1.0F || end > 1.0F || start < 0.0F || end < 0.0F) {

	}
}

void CRightJustify::NativeCaller()
{
}

void CRightJustify::SetupText()
{
	HUD::SET_TEXT_JUSTIFICATION(2);
	HUD::SET_TEXT_WRAP(this->m_Start, this->m_End);
}

void CMiddleJustify::SetupText()
{
}

void CMiddleJustify::NativeCaller()
{
}

void CMiddleJustify::SetupText(float start, float end)
{
}
