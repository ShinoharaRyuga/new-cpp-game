#include "object.h"

Object::Object(dxe::Camera* camera) {
	camera_ = camera;
}


void Object::render() {
	object_->render(camera_);
}