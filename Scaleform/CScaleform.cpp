#include "CScaleform.h"
CScaleform::CScaleform(std::string scaleformName) :
	CBaseScaleform(scaleformName),
	m_IsActive(false)
{
}

CScaleform::CScaleform(std::string scaleformName, std::string ScaleformBG, std::string scaleformFG) :
	CBaseScaleform(scaleformName, ScaleformBG, scaleformFG),
	m_IsActive(false)
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
	if (this->m_ScaleformFG == SCL_INVALID) {
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_ScaleformFG);
	}
	this->m_ScaleformFG = GRAPHICS::REQUEST_SCALEFORM_MOVIE(newScaleform.c_str());
	while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->m_ScaleformFG)) {
		WAIT(0);
	}
	return true;
}
/*
* This is a generic Scaleform cleanup only setting the handles to no longer needed.
* If a scaleform has a larger purpose of cleanup like say it needs to reactivate hud material than it needs overriding.
*/
void CScaleform::CleanUp()
{
	GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_Scaleform);
	GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_ScaleformBG);
	GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&this->m_ScaleformFG);
}

void CScaleform::Draw(signed flags, CVector2 drawPos, CVector2 lenWid)
{
	this->SetIsActive(true);
	if (flags & 1 << 1 &&
		flags & 1 << 2) {
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(this->m_ScaleformBG, this->m_ScaleformFG, 255, 255, 255, 255);
	}
	if (flags & 1 << 0) {
		GRAPHICS::DRAW_SCALEFORM_MOVIE(this->m_Scaleform, drawPos.x, drawPos.y, lenWid.x, lenWid.y, 255, 255, 255, 255, 0);
	}
}

void CScaleform::Draw()
{
	return;
}

