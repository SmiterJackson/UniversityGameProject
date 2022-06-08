#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
using namespace entities;

namespace obstacles
{
	class BaseObstacle : public Entity
	{
	public:
		BaseObstacle();
		BaseObstacle(const std::string _fileName, const sf::RectangleShape& _body, const sf::IntRect& _textureCut = sf::IntRect(0,0,0,0), const float _weight_ceffic = 1.0f);
		~BaseObstacle();

		void Initialize();
		void Execute();
		void SelfPrint(sf::RenderWindow& window);

	protected:
		sf::IntRect textureCut;
	};
}

