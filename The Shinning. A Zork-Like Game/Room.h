#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room : public Entity{
public:
	Room(const p2String name, const p2String description);
	~Room();

	void Look() const;
};

#endif