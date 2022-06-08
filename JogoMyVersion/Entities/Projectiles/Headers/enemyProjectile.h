#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
using namespace entities;

namespace projectiles
{
	class EnemyProjectile : public Entity, public Movable
	{
	public:
		EnemyProjectile();
		~EnemyProjectile();

		void Initialize();
		void Execute();
		void SelfPrint(sf::RenderWindow& window);
	};
}