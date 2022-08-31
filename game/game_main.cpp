#include <time.h>
#include "game_main.h"
#include "game_manager.h"

void gameMain(float delta_time) {
	GameManager* mgr = GameManager::GetInstance();
	mgr->update(delta_time);
	//dxe::Texture* t = dxe::Texture::CreateFromFile( "graphics/c1_anim_down.png", 128, 48, 4, 1);
	//int a = 0;
	//a++;
}

void gameEnd() {
}
