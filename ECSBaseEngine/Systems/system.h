#pragma once

#include "../Helpers/Includes.h"
#include "../Entities/EntityManager.h"

class System
{
public:

	virtual ~System();

	virtual void Process() = 0;

protected:
	System(std::string name);
	std::string systemName;

private:
	System();

};

System::System(std::string name)
{
	this->systemName = name;
}

System::System()
{
}

System::~System()
{
}