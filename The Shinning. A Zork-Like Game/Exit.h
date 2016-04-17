#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"

class Room;

class Exit : public Entity{
private:
	bool one_way;
	bool closed;
	bool locked;
	Room* destination;
	Entity* key;
public:
	// Constructor and Destructor
	Exit(const char* name, const char* description, Room* origin, Room* destination, bool one_way = false);
	~Exit();
	// Methods
	bool get_OneWay(){ return one_way; }
	bool ger_Close(){ return closed; }
	bool get_Locked(){ return locked; }
	Room* get_Destination(){ return destination; }
	Entity* get_Key(){ return key; }
};


#endif