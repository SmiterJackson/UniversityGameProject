#pragma once

#include "../Entities/Projectiles/Headers/enemyProjectile.h"
#include "../Entities/Projectiles/Headers/heroProjectile.h"
#include "../Entities/BaseEntities/Headers/livingEntity.h"
#include "../Entities/Obstacles/Headers/obstacles.h"
using namespace projectiles;
using namespace obstacles;
using namespace entities;

class Collider
{
public:
	class MapBounds
	{
	public:
		MapBounds();
		MapBounds(float _leftBound, float _topBound, float _rightBound, float _bottomBound);
		~MapBounds();

	public:
		float leftBound, topBound, rightBound, bottomBound;
	};

	Collider();
	Collider(const MapBounds& _mapLimits);
	Collider(const MapBounds& _mapLimits, const std::vector<LivingEntity*>& _livingEntities, std::vector<BaseObstacle*> _obstacles);
	~Collider();

	void UpdateCollisions(float _elapsed_time);

	// Função Adaptada da original, pelo canal Hilze Vonck
	bool CheckCollisionObstacles(LivingEntity& entity, BaseObstacle& obst);

	void operator+= (LivingEntity* item)
	{
		livingEntities.push_back(item);
	}
	void operator+= (BaseObstacle* item)
	{
		obstacles.push_back(item);
	}

protected:
	const MapBounds mapLimits;
	std::vector<LivingEntity*> livingEntities;
	std::vector<BaseObstacle*> obstacles;
	std::vector<HeroProjectile*> heroProjectiles;
	float timer;
};