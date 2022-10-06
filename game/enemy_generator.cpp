#include "enemy_generator.h"

EnemyGenerator::EnemyGenerator(dxe::Camera* camera, MyGameManagaer* manager) {
	camera_ = camera;
	manager_ = manager;
}

void EnemyGenerator::generator(int count) {

	for (int i = 0; i < count; i++) {
		int pos_x = GetRand(max_range_x);
		int pos_y = GetRand(max_range_y);
		int pos_z = GetRand(max_range_z);

		tnl::Vector3 pos = {(float)pos_x , (float)pos_y, (float)pos_z };
		Enemy* enemy = new Enemy(camera_);
		enemy->initialzie();
		enemy->setFirstPos(pos);
		manager_->enemies_.push_back(enemy);
	}
}