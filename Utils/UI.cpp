#define _CRT_SECURE_NO_WARNINGS
#define NATIVE_H
#ifdef NATIVE_H
#include "../ScriptHookV/natives.h"
#include "..\UI.h"
void UI_DrawText(const char* text, Vector2_t screen) {
    HUD::SET_TEXT_FONT(0);
    HUD::SET_TEXT_SCALE(1, 0.552);
    HUD::SET_TEXT_OUTLINE();
    HUD::SET_TEXT_DROP_SHADOW();
    HUD::SET_TEXT_CENTRE(TRUE);
    HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
    HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
    HUD::END_TEXT_COMMAND_DISPLAY_TEXT(screen.x, screen.y, 1);
}
/*
* Series of Short-hand data displayers.
* No combination string must be pre-assembled 
* @param (any) text,
* @param int decimalPlaces (Only for Float Func)
*/
void UI_DrawNotificationSTR(char* text) {
    HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
    HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
    HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);
}
/*
 SEE: UI_DrawNotificationSTR(char* text);
*/
void UI_DrawNotificationF(float text, int decimalPlaces) {
    HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("NUMBER");
    HUD::ADD_TEXT_COMPONENT_FLOAT(text, decimalPlaces);
    HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);
}
/*
 SEE: UI_DrawNotificationSTR(char* text);
*/
void UI_DrawNotificationI(int i) {
    HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("NUMBER");
    HUD::ADD_TEXT_COMPONENT_INTEGER(i);
    HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);
}
/*
* @brief By default this defines a basic Text Message esk notifcation.
* @brief This as well uses a headshot of the player's current character.
* @brief As well this cleans up whatever is specified in the params
* @param Notification *ptr - The Notification To draw and cleanup.
*/
void UI_DrawNotificationTXD(Notification* notification) {
    notification->handle = PED::REGISTER_PEDHEADSHOT(PLAYER::PLAYER_PED_ID());
    while (!PED::IS_PEDHEADSHOT_READY(notification->handle) || !PED::IS_PEDHEADSHOT_VALID(notification->handle)) {
        notification->txd->isDictRequested = FALSE;
        WAIT(0);
    }
    notification->txd->isDictRequested = TRUE;
    const char* txd = PED::GET_PEDHEADSHOT_TXD_STRING(notification->handle);
    notification->isHeadshot = TRUE;
    strncpy(notification->txd->txdName, txd, sizeof(notification->txd->txdName));
    strncpy(notification->txd->txdDict, txd, sizeof(notification->txd->txdDict));
    notification->txd->isDictRequested = TRUE;

    HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
    HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(notification->TEXT);
    HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(notification->txd->txdName, notification->txd->txdName, FALSE, 0, notification->TITLE, notification->HEADER);
    HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, TRUE);
    PED::UNREGISTER_PEDHEADSHOT(notification->handle);
    UI_n_Destroy(notification);
}
/*
* See: UI_DrawNotificationTXD(Notification* notification);
* @brief DOES NOT CLEANUP PARAM
* @param Notification notification - Notification To Be Drawn.
*/
void UI_DrawNotificationTXD_Ex(Notification* notification) {
    if (notification == NULL) return;
    notification->handle = PED::REGISTER_PEDHEADSHOT(PLAYER::PLAYER_PED_ID());
    while (!PED::IS_PEDHEADSHOT_READY(notification->handle) || !PED::IS_PEDHEADSHOT_VALID(notification->handle)) {
        notification->txd->isDictRequested = FALSE;
        WAIT(0);
    }
    notification->txd->isDictRequested = TRUE;
    const char* txd = PED::GET_PEDHEADSHOT_TXD_STRING(notification->handle);

    strncpy(notification->txd->txdName, txd, sizeof(notification->txd->txdName));
    strncpy(notification->txd->txdDict, txd, sizeof(notification->txd->txdDict));
    notification->txd->isDictRequested = TRUE;

    HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
    HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(notification->TEXT);
    HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(txd, txd, FALSE, 0, notification->TITLE, notification->HEADER);
    HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, TRUE);
    PED::UNREGISTER_PEDHEADSHOT(notification->handle);
}
void UI_DRAWBOX(RGBA_t rgba, Vector2_t screen, float width, float height)
{
    GRAPHICS::DRAW_RECT(screen.x, screen.y, width, height, (int)rgba.r, (int)rgba.g, (int)rgba.b, (int)rgba.a, TRUE);
}
Notification* UI_n_CreateM(char* title, char* header, char* msg)
{
    Notification *newNotif = (Notification*)malloc(sizeof(Notification));
    if (newNotif == NULL) return NULL;
    strncpy(newNotif->TITLE, title, sizeof(newNotif->TITLE) - 2);
    strncpy(newNotif->HEADER, header, sizeof(newNotif->HEADER) - 2);
    strncpy(newNotif->TEXT, msg, sizeof(newNotif->TEXT) - 2);
    newNotif->TITLE[63] = '\0';
    newNotif->HEADER[63] = '\0';
    newNotif->TEXT[63] = '\0';
    newNotif->handle = 0;
    newNotif->isHeadshot = FALSE;
    newNotif->txd = txd_Create(NULL, NULL);
    return newNotif;
}
Notification* UI_n_CreateDraw(char* title, char* header, char* msg)
{
    Notification* notif = UI_n_CreateM(title, header, msg);
    UI_DrawNotificationTXD_Ex(notif);
    return notif;
}
void UI_n_Destroy(Notification* ptr)
{
    free(ptr->txd);
    free(ptr);
}
#endif // NATIVE_H
#undef NATIVE_H