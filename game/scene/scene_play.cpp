#include "../game_manager.h"
#include "scene_play.h"
#include "scene_result.h"

void ScenePlay::initialzie() {
	camera_ = new dxe::Camera( DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT );
	camera_->pos_ = { 0, 150, -300 };

	sprite_ = new AnimSprite3D();
	sprite_->regist(32, 48, "walk_front", "graphics/c1_anim_down.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 48, 0);
	sprite_->regist(32, 48, "walk_depth", "graphics/c1_anim_up.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 48, 0);
	sprite_->regist(32, 48, "walk_left", "graphics/c1_anim_left.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 48, 0);
	sprite_->regist(32, 48, "walk_right", "graphics/c1_anim_right.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 48, 0);

	sprite_->setCurrentAnim("walk_front");

}

void ScenePlay::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_UP)) sprite_->setCurrentAnim("walk_depth");
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_DOWN)) sprite_->setCurrentAnim("walk_front");
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) sprite_->setCurrentAnim("walk_left");
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT)) sprite_->setCurrentAnim("walk_right");

	if (tnl::Input::IsKeyDown(eKeys::KB_UP)) sprite_->pos_ += {0, 0, 1};
	if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) sprite_->pos_ += {0, 0, -1};
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) sprite_->pos_ += {-1, 0, 0};
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) sprite_->pos_ += {1, 0, 0};

	sprite_->update(delta_time);

	sprite_->rot_ = tnl::Quaternion::LookAtAxisY(camera_->pos_, sprite_->pos_);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneResult());
	}
}

void ScenePlay::render()
{
	camera_->update();

	DrawGridGround(50, 20);

	sprite_->render(camera_);

	DrawStringEx(50, 50, -1, "scene play");
}
