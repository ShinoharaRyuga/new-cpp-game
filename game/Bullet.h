#pragma once
#include "object.h"

class Bullet : public Object {
	using Object::Object;
public:
	Bullet(dxe::Camera* camera);
	~Bullet() {};

	float speed_ = 5;

	void initialzie(tnl::Vector3 generate_pos, tnl::Quaternion rot);
	void update(float delta_time) override;
};
