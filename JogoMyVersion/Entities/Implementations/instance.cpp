#pragma once

#include "../Headers/instance.h"

// STATIC INITIALIZATION
unsigned int Instance::id = 0;

// CONSTRUCTORS
Instance::Instance() :
	own_id(++id)
{};
Instance::~Instance()
{};