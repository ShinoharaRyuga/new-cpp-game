#include "scene_base.h"
#include "../model/anim_sprite3d.h"

class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay(){
		delete camera_;
		delete sprite_;
	}

	dxe::Camera* camera_ = nullptr;
	AnimSprite3D* sprite_ = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;

};

