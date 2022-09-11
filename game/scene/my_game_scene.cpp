#pragma once
#include"my_game_scene.h"
#include "../game_manager.h"
#include "scene_result.h"
#include "../player_tank.h"
//�e�ہ@�f�o�b�O
//#include "../bullet.h"
//
//Bullet* bullet_ = nullptr;

void MyGameScene::initialzie() {
	camera_ = new dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT);
	camera_->pos_ = { 0, 200, -500 };
	objects_.push_back(new PlayerTank(camera_));

	for (Object* obj : objects_) {
		obj->initialzie();
	}
}

void MyGameScene::update(float delta_time) {

	GameManager* mgr = GameManager::GetInstance();
	
	for (Object* obj : objects_) {
		obj->update(delta_time);
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneResult());
	}

	//�e�ۂ𔭎� (�f�o�b�O)
	/*if (tnl::Input::IsKeyDown(eKeys::KB_SPACE)) {
		bullet_ = new Bullet(camera_);
		bullet_->initialzie({ 0, 100, -300 });
	}

	if (bullet_ != nullptr) {
		bullet_->update(delta_time);
	}*/
}

void MyGameScene::render() {
	camera_->update();
	DrawGridGround(50, 20);
	DrawStringEx(50, 50, -1, "my game scene");

	for (Object* obj : objects_) {
		obj->render();
	}

	//�e�� (�f�o�b�O)
	//if (bullet_ != nullptr) {
	//	bullet_->render();
	//}
}