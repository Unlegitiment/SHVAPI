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
CScaleform::CScaleform(std::string scaleformName) :
	CBaseScaleform(scaleformName)
{
}

bool CScaleform::SET_SCALEFORM(std::string newScaleform)
{
	if (this->m_Scaleform > SCL_INVALID) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_Scaleform);
	}
	this->m_Scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE(newScaleform.c_str());
	while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_Scaleform)) {
		WAIT(0);
	}
	return true;
}

bool CScaleform::SET_SCALEFORMBG(std::string newScaleform)
{
	if (this->m_ScaleformBG > SCL_INVALID) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_ScaleformBG);
	}
	this->m_ScaleformBG = GRAPHICS::REQUEST_SCALEFORM_MOVIE(newScaleform.c_str());
	while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_ScaleformBG)) {
		WAIT(0);
	}
	return true;
}

bool CScaleform::SET_SCALEFORMFG(std::string newScaleform)
{
	if (this->m_ScaleformFG > SCL_INVALID) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_ScaleformFG);
	}
	this->m_ScaleformFG = GRAPHICS::REQUEST_SCALEFORM_MOVIE(newScaleform.c_str());
	while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_ScaleformFG)) {
		WAIT(0);
	}
	return true;
}

void CScaleform::Draw()
{
	return;
}
