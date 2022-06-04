#pragma once

#include "stdafx.h"
#include "../Headers/entity.h"
using namespace entities;

BaseEntity::BaseEntity(bool* _haveGround = nullptr, sf::RectangleShape* _body = nullptr) :
	Instance(), Collidable(_body, _haveGround)
{};
BaseEntity::~BaseEntity()
{};


MovableEntity::MovableEntity(const bool _have_ground, sf::RectangleShape* _body = nullptr) :
	Movable(_have_ground), BaseEntity(&have_ground, _body)
{};
MovableEntity::~MovableEntity()
{};


LivingEntity::LivingEntity(const unsigned int _life_count, const bool _have_ground, sf::RectangleShape* _body = nullptr) :
	MovableEntity(_have_ground, _body), IsAlive(_life_count)
{};
LivingEntity::~LivingEntity()
{};