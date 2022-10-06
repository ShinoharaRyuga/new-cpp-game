#include "enemy.h";

Enemy::Enemy(dxe::Camera* camera) : Object::Object(camera) {
	camera_ = camera;
}

void Enemy::initialzie() {
	object_ = dxe::Mesh::CreateBoxMV(20);
	object_->setTexture(dxe::Texture::CreateFromFile("graphics/red1.bmp"));
	object_->flg_dbg_line_ = dxe::Mesh::fDebugLine::FLG_AXIS;
}

void Enemy::update(float delta_time) {

}

void Enemy::getDamege(int damege) {
	hp_ -= damege;

	if (hp_ <= 0) {
		clsDx();
		printfDx("Ž€–S");
	}
}

void Enemy::setFirstPos(tnl::Vector3 firstPos) {
	object_->pos_ = firstPos;
}