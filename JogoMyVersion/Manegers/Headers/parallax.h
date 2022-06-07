#pragma once

#include "stdafx.h"

class BackGround
{
public:
	BackGround(const std::string& _texture = std::string(), const float& _view_proportion = 1.0f, const float& _acceleration = 1.0f);
	BackGround(const sf::Texture& _texture = sf::Texture(), const float& _view_proportion = 1.0f, const float& _acceleration = 1.0f);
	BackGround(const sf::View& _backGround, const std::string& _texture, const sf::RectangleShape& _sprite, const float& _view_proportion = 1.0f, const float& _acceleration = 1.0f);
	BackGround(const sf::View& _backGround, const sf::Texture& _texture, const sf::RectangleShape& _sprite, const float& _view_proportion = 1.0f, const float& _acceleration = 1.0f);
	~BackGround();

	void Initialize();
	void UpdateBackGround(const sf::Vector2f& refDeltaPos);

protected:
	sf::View backGround;
	sf::Texture texture;
	sf::RectangleShape body;
	float view_proportion, acceleration;
};