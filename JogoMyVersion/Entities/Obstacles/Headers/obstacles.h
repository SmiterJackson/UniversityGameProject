#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
#include "../Manegers/Headers/traits.h"
using namespace entities;
using namespace traits;

namespace obstacles
{
	class BaseObstacle : public CollidableEntity, public Printable
	{
	public:
		BaseObstacle();
		BaseObstacle(const sf::RectangleShape& _body, const sf::Texture& texture, const float _weight_ceffic = 1.0f, const bool FacesRight = true);
		BaseObstacle(const sf::RectangleShape& _body, const std::string fileName, const float _weight_ceffic = 1.0f, const bool FacesRight = true);
		~BaseObstacle();

		virtual void Execute() = 0;
		virtual void Initialize() = 0;
	};

	class StaticObstacle : public BaseObstacle
	{
	public:
		StaticObstacle();
		StaticObstacle(const sf::RectangleShape& _body, const sf::Texture& texture, const float _weight_ceffic = 1.0f, const bool FacesRight = true);
		StaticObstacle(const sf::RectangleShape& _body, const std::string fileName, const float _weight_ceffic = 1.0f, const bool FacesRight = true);
		~StaticObstacle();

		void Execute();
		void Initialize();
		void SelfPrint(sf::RenderWindow& window);

	protected:

	};
}

