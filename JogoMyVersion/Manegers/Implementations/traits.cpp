#pragma once

#include "../Headers/traits.h"
using namespace traits;

//////////////////////////////////////////////////////////////////////////////////////
float Movable::global_gravity = 1.0f;

Movable::Movable(const bool _have_ground, const float _horizontal_acc, const float _vertical_acc) :
	horizontal_acc(_horizontal_acc), vertical_acc(_vertical_acc), have_ground(_have_ground), walk_right(false), walk_left(false), jumping(false)
{};
Movable::~Movable()
{};
//////////////////////////////////////////////////////////////////////////////////////
Slipery::Slipery(const float _coefficient) :
	friction_coefficient(_coefficient)
{};
Slipery::~Slipery()
{};
//////////////////////////////////////////////////////////////////////////////////////
ForcesAtDirect::ForcesAtDirect(const float _surface_acceler, const bool dir_is_right) :
	surface_acceler(_surface_acceler), dir_is_right(dir_is_right)
{};
ForcesAtDirect::~ForcesAtDirect()
{};

void ForcesAtDirect::InvertDirection()
{
	this->dir_is_right = !this->dir_is_right;
};
//////////////////////////////////////////////////////////////////////////////////////
Alive::Alive(const unsigned int _life_count) :
	life_count(_life_count), alive(true)
{};
Alive::~Alive()
{};

void Alive::InvertLifeState()
{
	this->alive = !this->alive;
};
//////////////////////////////////////////////////////////////////////////////////////
Printable::Printable() :
	texture(), faceRight(true)
{};
Printable::Printable(const sf::Texture& texture, const bool FacesRight) :
	texture(texture), faceRight(FacesRight)
{};
Printable::Printable(const std::string fileName, const bool FacesRight) :
	texture(), faceRight(FacesRight)
{
	this->texture.loadFromFile(fileName);
};
Printable::~Printable()
{};

void Printable::InvertTextureOrientation()
{
	this->faceRight = !this->faceRight;
};
//////////////////////////////////////////////////////////////////////////////////////
Collidable::Collidable(sf::RectangleShape& _body, const float _weight_ceffic) :
	rect(_body), weight_coeffic(std::min(std::max(_weight_ceffic, 0.0f), 1.0f))
{};
Collidable::~Collidable()
{};
//////////////////////////////////////////////////////////////////////////////////////
Animated::Animated() :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
Animated::Animated(const std::vector<Animation>& _animationVec) :
	animationVec(_animationVec), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
Animated::Animated(const VecAnimaValues& _animationVec) :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{
	size_t diff = this->animationVec.capacity() - this->animationVec.size();
	this->animationVec.reserve(diff + _animationVec.size());

	for (unsigned int i = 0; i < _animationVec.size(); ++i)
		this->animationVec.emplace_back(_animationVec[i]);
};
Animated::~Animated()
{};