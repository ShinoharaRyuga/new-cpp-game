#include "../game_manager.h"
#include "scene_title.h"
#include "scene_play.h"
#include "my_game_scene.h"


void SceneTitle::initialzie() {
}

void SceneTitle::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		//mgr->chengeScene( new ScenePlay() );
		mgr->chengeScene(new MyGameScene());
	}
}

void SceneTitle::render()
{
	DrawStringEx(50, 50, -1, "scene title");
}
