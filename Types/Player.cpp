#include "../ScriptHookV/natives.h"
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
	s->heading = ENTITY::GET_ENTITY_HEADING(player);
	s->pedModel = ENTITY::GET_ENTITY_MODEL(player);
	s->position = ENTITY::GET_ENTITY_COORDS(player, 1);
	strncpy(s->networkName, NETWORK::NETWORK_PLAYER_GET_NAME(player),sizeof(s->networkName));
	return (Player_H*)s;
}