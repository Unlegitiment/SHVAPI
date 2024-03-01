#pragma once
#include <vector>
#include <string>
/*
* This file is for remaking the Player List's basic capablities however without using scaleforms.
* It will be somewhat limited in some degree like for example I can't DrawSprite the player's head models. however Ideally this will serve as a way to go around the Scaleforms in a regular compacity since it is just a complete combinations of squares lmao.
*/

/*For this class I'm not sure if a listplayer should have it's own box or it should be the PlayerList. 
I'm going to go with my gut and actually have each listplayer have its own box that contains the players information
Reason for this is simply because of CEO slots and the fact they can be multicoloured.
*/
class ClanTag {
public:
	ClanTag(const char* string){}

	void Draw(float scaleF);
	bool m_BIsActive;
private:
	ClanTag() : m_ClanTag("")
	{
	};
	const char* m_ClanTag;

};
class ListPlayer {
public: 
	ListPlayer();
private:
	std::string& userName;
	int rank;
	int jp;
	ClanTag* tag; //Can be null run check.
	bool isRankVisible;
	bool isJPVisible;
	bool isUserNameVisible;
	bool isUserNameSanitized;
	bool CanPlayerChangeColor;
	
	bool DoesPlayerHaveStylizedBox;
	bool isPlayerInClan;
	
	
	

};
class PlayerListHeader {
public:
	enum PlayerListIcons {

	};

private:

};
class PlayerList {
public:
private:
	std::vector<ListPlayer> m_Players;
};