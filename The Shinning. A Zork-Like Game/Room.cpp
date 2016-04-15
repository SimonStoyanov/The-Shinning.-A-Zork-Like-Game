#include "Room.h"
#include "Entity.h"

Room::Room(const p2String title, const p2String description) : Entity(title, description, NULL){
	type = ROOM;
}

Room::~Room(){}

void Room::Look() const{
	this->Look();
}
