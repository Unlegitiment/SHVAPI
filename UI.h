#pragma once
#include "utils.h"
#include <string>
/*
* ~~~DRAW Functions~~~~
* IMPORTANT: Draw Functions must be called every tick or else they draw once.
*/

/*
* @param char* text - Text must be pre-combined
* @param Vector2 screen - Must be normalized (a.k.a between values of 0-1)
*/
extern void UI_DrawText(const char* text, Vector2_t screen);
extern void UI_DrawNotificationSTR(char* text);
extern void UI_DrawNotificationI(int i);
extern void UI_DrawNotificationF(float text, int decimalPlaces = 5);
extern void UI_DrawNotificationTXD(Notification *noti);
extern void UI_DrawNotificationTXD_Ex(Notification *noti);

extern void UI_DRAWBOX(RGBA_t rgba, Vector2_t screen, float width, float height);
/*
* @param char* title	Typically represented by the NPC's name
* @param char* header	The actual subject of something if it's a Email
* @param char* msg		The Content of the message.
* @return New Instance of Notification Object. (MALLOC)
*/
extern Notification* UI_n_CreateM(char* title, char* header, char* msg);
/*
* @brief Draws the Notification and creates a new instance of the object. (Relies on other functions)
* @param char* title	Typically represented by the NPC's name
* @param char* header	The actual subject of something if it's a Email
* @param char* msg		The Content of the message.
* @return New Instance of Notification Object. (MALLOC)
*/
extern Notification* UI_n_CreateDraw(char* title, char* header, char* msg);
/*
* @brief Free(s) the allocated Memory for the Notifications
* @param Notification* ptr - The block in which a single instance occupies.
*/
extern void UI_n_Destroy(Notification* ptr);

class CNotification {
public:
	//Factory
	CNotification(std::string str);
	static CNotification CreateAndDraw(std::string str);
	//Base stuff
	int GetNotifHandle();
	void changeText(std::string newStr);
	void Draw(); 
private:
	std::string text;
};
class CTxdNotication : public CNotification{

};
class CVersusNotification : public CNotification {

};
