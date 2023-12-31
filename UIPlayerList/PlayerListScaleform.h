#pragma once
#include <string>

using std::string;
enum class eHudColours : int{
	HUD_COLOUR_INVALID = -1,
	HUD_COLOUR_PURE_WHITE = 0,
	HUD_COLOUR_WHITE,
	HUD_COLOUR_BLACK,
	HUD_COLOUR_GREY,
	HUD_COLOUR_GREYLIGHT,
	HUD_COLOUR_GREYDARK,
	HUD_COLOUR_RED,
	HUD_COLOUR_REDLIGHT,
	HUD_COLOUR_REDDARK,
	HUD_COLOUR_BLUE,
	HUD_COLOUR_BLUELIGHT,
	HUD_COLOUR_BLUEDARK,
	HUD_COLOUR_YELLOW,
	HUD_COLOUR_YELLOWLIGHT,
	HUD_COLOUR_YELLOWDARK,
	HUD_COLOUR_ORANGE,
	HUD_COLOUR_ORANGELIGHT,
	HUD_COLOUR_ORANGEDARK,
	HUD_COLOUR_GREEN,
	HUD_COLOUR_GREENLIGHT,
	HUD_COLOUR_GREENDARK,
	HUD_COLOUR_PURPLE,
	HUD_COLOUR_PURPLELIGHT,
	HUD_COLOUR_PURPLEDARK,
	HUD_COLOUR_PINK,
	HUD_COLOUR_RADAR_HEALTH,
	HUD_COLOUR_RADAR_ARMOUR,
	HUD_COLOUR_RADAR_DAMAGE,
	HUD_COLOUR_NET_PLAYER1,
	HUD_COLOUR_NET_PLAYER2,
	HUD_COLOUR_NET_PLAYER3,
	HUD_COLOUR_NET_PLAYER4,
	HUD_COLOUR_NET_PLAYER5,
	HUD_COLOUR_NET_PLAYER6,
	HUD_COLOUR_NET_PLAYER7,
	HUD_COLOUR_NET_PLAYER8,
	HUD_COLOUR_NET_PLAYER9,
	HUD_COLOUR_NET_PLAYER10,
	HUD_COLOUR_NET_PLAYER11,
	HUD_COLOUR_NET_PLAYER12,
	HUD_COLOUR_NET_PLAYER13,
	HUD_COLOUR_NET_PLAYER14,
	HUD_COLOUR_NET_PLAYER15,
	HUD_COLOUR_NET_PLAYER16,
	HUD_COLOUR_NET_PLAYER17,
	HUD_COLOUR_NET_PLAYER18,
	HUD_COLOUR_NET_PLAYER19,
	HUD_COLOUR_NET_PLAYER20,
	HUD_COLOUR_NET_PLAYER21,
	HUD_COLOUR_NET_PLAYER22,
	HUD_COLOUR_NET_PLAYER23,
	HUD_COLOUR_NET_PLAYER24,
	HUD_COLOUR_NET_PLAYER25,
	HUD_COLOUR_NET_PLAYER26,
	HUD_COLOUR_NET_PLAYER27,
	HUD_COLOUR_NET_PLAYER28,
	HUD_COLOUR_NET_PLAYER29,
	HUD_COLOUR_NET_PLAYER30,
	HUD_COLOUR_NET_PLAYER31,
	HUD_COLOUR_NET_PLAYER32,

	HUD_COLOUR_SIMPLEBLIP_DEFAULT,

	HUD_COLOUR_MENU_BLUE,
	HUD_COLOUR_MENU_GREY_LIGHT,
	HUD_COLOUR_MENU_BLUE_EXTRA_DARK,
	HUD_COLOUR_MENU_YELLOW,
	HUD_COLOUR_MENU_YELLOW_DARK,
	HUD_COLOUR_MENU_GREEN,
	HUD_COLOUR_MENU_GREY,
	HUD_COLOUR_MENU_GREY_DARK,

	HUD_COLOUR_MENU_HIGHLIGHT,
	HUD_COLOUR_MENU_STANDARD,
	HUD_COLOUR_MENU_DIMMED,
	HUD_COLOUR_MENU_EXTRA_DIMMED,

	HUD_COLOUR_BRIEF_TITLE,

	HUD_COLOUR_MID_GREY_MP,

	HUD_COLOUR_NET_PLAYER1_DARK,
	HUD_COLOUR_NET_PLAYER2_DARK,
	HUD_COLOUR_NET_PLAYER3_DARK,
	HUD_COLOUR_NET_PLAYER4_DARK,
	HUD_COLOUR_NET_PLAYER5_DARK,
	HUD_COLOUR_NET_PLAYER6_DARK,
	HUD_COLOUR_NET_PLAYER7_DARK,
	HUD_COLOUR_NET_PLAYER8_DARK,
	HUD_COLOUR_NET_PLAYER9_DARK,
	HUD_COLOUR_NET_PLAYER10_DARK,
	HUD_COLOUR_NET_PLAYER11_DARK,
	HUD_COLOUR_NET_PLAYER12_DARK,
	HUD_COLOUR_NET_PLAYER13_DARK,
	HUD_COLOUR_NET_PLAYER14_DARK,
	HUD_COLOUR_NET_PLAYER15_DARK,
	HUD_COLOUR_NET_PLAYER16_DARK,
	HUD_COLOUR_NET_PLAYER17_DARK,
	HUD_COLOUR_NET_PLAYER18_DARK,
	HUD_COLOUR_NET_PLAYER19_DARK,
	HUD_COLOUR_NET_PLAYER20_DARK,
	HUD_COLOUR_NET_PLAYER21_DARK,
	HUD_COLOUR_NET_PLAYER22_DARK,
	HUD_COLOUR_NET_PLAYER23_DARK,
	HUD_COLOUR_NET_PLAYER24_DARK,
	HUD_COLOUR_NET_PLAYER25_DARK,
	HUD_COLOUR_NET_PLAYER26_DARK,
	HUD_COLOUR_NET_PLAYER27_DARK,
	HUD_COLOUR_NET_PLAYER28_DARK,
	HUD_COLOUR_NET_PLAYER29_DARK,
	HUD_COLOUR_NET_PLAYER30_DARK,
	HUD_COLOUR_NET_PLAYER31_DARK,
	HUD_COLOUR_NET_PLAYER32_DARK,
	HUD_COLOUR_BRONZE,
	HUD_COLOUR_SILVER,
	HUD_COLOUR_GOLD,
	HUD_COLOUR_PLATINUM,
	HUD_COLOUR_GANG1,
	HUD_COLOUR_GANG2,
	HUD_COLOUR_GANG3,
	HUD_COLOUR_GANG4,
	HUD_COLOUR_SAME_CREW,
	HUD_COLOUR_FREEMODE,
	HUD_COLOUR_PAUSE_BG,
	HUD_COLOUR_FRIENDLY,
	HUD_COLOUR_ENEMY,
	HUD_COLOUR_LOCATION,
	HUD_COLOUR_PICKUP,
	HUD_COLOUR_PAUSE_SINGLEPLAYER,
	HUD_COLOUR_FREEMODE_DARK,
	HUD_COLOUR_INACTIVE_MISSION,
	HUD_COLOUR_DAMAGE,
	HUD_COLOUR_PINKLIGHT,
	HUD_COLOUR_PM_MITEM_HIGHLIGHT,
	HUD_COLOUR_SCRIPT_VARIABLE,		//	marked by ~v~. Can be altered with the SET_SCRIPT_VARIABLE_HUD_COLOUR script command
	HUD_COLOUR_YOGA,
	HUD_COLOUR_TENNIS,
	HUD_COLOUR_GOLF,
	HUD_COLOUR_SHOOTING_RANGE,
	HUD_COLOUR_FLIGHT_SCHOOL,
	HUD_COLOUR_NORTH_BLUE,
	HUD_COLOUR_SOCIAL_CLUB,
	HUD_COLOUR_PLATFORM_BLUE,
	HUD_COLOUR_PLATFORM_GREEN,
	HUD_COLOUR_PLATFORM_GREY,
	HUD_COLOUR_FACEBOOK_BLUE,
	HUD_COLOUR_INGAME_BG,
	HUD_COLOUR_DARTS,
	HUD_COLOUR_WAYPOINT,
	HUD_COLOUR_MICHAEL,
	HUD_COLOUR_FRANKLIN,
	HUD_COLOUR_TREVOR,
	HUD_COLOUR_GOLF_P1,
	HUD_COLOUR_GOLF_P2,
	HUD_COLOUR_GOLF_P3,
	HUD_COLOUR_GOLF_P4,
	HUD_COLOUR_WAYPOINTLIGHT,
	HUD_COLOUR_WAYPOINTDARK,
	HUD_COLOUR_PANEL_LIGHT,
	HUD_COLOUR_MICHAEL_DARK,
	HUD_COLOUR_FRANKLIN_DARK,
	HUD_COLOUR_TREVOR_DARK,
	HUD_COLOUR_OBJECTIVE_ROUTE,
	HUD_COLOUR_PAUSEMAP_TINT,
	HUD_COLOUR_PAUSE_DESELECT,
	HUD_COLOUR_PM_WEAPONS_PURCHASABLE,
	HUD_COLOUR_PM_WEAPONS_LOCKED,
	HUD_COLOUR_END_SCREEN_BG,
	HUD_COLOUR_CHOP,
	HUD_COLOUR_PAUSEMAP_TINT_HALF,
	HUD_COLOUR_NORTH_BLUE_OFFICIAL,
	HUD_COLOUR_SCRIPT_VARIABLE_2,		//	marked by ~u~. Can be altered with the SET_SECOND_SCRIPT_VARIABLE_HUD_COLOUR script command
	HUD_COLOUR_H,
	HUD_COLOUR_HDARK,
	HUD_COLOUR_T,
	HUD_COLOUR_TDARK,
	HUD_COLOUR_HSHARD,
	HUD_COLOUR_CONTROLLER_MICHAEL,
	HUD_COLOUR_CONTROLLER_FRANKLIN,
	HUD_COLOUR_CONTROLLER_TREVOR,
	HUD_COLOUR_CONTROLLER_CHOP,
	HUD_COLOUR_VIDEO_EDITOR_VIDEO,
	HUD_COLOUR_VIDEO_EDITOR_AUDIO,
	HUD_COLOUR_VIDEO_EDITOR_TEXT,
	HUD_COLOUR_HB_BLUE,
	HUD_COLOUR_HB_YELLOW,
	HUD_COLOUR_VIDEO_EDITOR_SCORE,

	HUD_COLOUR_VIDEO_EDITOR_AUDIO_FADEOUT,
	HUD_COLOUR_VIDEO_EDITOR_TEXT_FADEOUT,
	HUD_COLOUR_VIDEO_EDITOR_SCORE_FADEOUT,

	HUD_COLOUR_HEIST_BACKGROUND,

	HUD_COLOUR_VIDEO_EDITOR_AMBIENT,
	HUD_COLOUR_VIDEO_EDITOR_AMBIENT_FADEOUT,
	HUD_COLOUR_GANG_BOSS,
	HUD_COLOUR_GOON,
	HUD_COLOUR_BOSS,
	HUD_COLOUR_LOW_FLOW,
	HUD_COLOUR_LOW_FLOW_DARK,
	HUD_COLOUR_G1,
	HUD_COLOUR_G2,
	HUD_COLOUR_G3,
	HUD_COLOUR_G4,
	HUD_COLOUR_G5,
	HUD_COLOUR_G6,
	HUD_COLOUR_G7,
	HUD_COLOUR_G8,
	HUD_COLOUR_G9,
	HUD_COLOUR_G10,
	HUD_COLOUR_G11,
	HUD_COLOUR_G12,
	HUD_COLOUR_G13,
	HUD_COLOUR_G14,
	HUD_COLOUR_G15,

	HUD_COLOUR_ADVERSARY,

	HUD_COLOUR_DEGEN_RED,
	HUD_COLOUR_DEGEN_YELLOW,
	HUD_COLOUR_DEGEN_GREEN,
	HUD_COLOUR_DEGEN_CYAN,
	HUD_COLOUR_DEGEN_BLUE,
	HUD_COLOUR_DEGEN_MAGENTA,

	HUD_COLOUR_STUNT_1,
	HUD_COLOUR_STUNT_2,

	HUD_COLOUR_SPECIAL_RACE_SERIES,
	HUD_COLOUR_SPECIAL_RACE_SERIES_DARK,

	HUD_COLOUR_CHALLENGE_SERIES,
	HUD_COLOUR_CHALLENGE_SERIES_DARK,

	HUD_COLOUR_TECH_GREEN,
	HUD_COLOUR_TECH_GREEN_DARK,
	HUD_COLOUR_TECH_RED,
	HUD_COLOUR_TECH_GREEN_VERY_DARK,

	HUD_COLOUR_PLACEHOLDER_01,
	HUD_COLOUR_PLACEHOLDER_02,
	HUD_COLOUR_PLACEHOLDER_03,
	HUD_COLOUR_PLACEHOLDER_04,
	HUD_COLOUR_PLACEHOLDER_05,
	HUD_COLOUR_PLACEHOLDER_06,
	HUD_COLOUR_PLACEHOLDER_07,
	HUD_COLOUR_PLACEHOLDER_08,
	HUD_COLOUR_PLACEHOLDER_09,
	HUD_COLOUR_PLACEHOLDER_10,

	HUD_COLOUR_JUNK_ENERGY,

	HUD_COLOUR_MAX_COLOURS
};

/*
Base PlayerList implementation with the UI.
Does not save data btw. Your as there is no implementation for it.
Create a Wrapper for it or suffer *shrug*
*/
class CPlayerListScaleform {
public:
	void CLEAN();
	CPlayerListScaleform& operator=(const CPlayerListScaleform&) = delete;
	enum class PlayerListIcons {
		NONE = 0,
		ACTIVE_HEADSET = 47,
		INACTIVE_HEADSET = 48,
		MUTED_HEADSET = 49,
		KICK = 64,
		RANK_FREEMODE = 65,
		SPECTATOR = 66,
		LOBBY_DRIVER = 79,
		LOBBY_CODRIVER = 80,
		BOUNTY = 115,
		DEAD = 116,
		DPAD_GANG_CEO = 121,
		DPAD_GANG_BIKER = 122,
		DPAD_DOWN_TARGET = 123
	};
	enum class JPTypes {
		NOJPSYMBOL = 0,
		JPSYMBOL = 1,
		NOJP = 2
	};
	CPlayerListScaleform();
	void DEBUG();
	void COLLAPSE();
	void SET_ICON(int index, int iconEnum, int rank);
	void DISPLAY_MIC();
	void SET_TITLE(string str, string str2, int icon);
	void SET_DATA_SLOT(int viewIndex, int rank, const char* name, eHudColours colour, const char* crewTag, JPTypes jpType, const char* txdDict, const char* txdImg, char* relationToViewer, PlayerListIcons icon = PlayerListIcons::RANK_FREEMODE, int mugshotTxd = 0, int jp = 0);
	void UPDATE_SLOT(int viewIndex, int rank, const char* name, eHudColours colour, const char* crewTag, JPTypes jpType, const char* txdDict, const char* txdImg, char* relationToViewer, PlayerListIcons icon = PlayerListIcons::RANK_FREEMODE, int mugshotTxd = 0, int jp = 0);
	void DISPLAY_VIEW();
	void SET_DATA_SLOT_EMPTY(int viewIndex, int itemIndex);
	void TXD_HAS_LOADED(const char* textDict, bool success, int uuid);
	void TXD_ALREADY_LOADED(const char* textdict, int uuid);
	void ADD_TXT_REF_RESPONSE(const char* textdict, int uuid, bool success);

	int getHandle();

private:
	int handle;
	const string SCALEFORM_TITLE_NAME = "MP_MM_CARD_FREEMODE";
protected:
};