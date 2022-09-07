#include "object.h"

void Object::render() {
	object_->render(camera_);
}