#pragma once

#include "../Entities/BaseEntities/Headers/livingEntity.h"
#include "../Entities/Obstacles/Headers/obstacles.h"
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

	const float GetElapsedTime() const { return elapsed_time; };
	void SetElapsedTime(const float _elapsed_time) { this->elapsed_time = _elapsed_time; };

	void UpdateCollisions();

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
	float elapsed_time, timer;
};