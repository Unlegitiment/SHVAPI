#pragma once
#include "CharacterSwitchNative.h"
#include "../ScriptHookV/types.h"
#include "../GenericList/CList.h"
#include "../Scaleform/BaseScaleform.h"

/*
* This Switch changes the player's ped dependant on inputs args. Transports them and while they are in the air displays GTA Online Propaganda. 
* For example rockstar newswire info posts etc.
* This DOES put you inside an interior btw. However it does NOT put you in the GTA Online passive sort of mode without guns. 
* As well this is just base interiors and doesn't include like generalized spawnpts and whatever.
*/
class CGTAVScaleform : public CBaseScaleform {
public:
	CGTAVScaleform();
	CGTAVScaleform(std::string title = "", std::string subTitle = "", std::string body = "", std::string txd = "", std::string txn = "");
	~CGTAVScaleform();
	void Draw() override;
	void CancelDraw(BOOL *active);
	void Cleanup();

	std::string m_Title;
	std::string m_Subtitle;
	std::string m_Body;
	std::string m_Txd;
	std::string m_Txn;
private:
	BOOL m_Visible;
};
class COnlineSwitcher {
public:
	enum eApartmentSelector {
		ECLIPSE	 ,
		DEL_PERRO,
		TINSEL	 ,
		RICHARD	 ,
		PILLBOX	 ,
		WEAZEL	 ,
		ALTA	 ,
		MAX_APARTMENT
	};
	void TeleportIntoApartment(eApartmentSelector selection);

private:

	Vector3 apartments[MAX_APARTMENT] = {};
};