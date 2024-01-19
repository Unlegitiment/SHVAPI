#pragma once
#include <string>
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
	int EndFunctionWithReturn();
	bool isScaleformReadyToReturn(int retHandle);
	int GetScaleformValueInt(int retHandle);
	std::string GetScaleformValueStr(int retHandle);
	bool GetScaleformValueBool(int retHandle);
	void RequestTXD(std::string txd);
	int* GetScaleform() { return &m_Scaleform; }


protected:
	int m_Scaleform = SCL_INVALID;		// The regular scaleform assignment goes to this one. 
	int m_ScaleformBG = SCL_INVALID;	//	
	int m_ScaleformFG = SCL_INVALID;	//	
	std::string m_ScfReq;
};