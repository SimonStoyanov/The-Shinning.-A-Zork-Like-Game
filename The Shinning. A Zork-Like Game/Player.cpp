#include "Player.h"
#include "Exit.h"

Player::Player(const char* name, const char* description, Room* room) : Entity(name, description, room)
{
	type = PLAYER;
}

Player::~Player(){}

void Player::Look(p2Vector<p2String>& commands) const{
	parent->Look();
}