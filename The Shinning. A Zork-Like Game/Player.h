#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Room.h"

class Player : public Entity{
public:
	Player() : Entity("a", "ab", nullptr){};
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Look(p2Vector<p2String>& commands) const;
};

#endif