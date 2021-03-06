#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Player : public Entity{
private:
	Room* currentRoom;
	Item* inventory;
public:
	Player(const char* name, const char* description, Room* parent);
	~Player();

	void Look(p2Vector<p2String>& commands) const; 
	void Go(p2Vector<p2String>& commands);
	void ChangeDoor(p2Vector<p2String>& commands);
};

#endif