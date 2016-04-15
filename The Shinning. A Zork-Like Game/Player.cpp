#include "Player.h"

Player::Player(const p2String name, const p2String description, Room* room) :
Entity(name, description, (Entity*)room)
{
	type = PLAYER;
}

Player::~Player(){}

void Player::Look(const p2Vector<p2String>& commands) const{
	printf("%s\n", &Entity::getName);
	printf("%s\n", &Entity::getDescription);
}