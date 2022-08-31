#include "../game_manager.h"
#include "scene_result.h"
#include "scene_title.h"

void SceneResult::initialzie() {
}

void SceneResult::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();


	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneTitle());
	}
}

void SceneResult::render()
{
	DrawStringEx(50, 50, -1, "scene result");
}
