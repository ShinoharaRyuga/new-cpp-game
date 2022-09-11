#pragma once
#include "object.h"
#include "bullet.h"	
#include "./scene/my_game_scene.h"

class PlayerTank : public Object {
	using Object::Object;
public:
	PlayerTank(dxe::Camera* camera);

	tnl::Vector3 muzzle_ = {0, 0, 0};
	MyGameScene* game_scene_ = nullptr;

	int hp_ = 10;
	int speed_ = 3;

	void getGameScene(MyGameScene* game_scene);
	void initialzie() override;
	void update(float delta_time) override;
};
