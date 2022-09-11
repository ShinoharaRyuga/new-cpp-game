#pragma once
#include "scene_base.h"
#include "../model/anim_sprite3d.h"
#include "../object.h"

class MyGameScene : public SceneBase {
public:
	MyGameScene() {}
	~MyGameScene() {
		delete camera_;
	}

	dxe::Camera* camera_ = nullptr;
	std::list<Object*> objects_;

	float speed_ = 1;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;

};
