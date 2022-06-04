#pragma once

#include "stdafx.h"
#include "../Entities/Headers/entity.h"
#include "../Manegers/Headers/drawble.h"

namespace collision 
{
	class Collidable
	{
	public:
		Collidable(sf::RectangleShape* _body = nullptr, bool* _haveGround = nullptr);
		~Collidable();

		void SetBodyRef(sf::RectangleShape* _body) { this->rect = _body; };

	protected:
		sf::RectangleShape* rect;
		bool* _haveGround;
	};

	class CollisionManager
	{
	public:
		CollisionManager();
		CollisionManager(const std::vector<drawable::SingleRectangleDrawable*>& _singleBody_entities, const std::vector<drawable::MultipleRectangleDrawable*>& _multipleBodies_entities);
		~CollisionManager();

		void VerifyCollisions();

	private:
		std::vector<Collidable> singleBody_entities;
	};
}

