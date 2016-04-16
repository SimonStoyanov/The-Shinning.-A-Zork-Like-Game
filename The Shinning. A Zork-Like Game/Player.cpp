#include "Player.h"
#include "Exit.h"

Player::Player(const p2String name, const p2String description, Room* room) :
Entity(name, description, (Entity*)room)
{
	type = PLAYER;
}

Player::~Player(){}

void Player::Look(p2Vector<p2String>& commands) const{
	parent->Look();
}