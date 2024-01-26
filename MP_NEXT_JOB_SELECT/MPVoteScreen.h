#pragma once
#include "CMPVoteScreenRaw.h"
#include "GridItem.h"
#include "../UserIO/THREAD.h"
#define MAX_BUTTONS 6
class CVoteScreen :  public CMPVoteScreenRaw, public IThreadMethod{
public:
	void Update();
	void Tick();
	void Close();
	void Draw();
	void QuitDraw() { m_isActive = false; }
	bool isDrawing() { return m_isActive; }
	CVoteScreen();
private:
	CVoteItem	m_VoteItems[MAX_BUTTONS];
	int			m_Selected;
	bool		m_isActive;
	void Querys();
};