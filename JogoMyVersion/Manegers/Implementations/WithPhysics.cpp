#pragma once

#include "../Headers/WithPhysics.h"
using namespace WithPhysics;

float Movable::global_gravity = 1.0f;

Movable::Movable(const float _horizontal_acc, const float _vertical_acc, const bool _have_ground) :
	horizontal_acc(_horizontal_acc), vertical_acc(_vertical_acc), have_ground(_have_ground)
{};
Movable::~Movable()
{};


float Slipery::global_friction = 1.0f;

Slipery::Slipery(const float _coefficient) :
	coefficient(_coefficient)
{};
Slipery::~Slipery()
{};