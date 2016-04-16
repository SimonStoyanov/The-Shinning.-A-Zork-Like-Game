#include "Exit.h"

Exit::Exit(const char* name, p2String opposite_name, const char* description, Room* origin, Room* destination, bool one_way) :
	Entity(name, description, (Entity*)origin),
	destination(destination),
	opposite_name(opposite_name),
	closed(false),
	locked(false),
	key(NULL),
	one_way(one_way)
	{
		type = EXIT;

		if (one_way == false)
			destination->entities.push_back(this);
	}

Exit::~Exit(){}

void Exit::Look() const
{
	printf("%s to %s\n", &Entity::getName, opposite_name);
	printf("%s\n", &Entity::getDescription);
}
