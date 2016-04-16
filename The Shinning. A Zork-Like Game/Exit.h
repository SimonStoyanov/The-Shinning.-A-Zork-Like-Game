#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"
#include "Room.h"

class Room;

class Exit : public Entity{
private:
	bool one_way;
	bool closed;
	bool locked;
	p2String opposite_name;
	Room* destination;
	Entity* key;
public:
	Exit(const char* name, p2String opposite_name, const char* description, Room* origin, Room* destination, bool one_way = false);
	~Exit();

	void Look() const;

};


#endif