#include "player_tank.h"

void PlayerTank::initialzie() {
	object_ = dxe::Mesh::CreateBoxMV(50);
	object_->setTexture(dxe::Texture::CreateFromFile("graphics/box.bmp"));
	object_->flg_dbg_line_ = dxe::Mesh::fDebugLine::FLG_AXIS;
	object_->pos_ = { 0, 100, -300 };
}

void PlayerTank::update(float delta_time) {
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		object_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, 1 }, object_->rot_q_) * speed_;
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		object_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, -1 }, object_->rot_q_) * speed_;
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		tnl::Vector3 axis = tnl::Vector3::TransformCoord({ 0, -1, 0 }, object_->rot_q_);
		object_->rot_q_ *= tnl::Quaternion::RotationAxis(axis, tnl::ToRadian(1));
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		tnl::Vector3 axis = tnl::Vector3::TransformCoord({ 0, 1, 0 }, object_->rot_q_);
		object_->rot_q_ *= tnl::Quaternion::RotationAxis(axis, tnl::ToRadian(1));
		//下記で方向がとれる
		//body_->rot_q_.getEuler().z;
	}

	//弾丸を発射
	if (tnl::Input::IsKeyDown(eKeys::KB_SPACE)) {
		
	}
}