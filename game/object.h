#pragma once
#include "./scene/my_game_scene.h"
#include "model/anim_sprite3d.h"

class Object : public MyGameScene {
public:
	Object(){};
	~Object() {};

	dxe::Mesh* object_ = nullptr;

	virtual void initialzie() {};
	virtual void update(float delta_time) {};
	void render();
};
