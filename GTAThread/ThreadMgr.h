#pragma once
#include "../GenericList/CList.h"
typedef void(*Thread)();
/*
* This is a class that controls the threads and registers the instances of them based on the ones at the main instance. 
* I believe thats how it work lmao.
*/
class GTAthread{
private:
	static GTAthread		sm_Instance;
	static CList<Thread>	sm_ThreadList;
	GTAthread() {};
public:
	int		Register(Thread thread);
	void	UnregisterThread(int index);
	Thread* Find(int index);
	static GTAthread& GetInstance() { return sm_Instance; }
	int GetSize() { return sm_ThreadList.getSize(); }
	Thread* GetList() { return sm_ThreadList.getList(); }

};