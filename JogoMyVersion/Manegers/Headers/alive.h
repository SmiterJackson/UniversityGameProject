#pragma once

#include "stdafx.h"

namespace traits
{
	class Alive
	{
	public:
		Alive(const unsigned int life_count = 0);
		~Alive();

		const unsigned int& GetLifeCount() { return this->life_count; };
		void SetLifeCount(const unsigned int& _life_count) { this->life_count = _life_count; };

		const bool IsClassAlive() { return this->alive; };
		void InvertLifeState();

		virtual void Died() = 0;

	protected:
		unsigned int life_count;
		bool alive;
	};
}