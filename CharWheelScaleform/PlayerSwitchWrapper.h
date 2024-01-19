#pragma once
#include "PLAYER_SWITCH.h"
#include "../UserIO/THREAD.h"

class CCharacterInfo {
public:
	enum SPState {
		UNLOCKED = 1,
		UNABLE_TO_SWAP = 2,
		LOCKED_CHAR_UNKNOWN = 3,
	};
	enum CharEnum {
		CE_MICHAEL = 0,
		CE_TREVOR = 1,
		CE_FRANKLIN = 2,
		CE_ONLINE = 3,
		CE_CHOP_RIGHT = 4,
		CE_CHOP_TOP = 5,
		CE_CHOP_LEFT = 6,
	};
	enum Slot {
		ST_MICHAEL = 0,
		ST_FRANKLIN = 1,
		ST_TREVOR = 2,
		ST_MP_SLOT = 3,
		ST_MAX_SLOT = 4
	};
	enum MPState {
		NULLCHARWITHLABEL = 0,
		NULLCHARWITHLABEL2 = 1,
		NULLCHARWITHLABEL3 = 2,
		NULLCHARWITHOUTLABEL = 3
	};
	CharEnum character;
	bool isHinted;
	bool isSelected;
};
class CCharacterInfoSP : public CCharacterInfo {
public:
	CCharacterInfoSP() {
		state = UNLOCKED;
		Damage = {
			false,
			false,
			false,
		};
		missionCounter = 0;
	}
	SPState state;
	struct {
		bool isDamaged;
		bool flash;
		bool notify;
	}Damage;
	int missionCounter;
};

/*
* Can be a Singleton because you can only have one instance of it active at once. 
* However is not right now because of the fact that it would introduce some added complexity.
* Work on Singleton stuff tomorrow today do outlines and maskarade.
*/
class PlayerSwitchWrapper : public IThreadMethod{
public:
	struct SCharacterInfoMP : CCharacterInfo{
		MPState state ;
		SCharacterInfoMP() {
			state = MPState::NULLCHARWITHOUTLABEL;
		}
	};
	PlayerSwitchWrapper();
	int GetSwitchIndex();
	void Tick();
	void Update();
	void SetMissionNumber(CCharacterInfo::Slot SlotToApply, int Number);
	CPLAYER_SWITCH GetRaw() { return m_rawSwitch; }
	std::string		m_MPSLOT_HEADTXD;
	std::string		m_MPLABEL; //depricated ? 
	bool m_Active;
private:
	void NativeTick();
	void HandleControl();
	CPLAYER_SWITCH		m_rawSwitch;
	int					m_selected;
	CCharacterInfoSP	m_SPCharacterInfo[CCharacterInfo::ST_MAX_SLOT - 1]; //define the classes wit only one missing [MP CharSlot]
	SCharacterInfoMP	m_MPCharacterInfo;
};


extern PlayerSwitchWrapper g_Switcher;