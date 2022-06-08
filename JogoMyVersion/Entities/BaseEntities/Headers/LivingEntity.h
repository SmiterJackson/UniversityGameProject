#pragma once

#include "entity.h"

namespace entities 
{
	// Especificação da estrutura de entidade cuja se diferencia por ser uma classe que pode se mover e tem 'vida'
	// PS: Necessária para diferenciar tipos de entidade no colisor
	class LivingEntity : public Entity, public Movable, public Alive
	{
	public:
		LivingEntity();
		LivingEntity(const sf::Texture& texture, const sf::RectangleShape& _body, const unsigned int _life_count = 0, const bool _have_ground = false, const float _weight_ceffic = 1.0f);
		LivingEntity(const std::string fileName, const sf::RectangleShape& _body, const unsigned int _life_count = 0, const bool _have_ground = false, const float _weight_ceffic = 1.0f);
		~LivingEntity();

		// FUNCTIONS
		virtual void Initialize() = 0;
		virtual void Execute() = 0;
		virtual void Died() = 0;
		virtual void SelfPrint(sf::RenderWindow& window) = 0;
	};
}