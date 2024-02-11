#include "CWrappedText.h"

CWrappedText::CWrappedText(CTextUI& text, float minTextPosition, float maxTextPosition) :
	m_Box(CBox(text.pos,CRGBA(0,0,0,0),minTextPosition,maxTextPosition)),
	text(text)
{
	
}
