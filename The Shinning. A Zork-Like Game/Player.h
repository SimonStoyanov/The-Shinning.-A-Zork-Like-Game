#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Room.h"

class Player : public Entity{
public:
	Player(const p2String name, const p2String description, Room* room);
	~Player();

	void Look(p2Vector<p2String>& commands) const;
};

#endif