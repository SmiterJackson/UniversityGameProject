#pragma once

#include "stdafx.h"

class BackGround
{
public:
	BackGround();
	BackGround(const std::string& texture_fileName, sf::RenderWindow& window, const sf::Vector2f& views_size, float _proportion = 1.0f);
	BackGround(const sf::Texture& _texture, sf::RenderWindow& window, const sf::Vector2f& views_size, float _proportion = 1.0f);
	~BackGround();

	const std::vector<std::pair<sf::View, float>>& GetBackgroundsViews() { return this->backGroundViews; };
	void SetBackgroundsViews(const std::vector<std::pair<sf::View, float>>& _backGroundViews) { this->backGroundViews = _backGroundViews; };

	void SetWindowRef(sf::RenderWindow& _windowRef) { this->windowRef = &_windowRef; };

	void Initialize(const sf::Vector2f size);
	void UpdateBackGround(const sf::Vector2f& refDeltaPos);
	//void CheckViewsOutBounds();

protected:
	std::vector<std::pair<sf::View, float>> backGroundViews;
	sf::RenderWindow* windowRef;
	sf::Texture texture;
	float views_proportion;
};