#pragma once

#include "../Headers/entity.h"
using namespace entities;

BaseEntity::BaseEntity() :
	Instance(), body()
{
#ifdef _DEBUG
	debugExecute();
#endif
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
BaseEntity::BaseEntity(const sf::RectangleShape& _body) :
	Instance(), body(_body)
{
#ifdef _DEBUG
	debugExecute();
#endif 
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
BaseEntity::~BaseEntity()
{};

#ifdef _DEBUG
void BaseEntity::debugExecute()
{
	this->font.loadFromFile("JogoMyVersion\\Resources\\fonts\\hf-free-complete\\equipment-pro-v1.1\\EquipmentPro.ttf");
	this->info_pos.setCharacterSize(10);
	this->info_pos.setFont(this->font);
	stringInfoUptade();
};
void BaseEntity::stringInfoUptade()
{
	this->info_pos.setFont(this->font);
	this->info_pos.setPosition(body.getPosition().x + body.getSize().x / 2.0f - body.getSize().x / 4.0f, body.getPosition().y - body.getSize().y / 2.0f + body.getSize().y / 4.0f);
	sf::Vector2f data = body.getPosition();

	this->value_as_string = '(';
	this->value_as_string += std::to_string(lround(data.x));
	this->value_as_string += ',';
	this->value_as_string += std::to_string(lround(data.y));
	this->value_as_string += ')';
	this->info_pos.setString(value_as_string.c_str());
};
void BaseEntity::PrintInfo(sf::RenderWindow& window)
{
	window.draw(this->info_pos);
};
#endif


CollidableEntity::CollidableEntity(const float _weight_ceffic) :
	BaseEntity(), Collidable(this->body, _weight_ceffic)
{};
CollidableEntity::CollidableEntity(const sf::RectangleShape& _body, const float _weight_ceffic) :
	BaseEntity(_body), Collidable(this->body, _weight_ceffic)
{};
CollidableEntity::~CollidableEntity()
{};


MovableEntity::MovableEntity(const float _weight_ceffic, const bool _have_ground) :
	CollidableEntity(_weight_ceffic), Movable(_have_ground)
{};
MovableEntity::MovableEntity(const sf::RectangleShape& _body, const float _weight_ceffic, const bool _have_ground) :
	CollidableEntity(_body, _weight_ceffic), Movable(_have_ground)
{};
MovableEntity::~MovableEntity()
{};


LivingEntity::LivingEntity(const float _weight_ceffic, const unsigned int _life_count, const bool _have_ground) :
	MovableEntity(_weight_ceffic, _have_ground), Alive(_life_count)
{};
LivingEntity::LivingEntity(const sf::RectangleShape& _body, const float _weight_ceffic, const unsigned int _life_count, const bool _have_ground) :
	MovableEntity(_body, _weight_ceffic, _have_ground), Alive(_life_count)
{};
LivingEntity::~LivingEntity()
{};