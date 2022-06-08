#pragma once

#include "../Headers/entity.h"
using namespace entities;

Entity::Entity() :
	Ente(), Collidable(this->body), body()
{
	this->body.setOrigin(this->body.getSize() / 2.0f);
	this->body.setTexture(&this->texture);
#ifdef _DEBUG
	debugExecute();
#endif
};
Entity::Entity(const sf::Texture& _texture, const sf::RectangleShape& _body, const float _weight_ceffic) :
	Ente(), Collidable(this->body, _weight_ceffic), Printable(_texture), body(_body)
{
	this->body.setOrigin(this->body.getSize() / 2.0f);
	this->body.setTexture(&this->texture);
#ifdef _DEBUG
	debugExecute();
#endif 
};
Entity::Entity(const std::string _fileName, const sf::RectangleShape& _body, const float _weight_ceffic) :
	Ente(), Collidable(this->body, _weight_ceffic), Printable(_fileName), body(_body)
{
	this->body.setOrigin(this->body.getSize() / 2.0f);
	this->body.setTexture(&this->texture);
#ifdef _DEBUG
	debugExecute();
#endif
};
Entity::~Entity()
{};

#ifdef _DEBUG
void Entity::debugExecute()
{
	this->font.loadFromFile("JogoMyVersion\\Resources\\fonts\\hf-free-complete\\equipment-pro-v1.1\\EquipmentPro.ttf");
	this->info_pos.setCharacterSize(8);
	this->info_pos.setFont(this->font);
	info_pos.setFillColor(sf::Color(0,255,255));
	info_pos.setOutlineThickness(0.75f);
	info_pos.setOutlineColor(sf::Color(0, 0, 255));
	stringInfoUptade();
};
void Entity::stringInfoUptade()
{
	this->info_pos.setFont(this->font);
	this->info_pos.setPosition(body.getPosition().x + body.getSize().x / 2.0f - body.getSize().x / 4.0f, body.getPosition().y - body.getSize().y / 2.0f + body.getSize().y / 4.0f);
	sf::Vector2f data = body.getPosition();

	this->value_as_string = '(';
	this->value_as_string += std::to_string(lround(data.x));
	this->value_as_string += ',';
	this->value_as_string += std::to_string(lround(data.y));
	this->value_as_string += ')';
	this->info_pos.setString(value_as_string);
};
void Entity::PrintInfo(sf::RenderWindow& window)
{
	window.draw(this->info_pos);
};
#endif