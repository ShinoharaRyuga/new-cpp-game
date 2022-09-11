#pragma once
#include "object.h"

class Bullet : public Object {
	using Object::Object;
public:
	Bullet(dxe::Camera* camera);
	~Bullet() {};

	float speed_ = 10;

	void initialzie(tnl::Vector3 generate_pos);
	void update(float delta_time) override;
};
