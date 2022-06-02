#pragma once

#include "../Headers/WithPhysics.h"
using namespace WithPhysics;

float WithPhysics::Movable::global_gravity = 1.0f;

Movable::Movable(const float _horizontal_acc, const float _vertical_acc) :
	horizontal_acc(_horizontal_acc), vertical_acc(_vertical_acc)
{};
Movable::~Movable()
{};