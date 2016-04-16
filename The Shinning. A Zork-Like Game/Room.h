#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room : public Entity{
public:
	Room(const char* name, const char* description);
	~Room();

	void Look() const;
};

#endif