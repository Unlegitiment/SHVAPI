#include "MPVoteScreen.h"
//CVoteScreen CVoteScreen::sm_Instance;

//CVoteScreen& CVoteScreen::GetInstance()
//{
//	return sm_Instance;
//}
CVoteScreen::CVoteScreen():
	CMPVoteScreenRaw(),
	m_isActive(false),
	m_VoteItems{CVoteItem(),CVoteItem(), CVoteItem(), CVoteItem(), CVoteItem(), CVoteItem(),},
	m_Selected(0)
{
	
	return;
}
void CVoteScreen::Draw() {
	GRAPHICS::DRAW_SCALEFORM_MOVIE(this->m_Scaleform, 0.5, 0.5, 1, 1, 255, 255, 255, 255, 0);
}

void CVoteScreen::Update()
{

}

void CVoteScreen::Tick()
{
	this->Draw();
}

void CVoteScreen::Close()
{
}
