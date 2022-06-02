#pragma once

#include "stdafx.h"
#include "../Headers/entity.h"

Entity::Entity() :
	Instance(), body()
{};
Entity::Entity(sf::Texture& texture, bool facingRight) :
	Instance(), body()
{
	this->body.setTexture(texture);
};
Entity::Entity(sf::Texture& texture, sf::RectangleShape& Body, bool facingRight) :
	Instance(), body()
{
	this->body.setTexture(texture);
};
Entity::~Entity()
{};
