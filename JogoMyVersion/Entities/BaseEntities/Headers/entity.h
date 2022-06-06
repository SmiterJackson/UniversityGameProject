#pragma once

#include "instance.h"
#include "../Manegers/Headers/traits.h" 
using namespace traits;

namespace entities
{
	// Estrutura base para uma entidade, cuja tem as variáveis para se movimentar, é uma instancia no no jogo
	class BaseEntity : public Instance
	{
	public:
		BaseEntity();
		BaseEntity(const sf::RectangleShape& _body);
		~BaseEntity();

		sf::RectangleShape& GetBody() { return this->body; };
		const sf::RectangleShape& GetConstBody() { return this->body; };
		void SetBody(const sf::RectangleShape& _body) { this->body = _body; };

		// FUNCTIONS
		virtual void Execute() = 0;
		virtual void Initialize() = 0;

	protected:
		sf::RectangleShape body;
	};

	class CollidableEntity : public BaseEntity, public Collidable
	{
	public:
		CollidableEntity(const float _weight_ceffic = 1.0f);
		CollidableEntity(const sf::RectangleShape& _body, const float _weight_ceffic = 1.0f);
		~CollidableEntity();

		// FUNCTIONS
		virtual void Execute() = 0; // para cada  execute especializado defirnir ações de colisão
		virtual void Initialize() = 0;
	};

	class MovableEntity : public CollidableEntity, public Movable
	{
	public:
		MovableEntity(const float _weight_ceffic = 1.0f, const bool _have_ground = false);
		MovableEntity(const sf::RectangleShape& _body, const float _weight_ceffic = 1.0f, const bool _have_ground = false);
		~MovableEntity();

		// FUNCTIONS
		virtual void Execute() = 0; // para cada  execute especializado defirnir ações de colisão
		virtual void Initialize() = 0;
	};

	class LivingEntity : public MovableEntity, public Alive 
	{
	public:
		LivingEntity(const float _weight_ceffic = 1.0f, const unsigned int _life_count = 0, const bool _have_ground = false);
		LivingEntity(const sf::RectangleShape& _body, const float _weight_ceffic = 1.0f, const unsigned int _life_count = 0, const bool _have_ground = false);
		~LivingEntity();

		// FUNCTIONS
		virtual void Execute() = 0;
		virtual void Initialize() = 0;
	};
}