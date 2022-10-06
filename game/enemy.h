#pragma once
#include"object.h";

class Enemy : public Object {
	using Object::Object;
public:
	Enemy(dxe::Camera* camera);

	tnl::Vector3 pos_ = {0, 0, 0};
	
	int hp_ = 1;

	void initialzie() override;
	void update(float delta_time) override;
	void getDamege(int damege);
	void setFirstPos(tnl::Vector3 firstPos);
};
