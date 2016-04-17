#include "Player.h"
#include "Entity.h"
#include "World.h"
#include "Exit.h"

Player::Player(const char* name, const char* description, Room* parent) : Entity(name, description, parent),
	currentRoom(parent)
	{
		type = PLAYER;
	}

Player::~Player(){}

void Player::Look(p2Vector<p2String>& commands) const{
	printf("----%s----", parent->getName());
	printf("\n%s\n", parent->getDescription());
}

void Player::Go(p2Vector<p2String>& commands){
	if (commands.size() > (uint)1){
		
	}
	else {
		Exit* aux = currentRoom->GetExit(commands[0]);
		if (aux != nullptr && aux->getName() == commands[0]){
			parent = aux->get_Destination();
		}
		else printf("There is no room in direction %s.\n", commands[0].c_str());
	}
}