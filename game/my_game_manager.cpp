#include "my_game_manager.h"

void MyGameManagaer::render() {
	for (Enemy* enemy : enemies_) {
		enemy->render();
	}
}