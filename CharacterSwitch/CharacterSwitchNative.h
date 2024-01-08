#pragma once
#include <string>
/*
* This class acts as a base for all Scaleform Functions. Also any control variables I'd find useful.
* For MVC think Model.
* Also this is a Singleton because you can only have one SWITCH active at a time.
* This is NOT a Wrapper for a Switcher(s).
* Make one yourself you lazy shit.
*/
#define BIT(x) (1 << x)
class CCharSwitcherNATIVE{
private:
	static int					sm_OldPed		 ;
	static int					sm_NewPed		 ;
	static int					sm_SwitchState	 ;
	static int					sm_SwitchType	 ; // ePlayerSwitchType : LONG, MED, SHORT, AUTO;
	static bool					sm_IsSwitchActive;
	int							m_Flags		  = 0;
	static CCharSwitcherNATIVE	sm_Instance		 ;
	static std::string			sm_EstablishShot ; 
	CCharSwitcherNATIVE() {};

	friend class TeleportCameraSwitch; //All SubClasses should go here as friend classes. This is because it allows them to control the state of all static members.
public:
	/*Flags*/
	enum {
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
		SWITCH_FLAG_15	= BIT(15)
	};
	static CCharSwitcherNATIVE& GetInstance() { return sm_Instance; };
	int GetSwitchState();
	void Init(int oldPed, int newPed, int SwitchType, signed flags);
	void Start();
	void StartWithParams(int oldPed, int newPed, int SwitchType, signed flags);
	void Stop(bool withClean);
	bool isSwitchInProgress() { return this->sm_IsSwitchActive; }
	int GetIdealSwitch(float x1, float y1, float z1, float x2,float y2, float z2);
	void SetEstablishingShot(std::string establishingShot); 
	
};