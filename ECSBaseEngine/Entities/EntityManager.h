#pragma once

#include "../Helpers/Includes.h"
#include "Entity.h"

class EntityManager
{
public:
	EntityManager();
	virtual ~EntityManager();

	static Entity* CreateEntity();
	static std::vector<Entity*> entityList;

private:

};

std::vector<Entity*> EntityManager::entityList;

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

Entity* EntityManager::CreateEntity()
{
	Entity* e = new Entity();
	//validate that the entity was created??

	EntityManager::entityList.push_back(e);
	return e;

}
