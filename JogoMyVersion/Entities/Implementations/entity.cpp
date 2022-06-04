#pragma once

#include "stdafx.h"
#include "../Headers/entity.h"
using namespace entities;

BaseEntity::BaseEntity() :
	Instance()
{};
BaseEntity::~BaseEntity()
{};


MovableEntity::MovableEntity(const bool _have_ground) :
	BaseEntity(), Movable(_have_ground)
{};
MovableEntity::~MovableEntity()
{};


LivingEntity::LivingEntity(const unsigned int _life_count, const bool _have_ground) :
	MovableEntity(_have_ground), IsAlive(_life_count)
{};
LivingEntity::~LivingEntity()
{};