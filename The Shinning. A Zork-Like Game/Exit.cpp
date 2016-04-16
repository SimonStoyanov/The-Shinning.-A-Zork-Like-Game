#include "Exit.h"

Exit::Exit(const p2String name, const p2String opposite_name, const p2String description, Room* origin, Room* destination, bool one_way) :
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
