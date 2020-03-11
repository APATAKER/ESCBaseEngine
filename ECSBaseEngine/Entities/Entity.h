#pragma once
#include "../Components/Component.h"
#include"../Helpers/Includes.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	template<class T> T* AddComponent();
	template<class T> T* GetComponent();
	bool RemoveComponent(Component* c);
	template<class T> bool HasComponent();

	ui id;
	std::string name;
	//Component list
	std::vector<Component*> componentList;


private:

};

Entity::Entity()
{
	this->id = 0;

	this->name = "";
}

Entity::~Entity()
{
}

bool Entity::RemoveComponent(Component* c)
{
	int remove_index = -1;
	for (ui i = 0; i < componentList.size(); i++)
	{
		if (componentList.at(i) == c) {
			remove_index = i;
			SAFE_DELETE(componentList.at(i));

		}
	}
	//remove from vector
	if (remove_index != -1) {
		componentList.erase(componentList.begin() + remove_index);
	}
	return true;
}

template<class T>
T* Entity::AddComponent()
{
	T* c = new T();
	if (dynamic_cast<Component*>(c) == 0) {
		return 0;
	}

	this->componentList.push_back(c);

	return c;

}

template<class T>
T* Entity::GetComponent()
{
	for (ui i = 0; i < componentList.size(); i++)
	{
		if (dynamic_cast<T*>(componentList.at(i)) != 0) {
			return dynamic_cast<T*>(componentList.at(i));
		}
	}
	//Entity does not contain specified component.
	return 0;
}

template<class T>
bool Entity::HasComponent()
{
	for (ui i = 0; i < componentList.size(); i++)
	{
		if (dynamic_cast<T*>(componentList.at(i)) != 0) {
			//Component found
			return true;
		}
	}
	//Entity does not contain specified component.
	return false;
}
