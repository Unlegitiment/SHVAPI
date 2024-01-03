#include "ListPlayer.h"
#include <string>
CListPlayer::CListPlayer() :
	m_Name("Unlegit"),
	index(0),
	relationtoPlayer("")
{
	
}
CListPlayer::CListPlayer(std::string name)
{
	this->m_Name = name;
	this->index = 0;
	this->relationtoPlayer = "";
	return;
}

CListPlayer::CListPlayer(std::string name, CCrewTag tag)
{
	this->m_Name = name;
	this->m_CrewTag = tag;
	this->relationtoPlayer = "";

	this->index = 0;
}

//void CListPlayer::ApplyCrewTag(CCrewTag crewTag)
//{
//	this->m_CrewTag = crewTag;
//}

std::string CListPlayer::toStr()
{
	std::string retStr = m_Name + this->m_CrewTag.toStr();
	return retStr;
}

CPlayerRankBase::CPlayerRankBase()
{
	this->m_Rank = 0;
	return;
}

std::string CPlayerRankBase::toStr()
{
	return std::string(std::to_string(this->m_Rank));
}
