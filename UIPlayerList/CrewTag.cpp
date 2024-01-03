#include "CrewTag.h"
#include <string>
string ItoStr(int x) {
    std::string str;
    str = std::to_string(x);
    return str;
}
void CCrewTag::FinalizeCrewTag(std::string& crewTag) {
    crewTag.resize(std::max(static_cast<size_t>(3), crewTag.size(), std::less<size_t>()), ' ');

    crewTag.insert(0, "...");
    if (this->m_isPrivate) {
        crewTag[0] = '(';
    }
    if (this->m_hasRockstar) {
        crewTag[1] = '*';
    }
    crewTag[2] = ItoStr((int)this->m_Rank)[0];
}
CCrewTag::CCrewTag(string crewTag)
{
    this->m_BaseCrewTag = crewTag;
    this->m_isPrivate = true;
    this->m_hasRockstar = false;
    this->m_Rank = eCrewRank::MUSCLE;
    FinalizeCrewTag(this->m_BaseCrewTag);
    return;
}
CCrewTag::CCrewTag() {
    this->m_BaseCrewTag = "RSG";
    this->m_hasRockstar = true;
    this->m_isPrivate = false;
    this->m_Rank = eCrewRank::COMMISSIONER;
    FinalizeCrewTag(this->m_BaseCrewTag);
    return;
}
string CCrewTag::toStr() {
    string temp = this->m_BaseCrewTag ;
    return temp;
}
void CCrewTag::change_Private(bool newData) {
    this->m_isPrivate = newData;
    if (this->m_isPrivate) {
        this->m_BaseCrewTag[0] = '.';
    }
    else {
        this->m_BaseCrewTag[0] = '(';
    }
    return;
}
void CCrewTag::change_RSG(bool newData) {
    this->m_hasRockstar = newData;
    if (this->m_hasRockstar) {
        this->m_BaseCrewTag[1] = '.';
    }
    else {
        this->m_BaseCrewTag[1] = '*';
    }
    return;
}
void CCrewTag::change_Rank(eCrewRank newRank) {
    this->m_Rank = newRank;
    this->m_BaseCrewTag[2] = ItoStr((int)newRank)[0];
}
CCrewTag::CCrewTag(string crewTag, bool priv, bool rsg, eCrewRank rank) {
    this->m_BaseCrewTag = crewTag;
    this->m_hasRockstar = rsg;
    this->m_isPrivate = priv;
    this->m_Rank = rank;
    this->FinalizeCrewTag(this->m_BaseCrewTag);
    return;
}