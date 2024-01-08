#pragma once
#include "CharacterSwitchNative.h"
#include "../ScriptHookV/types.h"
#include "../GenericList/CList.h"
/*
* This Switch changes the player's ped dependant on inputs args. Transports them and while they are in the air displays GTA Online Propaganda. 
* For example rockstar newswire info posts etc.
* This DOES put you inside an interior btw. However it does NOT put you in the GTA Online passive sort of mode without guns. 
* As well this is just base interiors and doesn't include like generalized spawnpts and whatever.
*/
class CBaseScaleform {
public:
	enum ScaleformVal {
		SCL_INVALID = -1,
	};
	CBaseScaleform(std::string scaleform);
	virtual void Draw() = 0;
	virtual void LitStrPush(std::string literalString);
	virtual void GXTStrPush(std::string gxtTablesStr);
	void IntegerPush(int i);
	void FloatPush(float f);
	void TextureStrPush(std::string str);
	void PlayerStrPush(std::string str);
	void BeginFunction(std::string funcName);
	void EndFunction();
	void RequestTXD(std::string txd);
	int* GetScaleform() { return &m_Scaleform;  }


protected:
	int m_Scaleform		= SCL_INVALID; //The regular scaleform assignment goes to this one. 
	int m_ScaleformBG	= SCL_INVALID; //
	int m_ScaleformFG	= SCL_INVALID; //
	std::string m_ScfReq;
};
class CGTAVScaleform : public CBaseScaleform {
public:
	CGTAVScaleform();
	CGTAVScaleform(std::string title = "", std::string subTitle = "", std::string body = "", std::string txd = "", std::string txn = "");
	~CGTAVScaleform();
	void DrawFrame();
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
		ECLIPSE		= 0,
		DEL_PERRO	= 1,
		TINSEL		= 2,
		RICHARD		= 3,
		PILLBOX		= 4,
		WEAZEL		= 5,
		ALTA		= 6,
		MAX_APARTMENT
	};
	void TeleportIntoApartment(eApartmentSelector selection);

private:

	Vector3 apartments[MAX_APARTMENT] = {};
};