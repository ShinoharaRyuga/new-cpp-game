#pragma once
#include "enemy.h";
#include "my_game_manager.h"

class EnemyGenerator {
public:
	EnemyGenerator(dxe::Camera* camera, MyGameManagaer* manager);

	dxe::Camera* camera_ = nullptr;
	MyGameManagaer* manager_ = nullptr;
	int max_range_x = 500;
	int max_range_y = 100;
	int max_range_z = 500;

	void generator(int count);
};
