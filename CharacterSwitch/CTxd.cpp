#include "CTxd.h"
#include "../ScriptHookV/natives.h"
void CTxdMgr::Request(CTxd& ref)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(ref.m_Txd.c_str(), 1);
	while (!CTxdMgr::IsTxdLoaded(ref)) WAIT(0);
	ref.m_HasBeenRequested = true;
}

bool CTxdMgr::IsTxdLoaded(CTxd& ref)
{
	return GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(ref.m_Txd.c_str());
}

Vector3 CTxdMgr::GetResolution(CTxd& ref)
{
	return GRAPHICS::GET_TEXTURE_RESOLUTION(ref.m_Txd.c_str(), ref.m_Txn.c_str());
}



void CTxdMgr::SetNoLongerNeed(CTxd& ref)
{
	GRAPHICS::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED(ref.m_Txd.c_str());
	ref.m_HasBeenRequested = false;
}



CTxd::CTxd(string txd, string txn)
	:
	m_Txd(txd),
	m_Txn(txn),
	m_HasBeenRequested(false)
{
}

void CHeadshot::Register(int ped, PedHeadshotRequest requestType)
{
	if (requestType > HEADSHOT_MAX) return;
	switch (requestType) {
	case HEADSHOT_NORMAL:
		break;
	case HEADSHOT_TRANSPARENT:
		break;
	case HEADSHOT_HIRES:
		break;
	}
}

void CHeadshot::Unregister(int shotId)
{
}

void CHeadshot::GetHeadshot(CHeadshot& shot)
{
}

void CHeadshotMgr::Register(int pedId)
{
}

void CHeadshotMgr::RegisterTransparent(int pedId)
{
}

void CHeadshotMgr::RegisterHires(int shotId)
{
}

void CHeadshotMgr::UnRegister(int pedId)
{
}

bool CHeadshotMgr::isValid(int shotId)
{
	return false;
}

bool CHeadshotMgr::isReady(int shotId)
{
	return false;
}

CTxd CHeadshotMgr::GetHeadshotAsTxd(int shotId)
{
	const char* pHeadshot = PED::GET_PEDHEADSHOT_TXD_STRING(shotId);
	return CTxd(pHeadshot, pHeadshot);
}
