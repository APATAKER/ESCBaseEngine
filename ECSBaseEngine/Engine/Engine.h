#pragma once

#include "../Systems/system.h" // TO BE changed : change to the systems you want

class Engine
{
public:
	Engine();
	virtual ~Engine();

	bool Initialize();
	bool Destroy();
	void Run();
	void AddSystem(System* s);

private:
	void Update();
	void Draw();

	std::vector<System*> mSystemList;

};