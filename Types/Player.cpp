#include "E:\ScriptHookV\inc\natives.h"
#include "..\Types.h"
#define MAX_PLAYERNAME 64
typedef struct player_t_{
	int handle;
	Vector3 position;
	float heading;
	char networkName[MAX_PLAYERNAME];
	Hash pedModel;
}Player_S;

Player_H* __INIT_PLAYER__(Player player) {
	Player_S* s = (Player_S*)player;
	s->handle = player;
	s->heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
	s->pedModel = ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID());
	s->position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	strncpy(s->networkName, NETWORK::NETWORK_PLAYER_GET_NAME(player),sizeof(s->networkName));
	return (Player_H*)s;
}
