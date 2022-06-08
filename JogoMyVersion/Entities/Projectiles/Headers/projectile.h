#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
using namespace entities;

namespace projectiles 
{
	class BaseProjectile : public Entity, public Movable
	{
	public:
		BaseProjectile();
		~BaseProjectile();

		virtual void Initialize() = 0;
		virtual void Execute() = 0;
		virtual void SelfPrint(sf::RenderWindow& window) = 0;
	};
}
