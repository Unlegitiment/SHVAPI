#include "ThreadMgr.h"
//STATIC INIT
GTAthread		GTAthread::sm_Instance;
CList<Thread>	GTAthread::sm_ThreadList = CList<Thread>();
int GTAthread::Register(Thread thread) {
	sm_ThreadList.add(thread);
	return 0;
}
void GTAthread::UnregisterThread(int index) {
	sm_ThreadList.replace(index, nullptr);
}
