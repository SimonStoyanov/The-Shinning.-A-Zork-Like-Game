#include "Exit.h"

Exit::Exit(const char* name, const char* description, Room* origin, Room* _destination, bool one_way) :
	Entity(name, description, (Entity*)origin),
	destination(_destination),
	closed(false),
	locked(false),
	key(NULL),
	one_way(one_way)
	{
		type = EXIT;
	}

Exit::~Exit(){}


