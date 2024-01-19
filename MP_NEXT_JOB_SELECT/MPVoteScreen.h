#pragma once
#include "CMPVoteScreenRaw.h"
#include "GridItem.h"
#include "../UserIO/THREAD.h"
#define MAX_BUTTONS 6
//class CVoteScreen : private CMPVoteScreenRaw, public IThreadMethod{
//public:
//	//static CVoteScreen& GetInstance();
//	void Update();
//	void Tick();
//	void Close();
//private:
//	void Querys();
//	//static CVoteScreen	sm_Instance;
//	static CVoteItem	sm_VoteItems[MAX_BUTTONS];
//	static int			sm_Selected;
//	CVoteScreen();
//
//	void Draw();
//	
//	
//};