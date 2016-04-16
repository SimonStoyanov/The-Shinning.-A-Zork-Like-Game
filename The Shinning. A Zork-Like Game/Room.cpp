#include "Room.h"
#include "Entity.h"

Room::Room(const char* title, const char* description) : Entity(title, description, nullptr){
	type = ROOM;
}

Room::~Room(){}

void Room::Look() const{
	this->Look();
}
