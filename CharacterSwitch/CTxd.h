#pragma once
#include <string>
#include "../ScriptHookV/types.h"
using std::string;
class CTxd {
public:
	CTxd(string txd, string txn);
	string m_Txd, m_Txn;
	bool GetIfRequested() { return m_HasBeenRequested; }
	friend class CTxdMgr;
private:
	/*
	* Consider maybe using a bitmask to represent different values 
	* I.E - NotRequested, Requesting..., Requested Successfully, Request Failed
	*/
	bool m_HasBeenRequested;
};
class CTxdMgr {
public:
	static void Request(CTxd& ref);
	static bool IsTxdLoaded(CTxd& ref);
	static Vector3 GetResolution(CTxd& ref);
	static void SetNoLongerNeed(CTxd& ref);
};
class CHeadshot : public CTxd{
public:
	CHeadshot(int ped) :
		CTxd("",""),
		m_PedToHeadshot(ped)
	{
	}
	enum PedHeadshotRequest{
		HEADSHOT_NORMAL,
		HEADSHOT_TRANSPARENT,
		HEADSHOT_HIRES,

		HEADSHOT_MAX
	};
	void Register(int ped, PedHeadshotRequest requestType);
	void Unregister(int shotId);
	void GetHeadshot(CHeadshot& shot);
	int GetHeadshotId() { return m_PedHeadshotRequest; }
private:
	int m_PedHeadshotRequest;
	int m_PedToHeadshot;
};
#define __CHECK_HEADSHOT__(shotId) \
while(!PED::IS_PEDHEADSHOT_READY(shotId) || !PED::IS_PEDHEADSHOT_VALID(shotId)) WAIT(0);\

class CHeadshotMgr : private CTxdMgr{
public:
	static void Register(int pedId);
	static void RegisterTransparent(int pedId);
	static void RegisterHires(int shotId);
	static void UnRegister(int pedId);
	static bool isValid(int shotId);
	static bool isReady(int shotId);
	static CTxd GetHeadshotAsTxd(int shotId); //Same as GET_HEADSHOT_TXD_STRING however using CTxd as a buffer between.
};