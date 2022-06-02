#pragma once

#include "../Headers/WithPhysics.h"
using namespace WithPhysics;

float Movable::global_gravity = 1.0f;

Movable::Movable(const bool _have_ground, const float _horizontal_acc, const float _vertical_acc) :
	horizontal_acc(_horizontal_acc), vertical_acc(_vertical_acc), have_ground(_have_ground)
{};
Movable::~Movable()
{};


float Slipery::global_friction = 1.0f;

Slipery::Slipery(const float _coefficient) :
	friction_coefficient(_coefficient)
{};
Slipery::~Slipery()
{};