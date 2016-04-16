#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

#include "p2String.h"
#include "p2Vector.h"

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	PLAYER,
	CREATURE
};

class Entity
{
private:
	// Parameters
	p2String name;
	p2String description;
public:
	// Parent
	Entity* parent;
	// Type
	EntityType type = ENTITY;
	// Vector
	p2Vector<Entity*> entities;

	// Constructor
	Entity(const p2String name, const p2String description, Entity* parent);
	// Destructor
	virtual ~Entity();
	//Methods
	const p2String getName();
	const p2String getDescription();
	const EntityType getType();
	virtual void Look();
	
};

#endif