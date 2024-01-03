#pragma once
#include <iostream>
using std::string;
class CCrewTag {

public:
    enum class eCrewRank {
        LEADER = 0,
        COMMISSIONER = 1,
        LIEUTENANT = 2,
        REPRESENTATIVE = 3,
        MUSCLE = 4
    };
    /*Creates a base RSG Tag.*/
    CCrewTag();
    CCrewTag(string crewTag);
    CCrewTag(string crewTag, bool priv, bool rsg, eCrewRank rank);
    string toStr();
    //Changes whether to include the arrow at the beginning of the crewTag. 
    void change_Private(bool newData);
    //Changes whether to include the RSG typically seen in the official Rockstar Games Crew Tags. 
    void change_RSG(bool newData);
    //Applies a change to the rank of the Crew Tag
    void change_Rank(eCrewRank newRank);
private:
    /*
    This is a one time call method. Used in constructors for examples. Otherwise don't use it.
    */
    void FinalizeCrewTag(std::string& crewTag);
    bool m_hasRockstar, m_isPrivate;
    eCrewRank m_Rank;
    string m_BaseCrewTag;
};