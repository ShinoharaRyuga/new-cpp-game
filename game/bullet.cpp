#include "bullet.h"

Bullet :: Bullet(dxe::Camera* camera) : Object::Object(camera) {
	camera_ = camera;
}

void Bullet::initialzie(tnl::Vector3 generate_pos) {
	object_ = dxe::Mesh::CreateSphereMV(10);
	object_->pos_ = generate_pos;
}

void Bullet::update(float delta_time) {
	object_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, 1 }, object_->rot_q_) * speed_;
}