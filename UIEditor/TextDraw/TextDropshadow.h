#pragma once
#include "../../ScriptHookV/types.h"
class CTextDropshadow{
public:
	CTextDropshadow(int dist, CRGBA colour);
	void changeColour(CRGBA newColour);
	void changeDistance(int newDistance);
	int getDistance();
	CRGBA getColour();
private:
	void NativeCall();
	CRGBA colour;
	int distance;
};