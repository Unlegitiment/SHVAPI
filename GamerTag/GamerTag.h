#pragma once
#include <string>
using std::string;
class CGamerTag { //Model
public:
	CGamerTag(int pedToAttach, string usrName, bool isRockstarClan);
	void Init();
private:
	friend class CGamerTagMgr;
	string usrName;
	int pedToAttach;
	bool pointedTag;
	bool isRClan;
	string clanTag;
	int flags;
	int handle;
};
class CGamerTagMgr { //make static
	static CGamerTagMgr& GetInstance();
	int GetHandle(CGamerTag& tag);
};
class CGamerTagView {
public:
	void Draw(CGamerTag& gamerTag);
private:

}; 