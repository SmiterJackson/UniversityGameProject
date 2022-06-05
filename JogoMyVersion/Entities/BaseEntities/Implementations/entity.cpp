#pragma once

#include "stdafx.h"
#include "../Headers/entity.h"
using namespace entities;

BaseEntity::BaseEntity() :
	Instance(), body()
{
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
BaseEntity::BaseEntity(const sf::RectangleShape& _body) :
	Instance(), body(_body)
{
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
BaseEntity::~BaseEntity()
{};


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