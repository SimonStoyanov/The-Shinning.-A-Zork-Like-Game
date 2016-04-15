#include "Entity.h"

// Constructor
Entity::Entity(const p2String name, const p2String description, Entity* parent) :
name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->entities.push_back(this);
}
// Destructor
Entity::~Entity(){};

// Get Entity Name
const p2String Entity::getName(){
	return name;
}
// Get Entity Description
const p2String Entity::getDescription(){
	return description;
}
// Get Entity Type
const EntityType Entity::getType(){
	return type;
}
// Print Entity's Name and Description
void Entity::Look(){
	printf("%s\n", name);
	printf("%s\n", description);
}
