#include "BaseScaleform.h"
#include "../ScriptHookV/natives.h"
CBaseScaleform::CBaseScaleform(std::string scaleform)
	:
	m_ScfReq(scaleform)
{
	this->m_Scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE(scaleform.c_str());
	while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(m_Scaleform)) {
		WAIT(0);
	}
}

CBaseScaleform::CBaseScaleform(std::string scl, std::string sclBG, std::string sclFG)
{
	int* scaleforms[3] = { &this->m_Scaleform, &this->m_ScaleformBG, &this->m_ScaleformFG };
	std::string strs[3] = { scl, sclBG, sclFG };
	for (int i = 0; i < 3; i++) {
		*scaleforms[i] = GRAPHICS::REQUEST_SCALEFORM_MOVIE(strs[i].c_str());
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(*scaleforms[i])) {
			WAIT(0);
		}
	}
	return;
}

void CBaseScaleform::LitStrPush(std::string literalString)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(literalString.c_str());
}

void CBaseScaleform::GXTStrPush(std::string gxtTablesStr)
{
	GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING(gxtTablesStr.c_str());
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CBaseScaleform::IntegerPush(int i)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(i);
}

void CBaseScaleform::FloatPush(float f)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(f);
}

void CBaseScaleform::TextureStrPush(std::string str)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_TEXTURE_NAME_STRING(str.c_str());
}

void CBaseScaleform::PlayerStrPush(std::string str)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(str.c_str());
}

void CBaseScaleform::BeginFunction(std::string funcName)
{
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->m_Scaleform, funcName.c_str());
}

void CBaseScaleform::EndFunction()
{
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

int CBaseScaleform::EndFunctionWithReturn()
{
	return GRAPHICS::END_SCALEFORM_MOVIE_METHOD_RETURN_VALUE();
}

bool CBaseScaleform::isScaleformReadyToReturn(int retHandle)
{
	return GRAPHICS::IS_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_READY(retHandle);
}

int CBaseScaleform::GetScaleformValueInt(int retHandle)
{
	return GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_INT(retHandle);
}

std::string CBaseScaleform::GetScaleformValueStr(int retHandle)
{
	return std::string(GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_STRING(retHandle));
}

bool CBaseScaleform::GetScaleformValueBool(int retHandle)
{
	return GRAPHICS::GET_SCALEFORM_MOVIE_METHOD_RETURN_VALUE_BOOL(retHandle);
}
int CBaseScaleform::sclRequest(int sclId, std::string ScaleformReq)
{
	switch (sclId) {
	case -1: //none aka modify base
		this->m_Scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE(ScaleformReq.c_str());
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_Scaleform)) {
			WAIT(0);
		}
		break;
	case -2://base
		this->m_Scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE(ScaleformReq.c_str());
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_Scaleform)) {
			WAIT(0);
		}
		break;
	case -3://bg
		this->m_ScaleformBG = GRAPHICS::REQUEST_SCALEFORM_MOVIE(ScaleformReq.c_str());
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_ScaleformBG)) {
			WAIT(0);
		}
		break;
	case -4://fg
		this->m_ScaleformFG = GRAPHICS::REQUEST_SCALEFORM_MOVIE(ScaleformReq.c_str());
		while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_ScaleformFG)) {
			WAIT(0);
		}
		break;
	case -5://all

		break;
	default: //return 0;
		break;
	}
	return SCL_PASSCODE;
}
