#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
#include "../Manegers/Headers/traits.h"
using namespace entities;
using namespace traits;

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
