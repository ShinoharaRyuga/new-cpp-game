#include"my_game_scene.h"
#include "../game_manager.h"
#include "scene_result.h"



void MyGameScene::initialzie() {
	camera_ = new dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT);
	camera_->pos_ = { 0, 200, -500 };

	body_ = dxe::Mesh::CreateBoxMV(50);
	body_->setTexture(dxe::Texture::CreateFromFile("graphics/box.bmp"));
	body_->flg_dbg_line_ = dxe::Mesh::fDebugLine::FLG_AXIS;
	body_->pos_ = { 0, 100, -300 };
}

void MyGameScene::update(float delta_time) {

	GameManager* mgr = GameManager::GetInstance();

	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		body_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, 1 }, body_->rot_q_) * speed_;
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		body_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, -1 }, body_->rot_q_) * speed_;
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		tnl::Vector3 axis = tnl::Vector3::TransformCoord({ 0, -1, 0 }, body_->rot_q_);
		body_->rot_q_ *= tnl::Quaternion::RotationAxis(axis, tnl::ToRadian(1));
	}
	
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		tnl::Vector3 axis = tnl::Vector3::TransformCoord({ 0, 1, 0 }, body_->rot_q_);
		body_->rot_q_ *= tnl::Quaternion::RotationAxis(axis, tnl::ToRadian(1));
	}
	
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneResult());
	}
}

void MyGameScene::render() {
	camera_->update();

	DrawGridGround(50, 20);

	body_->render(camera_);

	DrawStringEx(50, 50, -1, "my game scene");
}