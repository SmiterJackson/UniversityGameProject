#pragma once

#include "stdafx.h"
#include "instance.h"
#include "../Manegers/Headers/caracteristics.h"
using namespace caracteristics;

namespace entities
{
	// Estrutura base para uma entidade, cuja tem as variáveis para se movimentar, é uma instancia no no jogo
	class BaseEntity : public Instance 
	{
	public:
		BaseEntity();
		~BaseEntity();

		// FUNCTIONS
		virtual void Execute() = 0;
		virtual void Initialize() = 0;
	};

	class MovableEntity : public BaseEntity, public Movable
	{
	public:
		MovableEntity(const bool _have_ground = false);
		~MovableEntity();

		// FUNCTIONS
		virtual void Execute() = 0;
		virtual void Initialize() = 0;
	};

	class LivingEntity : public MovableEntity, public IsAlive 
	{
	public:
		LivingEntity(const unsigned int _life_count = 0, const bool _have_ground = false);
		~LivingEntity();

		// FUNCTIONS
		virtual void Execute() = 0;
		virtual void Initialize() = 0;
	};
}
