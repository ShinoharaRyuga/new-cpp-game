#include "./model/anim_sprite3d.h"
#include "./scene/my_game_scene.h"
#include "object.h"

class Bullet {
public:
	Bullet() {}

	float speed_ = 1;

	void initialzie() ;
	void update(float delta_time) ;
};
