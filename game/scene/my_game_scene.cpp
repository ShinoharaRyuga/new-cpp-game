#pragma once
#include"my_game_scene.h"
#include "../game_manager.h"
#include "scene_result.h"
#include "../player_tank.h"
#include "../enemy.h"
#include "../enemy_generator.h"

void MyGameScene::initialzie() {
	manager_ = new MyGameManagaer();
	camera_ = new dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT);
	camera_->pos_ = { 0, 200, -500 };
	PlayerTank* player_tank = new PlayerTank(camera_);
	player_tank->getGameScene(this);
	objects_.push_back(player_tank);
	EnemyGenerator* enemyGenerator = new EnemyGenerator(camera_, manager_);
	enemyGenerator->generator(5);
	
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
}

void MyGameScene::render() {
	camera_->update();
	DrawGridGround(camera_, 50, 20);
	DrawStringEx(50, 50, -1, "my game scene");

	for (Object* obj : objects_) {
		obj->render();
	}

	manager_->render();
}