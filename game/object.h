#pragma once
#include "model/anim_sprite3d.h"

class Object {
public:
	Object(dxe::Camera* camera);
	~Object() {};

	dxe::Mesh* object_ = nullptr;
	dxe::Camera* camera_ = nullptr;

	virtual void initialzie() {};
	virtual void update(float delta_time) {};
	void render();
};


