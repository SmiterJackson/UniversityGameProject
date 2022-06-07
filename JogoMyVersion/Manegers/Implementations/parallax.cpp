#pragma once

#include "../Headers/parallax.h"

#define VIEW_COEFFICIENT 0.2f

#define BACKGROUND_HEIGHT 324
#define BACKGROUND_WIDTH 576

BackGround::BackGround(const std::string& _texture, const float& _view_proportion, const float& _acceleration) :
	backGround(), texture(), body(), view_proportion(_view_proportion), acceleration(_acceleration)
{
	this->texture.loadFromFile(_texture);
	Initialize();
};
BackGround::BackGround(const sf::Texture& _texture, const float& _view_proportion, const float& _acceleration) :
	backGround(), texture(_texture), body(), view_proportion(_view_proportion), acceleration(_acceleration)
{
	Initialize();
};
BackGround::BackGround(const sf::View& _backGround, const std::string& _texture, const sf::RectangleShape& _sprite, const float& _view_proportion, const float& _acceleration) :
	backGround(_backGround), texture(), body(_sprite), view_proportion(_view_proportion), acceleration(_acceleration)
{
	this->texture.loadFromFile(_texture);
	Initialize();
};
BackGround::BackGround(const sf::View& _backGround, const sf::Texture& _texture, const sf::RectangleShape& _sprite, const float& _view_proportion, const float& _acceleration) :
	backGround(_backGround), texture(_texture), body(_sprite), view_proportion(_view_proportion), acceleration(_acceleration)
{
	Initialize();
};
BackGround::~BackGround()
{};

void BackGround::Initialize()
{
	this->body.setSize(sf::Vector2f(1728.0f, 972.0f));
	this->body.setOrigin(this->body.getSize() / 2.0f);
	this->body.setTexture(&this->texture);
	this->body.setPosition(sf::Vector2f(0.0f, 0.0f));
	this->backGround.setCenter(sf::Vector2f(0.0f, -(this->body.getSize().y / 4.0f) * 3));
	this->backGround.setSize(sf::Vector2f(BACKGROUND_WIDTH * this->view_proportion, BACKGROUND_HEIGHT * this->view_proportion));
};

void BackGround::UpdateBackGround(const sf::Vector2f& refDeltaPos)
{
	sf::Vector2f offset;

	offset.x -= refDeltaPos.x * this->acceleration;
	offset.y -= refDeltaPos.y * this->acceleration;

	this->backGround.move(offset);
}