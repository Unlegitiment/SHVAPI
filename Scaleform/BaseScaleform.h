#pragma once
#include <string>
#include "../ScriptHookV/natives.h"
#define SCL_PASSCODE 1
class CBaseScaleform {
public:
	enum ScaleformVal {
		SCL_INVALID = -1,
	};
	CBaseScaleform(std::string scaleform);
	CBaseScaleform(std::string scl, std::string sclBG, std::string sclFG);
	
	virtual void Draw() = 0;
	void LitStrPush(std::string literalString);
	void GXTStrPush(std::string gxtTablesStr);
	void IntegerPush(int i);
	void FloatPush(float f);
	void TextureStrPush(std::string str);
	void PlayerStrPush(std::string str);
	void BeginFunction(std::string funcName);
	void EndFunction();
	int EndFunctionWithReturn();
	bool isScaleformReadyToReturn(int retHandle);
	int GetScaleformValueInt(int retHandle);
	std::string GetScaleformValueStr(int retHandle);
	bool GetScaleformValueBool(int retHandle);
	int* GetScaleform() { return &m_Scaleform; }
	int* GetScaleformFG() { return &m_ScaleformFG; }
	int* GetScaleformBG() { return &m_ScaleformBG; }
protected:
	int m_Scaleform = SCL_INVALID;		//  The regular scaleform assignment goes to this one. 
	int m_ScaleformBG = SCL_INVALID;	//	 
	int m_ScaleformFG = SCL_INVALID;	//	  
	std::string m_ScfReq; 
	/*
	* sclId if specified by a 
	* -1 = base,
	* -2 = base,
	* -3 = BG,
	* -4 = FG,
	* @returns Integer Trial Code; if 1 it passed else it will fail for any reason.
	* @returns It will NOT throw an exception if it fails instead it will send a notification to the user.
	*/
	int sclRequest(int sclId = SCL_INVALID, std::string ScaleformReq = "");
};

/// <summary>
/// This class is actually pretty nice 
/// This is an API Class that allows for A) quick scaleform testing
/// </summary>
