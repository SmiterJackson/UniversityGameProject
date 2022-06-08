#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
using namespace entities;

namespace projectiles 
{
	class HeroProjectile : public Entity, public Movable
	{
	public:
		HeroProjectile(sf::Vector2f position = sf::Vector2f(0.f, 0.f), bool _dirrection = true);
		~HeroProjectile();

		void Initialize();
		void Execute();
		void SelfPrint(sf::RenderWindow& window);

	private:
		sf::Vector2f origin;
	};
}
