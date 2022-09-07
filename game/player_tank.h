#include "object.h"

class PlayerTank : public Object {
public:
	PlayerTank() {};

	int hp_ = 10;
	int speed_ = 3;

	void initialzie() override;
	void update(float delta_time) override;
};
