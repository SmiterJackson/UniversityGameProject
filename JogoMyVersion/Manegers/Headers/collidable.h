#pragma once

#include "stdafx.h"

namespace traits
{
	class Collidable
	{
	public:
		Collidable(sf::RectangleShape& _body, const float _weight_ceffic = 0.0f);
		~Collidable();

		const float& GetWeightCoefficient() { return this->weight_coeffic; };
		void SetWeightCoefficient(const float _weight_coeffic) { this->weight_coeffic = _weight_coeffic; };

		//bool CheckCollision(BaseObstacle& item_2);

	protected:
		sf::RectangleShape& rect;
		float weight_coeffic;
	};
}