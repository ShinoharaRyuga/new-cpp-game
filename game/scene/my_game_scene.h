#pragma once
#include "scene_base.h"
#include "../model/anim_sprite3d.h"
#include "../object.h"
#include "../my_game_manager.h"

class MyGameScene : public SceneBase {
public:
	MyGameScene() {}
	~MyGameScene() {
		delete camera_;
	}

	dxe::Camera* camera_ = nullptr;
	std::list<Object*> objects_;
	MyGameManagaer* manager_ = nullptr;


	float speed_ = 1;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;

};
