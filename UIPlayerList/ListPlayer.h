#pragma once
#include <iostream>
#include "CrewTag.h"
class CPlayerRankBase {
public:
    CPlayerRankBase(); //instanciate instance?
    std::string toStr();
    int m_Rank;
private:

};
class CListPlayer {
public:
    CListPlayer();
    CListPlayer(std::string name);
    CListPlayer(std::string name, CCrewTag tag);
    //void ApplyCrewTag(CCrewTag crewTag);
    std::string toStr();
    std::string m_Name;
    CPlayerRankBase m_Rank;
    CCrewTag m_CrewTag;
    std::string relationtoPlayer;
private:
    int index;
};