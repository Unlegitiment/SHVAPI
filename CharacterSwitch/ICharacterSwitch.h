#pragma once
#include "../ScriptHookV/enums.h"
/*
* Flags use bitwise operations to perform.
* the enumeration is to assist with naming however these are internal and I don't know what they are named just from my own observation
*/
#define BIT(x) (1 << x)
class ICharacterSwitch{
private:
	signed m_Flags;
	int m_OldPed; // oldPedId (starting Jump pos)
	int m_NewPed; // newPedId (end Jump Pos) 
	int m_SwitchType; // see: ePlayerSwitchEnum in the natives
	int m_JumpIndex; // native for getting the current bit its on;
	
public:
	enum SWITCH_FLAGS{
		SWITCH_FLAG_0	= BIT(0),
		SWITCH_FLAG_1	= BIT(1),
		SWITCH_FLAG_2	= BIT(2),
		SWITCH_FLAG_3	= BIT(3),
		SWITCH_FLAG_4	= BIT(4),
		SWITCH_FLAG_5	= BIT(5),
		SWITCH_FLAG_6	= BIT(6),
		SWITCH_FLAG_7	= BIT(7),
		SWITCH_FLAG_8	= BIT(8),
		SWITCH_FLAG_9	= BIT(9),
		SWITCH_FLAG_10	= BIT(10),
		SWITCH_FLAG_11	= BIT(11),
		SWITCH_FLAG_12	= BIT(12),
		SWITCH_FLAG_13	= BIT(13),
		SWITCH_FLAG_14	= BIT(14),
		SWITCH_FLAG_15	= BIT(15),
		SWITCH_FLAG_16	= BIT(16)
	};
	ICharacterSwitch(int oldPed, int newPed, ePlayerSwitchTypes playerSwitchType, signed flags);
	void Start();
	void End();
};