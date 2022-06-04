#pragma once

#include "stdafx.h"
#include "../Entities/Headers/entity.h"
#include "../Manegers/Headers/drawble.h"
#include "../Manegers/Headers/caracteristics.h"
using namespace entities;
using namespace drawable;
using namespace caracteristics;

namespace obstacles
{
	class BaseObstacle : public BaseEntity, public SingleRectangleDrawable
	{
	public:
		BaseObstacle();
		BaseObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const bool FacesRight = true);
		BaseObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const bool FacesRight = true);
		BaseObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const VecAnimaValues& _animationMap, const bool FacesRight = true);
		BaseObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const VecAnimaValues& _animationMap, const bool FacesRight = true);
		BaseObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const std::vector<Animation>& _animationMap, const bool FacesRight = true);
		BaseObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const std::vector<Animation>& _animationMap, const bool FacesRight = true);
		~BaseObstacle();

		virtual void Initialize() = 0;
		virtual void Execute() = 0;
		virtual void SelfPrint(sf::RenderWindow& window) = 0;
	};

	class StaticObstacle : public BaseObstacle, public Slipery, public ForcesAtDirect
	{
	public:
		StaticObstacle(const float _surface_acceler = 0.0f, const bool dir_is_right = true, const float _coefficient = 1.0f);
		StaticObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const sf::IntRect& textureCut, const bool FacesRight = true, const float _surface_acceler = 0.0f, 
						const bool dir_is_right = true, const float _coefficient = 1.0f);
		StaticObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const sf::IntRect& textureCut, const bool FacesRight = true, const float _surface_acceler = 0.0f,
						const bool dir_is_right = true, const float _coefficient = 1.0f);
		StaticObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const VecAnimaValues& _animationMap, const sf::IntRect& textureCut, const bool FacesRight = true,
						const float _surface_acceler = 0.0f, const bool dir_is_right = true, const float _coefficient = 1.0f);
		StaticObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const VecAnimaValues& _animationMap, const sf::IntRect& textureCut, const bool FacesRight = true,
						const float _surface_acceler = 0.0f, const bool dir_is_right = true, const float _coefficient = 1.0f);
		StaticObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const std::vector<Animation>& _animationMap, const sf::IntRect& textureCut, const bool FacesRight = true,
						const float _surface_acceler = 0.0f, const bool dir_is_right = true, const float _coefficient = 1.0f);
		StaticObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const std::vector<Animation>& _animationMap, const sf::IntRect& textureCut, const bool FacesRight = true,
						const float _surface_acceler = 0.0f, const bool dir_is_right = true, const float _coefficient = 1.0f);
		~StaticObstacle();
		
		void Initialize();
		void Execute();
		void SelfPrint(sf::RenderWindow& window);
	};
}