#pragma once

#include "stdafx.h"

class BackGround
{
public:
	BackGround(const float _dist_coeffic = 1.0f);
	BackGround(const sf::Vector2f& _size = sf::Vector2f(1920.f, 1080.f), const sf::View& _view = sf::View(), 
			const sf::Texture& _texture = sf::Texture(), const sf::Sprite& _sprite = sf::Sprite(), const float _dist_coeffic = 1.0f);
	BackGround(const sf::Vector2f& _size = sf::Vector2f(1920.f, 1080.f), const sf::View& _view = sf::View(), 
			const std::string& _texture_fileName = std::string(), const sf::Sprite& _sprite = sf::Sprite(), const float _dist_coeffic = 1.0f);
	~BackGround();

	const sf::View& GetConstView() { return this->view; };
	void SetView(const sf::View& _view) { this->view = _view; };

	const sf::Texture& GetConstTexture() { return this->texture; };
	void SetTexture(const sf::Texture& _texture) { this->texture = _texture; };

	const sf::Sprite& GetConstSprite() { return this->sprite; };
	void SetSprite(const sf::Sprite& _sprite) { this->sprite = _sprite; };

	void Initialize(const sf::Vector2f& _size);
	void UpdateBackground(sf::RenderWindow& window, const sf::Vector2f& refDeltaPos, float elapsed_time);

protected:
	sf::View view;
	sf::Texture texture;
	sf::Sprite sprite;
	const float dist_coeffic;
};

class Parallax
{
public:
	Parallax();
	~Parallax();

	const std::vector<BackGround>& GetBackgrounds() { return this->backgrounds; };

	void Initialize();
	void DrawBackground(sf::RenderWindow& window, const sf::Vector2f& refDeltaPos, float elapsed_time);

protected:
	std::vector<BackGround> backgrounds;
};