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

void CBaseScaleform::RequestTXD(std::string txd)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(txd.c_str(), 1);
	while (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(txd.c_str())) {
		WAIT(0);
	}
}