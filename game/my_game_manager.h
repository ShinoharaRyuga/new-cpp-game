#pragma once
#include "enemy.h";
#include <list>

class MyGameManagaer {
public:
	std::list<Enemy*> enemies_;

	void render();
};
