#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
#include "../Entities/Obstacles/Headers/obstacles.h"
#include "traits.h"
using namespace obstacles;
using namespace entities;
using namespace traits;

class Collider
{
public:
	Collider();
	Collider(const std::vector<LivingEntity*>& _livingEntities, std::vector<BaseObstacle*> _obstacles);
	~Collider();

	void UpdateCollisions();
	bool CheckCollision(LivingEntity& item_1, BaseObstacle& item_2);
	bool CheckNext(LivingEntity& entity, BaseObstacle& obst);

	void operator+= (LivingEntity* item)
	{
		livingEntities.push_back(item);
	}
	void operator+= (BaseObstacle* item)
	{
		obstacles.push_back(item);
	}

protected:
	std::vector<LivingEntity*> livingEntities;
	std::vector<BaseObstacle*> obstacles;
};