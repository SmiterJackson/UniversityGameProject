#pragma once

#include "../Headers/Hero.h"
using namespace sf;

#define MAX_HORIZONTAL_VELOCITY 75.0f
#define HORIZONTAL_ACCELERATION 25.0f

#define JUMP_ACCELERATION -24.0f // coeffficiente para o tamanho do pulo
#define MAX_FALL_VELOCITY -(JUMP_ACCELERATION / 2.0f)
#define VERTICAL_ACCELERATION -(JUMP_ACCELERATION / 16.0f) // proporção de tempo desaceleração do pulo, o mais confortável que percebi foi 16

#define INVENCIBILITY_FRAMES_TIME 3.0f

Hero::Hero() :
	LivingEntity(), Printable(), Animated(), Slipery()
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const unsigned int _life_count, const float _weight_ceffic, const bool _have_ground) :
	LivingEntity(_body, _weight_ceffic, _life_count, _have_ground), Printable(texture), Animated(), Slipery()
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const VecAnimaValues& _animations, const unsigned int _life_count, const float _weight_ceffic, const bool _have_ground) :
	LivingEntity(_body, _weight_ceffic, _life_count, _have_ground), Printable(texture), Animated(_animations), Slipery()
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const std::vector<Animation>& _animations, const unsigned int _life_count, const float _weight_ceffic, const bool _have_ground) :
	LivingEntity(_body, _weight_ceffic, _life_count, _have_ground), Printable(texture), Animated(_animations), Slipery()
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const std::string fileName, const unsigned int _life_count, const float _weight_ceffic, const bool _have_ground) :
	LivingEntity(_body, _weight_ceffic, _life_count, _have_ground), Printable(fileName), Animated(), Slipery()
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const std::string fileName, const VecAnimaValues& _animations, const unsigned int _life_count, const float _weight_ceffic, const bool _have_ground) :
	LivingEntity(_body, _weight_ceffic, _life_count, _have_ground), Printable(fileName), Animated(_animations), Slipery()
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const std::string fileName, const std::vector<Animation>& _animations, const unsigned int _life_count, const float _weight_ceffic, const bool _have_ground) :
	LivingEntity(_body, _weight_ceffic, _life_count, _have_ground), Printable(fileName), Animated(_animations), Slipery()
{
	Initialize();
};
Hero::~Hero()
{};

void Hero::Initialize()
{
	this->next_ani = Idle;
	this->body.setTexture(&this->texture);
	this->body.setOrigin((this->body.getSize() / 2.0f));
	this->friction_coefficient = 0.95f;
	this->invec_current_timer = 0.0f;
	this->walk_right = false;
	this->walk_left = false;
	this->crouching = false;
};
void Hero::Execute()
{	
	if (!this->alive) {
		Died();
		return;
	}

	if ((!this->walk_left && this->walk_right) || (this->walk_left && !this->walk_right) && !this->crouching)
	{
		if (this->have_ground)
			this->next_ani = Run;
		if (this->walk_left && this->horizontal_acc > -MAX_HORIZONTAL_VELOCITY)
		{
			this->faceRight = false;
			this->horizontal_acc -= HORIZONTAL_ACCELERATION * elapsed_time;
		}
		if (this->walk_right && this->horizontal_acc < MAX_HORIZONTAL_VELOCITY)
		{
			this->faceRight = true;
			this->horizontal_acc += HORIZONTAL_ACCELERATION * elapsed_time;
		}
	}
	else
	{
		if (this->horizontal_acc >= -0.1f || this->horizontal_acc <= 0.1f)
		{
			this->horizontal_acc = 0.0f;

			if (this->have_ground)
				this->next_ani = Idle;
		}

		if (this->horizontal_acc > 0.0f)
			this->horizontal_acc -= HORIZONTAL_ACCELERATION * elapsed_time;

		if (this->horizontal_acc < 0.0f)
			this->horizontal_acc += HORIZONTAL_ACCELERATION * elapsed_time;
	}

	if (this->have_ground && this->crouching)
	{
		this->next_ani = Crouch;

		if (this->walk_left)
			this->faceRight = false;
		else
			this->faceRight = true;

		if (this->horizontal_acc >= -0.1f || this->horizontal_acc <= 0.1f)
			this->horizontal_acc = 0.0f;

		if (this->horizontal_acc > 0.0f)
			this->horizontal_acc -= HORIZONTAL_ACCELERATION * elapsed_time * 2;

		if (this->horizontal_acc < 0.0f)
			this->horizontal_acc += HORIZONTAL_ACCELERATION * elapsed_time * 2;
	}

	if (!this->have_ground)
	{
		if (this->vertical_acc < MAX_FALL_VELOCITY)
			this->vertical_acc += VERTICAL_ACCELERATION;
	}
	else
		this->vertical_acc = 0.0f;

	if (this->have_ground && this->jumping) // Caso esteja no chão e pule, acelera para cima
	{
		this->have_ground = false;
		this->next_ani = Jump;
		this->vertical_acc = JUMP_ACCELERATION;
	}

	if (this->invec_current_timer > 0.0f)
		this->invec_current_timer -= this->elapsed_time;
	else {
		this->invec_current_timer = 0.0f;
		this->invenc_frames = false;
	}

	this->horizontal_acc *= this->friction_coefficient;
	this->body.move(sf::Vector2f(this->horizontal_acc, this->vertical_acc));
};
void Hero::Damaged()
{
	if (!invenc_frames)
	{
		--(this->life_count);
		this->invenc_frames = true;
		this->invec_current_timer = INVENCIBILITY_FRAMES_TIME;
	}
	
	if (this->invec_current_timer > 0.0f)
		this->invec_current_timer -= this->elapsed_time;
	else {
		this->invec_current_timer = 0.0f;
		this->invenc_frames = false;
	}
};
void Hero::Died()
{
	this->alive = false;

	if (this->horizontal_acc < 0.1f && this->horizontal_acc > -0.1f)
	{
		this->horizontal_acc = 0.0f;
	}
	else if (this->horizontal_acc < MAX_HORIZONTAL_VELOCITY)
	{
		this->horizontal_acc -= HORIZONTAL_ACCELERATION * this->elapsed_time;
	}
	else
	{
		this->horizontal_acc += HORIZONTAL_ACCELERATION * this->elapsed_time;
	}

	if (this->have_ground && this->jumping)
	{
		this->next_ani = Jump;
		this->vertical_acc += JUMP_ACCELERATION * this->elapsed_time;
	}
	else if (!this->have_ground && this->vertical_acc > MAX_FALL_VELOCITY)
	{
		this->next_ani = Jump;
		this->vertical_acc += MAX_FALL_VELOCITY * this->elapsed_time;
	}
	else
	{
		this->next_ani = Jump;
		this->vertical_acc = 0;
	}

	this->next_ani = Death;
	this->body.move(sf::Vector2f(this->horizontal_acc, this->vertical_acc));
};
void Hero::SelfPrint(sf::RenderWindow& window)
{
	if (this->lastUsedAni != this->next_ani)
		this->animationVec[this->lastUsedAni].ResetAnimation();

	this->lastUsedAni = this->next_ani;
	this->body.setTextureRect(this->animationVec[this->next_ani].update(this->elapsed_time, this->faceRight));
	window.draw(this->body);
};

/*

*/

/*if (Keyboard::isKeyPressed(Keyboard::A))
		this->walk_left = true;
	else
		this->walk_left = false;
	if (Keyboard::isKeyPressed(Keyboard::D))
		this->walk_right = true;
	else
		this->walk_right = false;
	if (Keyboard::isKeyPressed(Keyboard::S))
		this->crouching = true;
	else
		this->crouching = false;
	if (Keyboard::isKeyPressed(Keyboard::W) && this->have_ground)
		this->jumping = true;
	else
		this->jumping = false;

	if(((this->walk_right && !this->walk_left) || (!this->walk_right && this->walk_left)) && !this->crouching)
	{
		if(this->have_ground)
			this->next_ani = Run;

		if(this->walk_right && this->horizontal_acc < MAX_HORIZONTAL_VELOCITY)
			this->horizontal_acc += HORIZONTAL_ACCELERATION * this->elapsed_time;
		else if(this->horizontal_acc > -MAX_HORIZONTAL_VELOCITY)
			this->horizontal_acc -= HORIZONTAL_ACCELERATION * this->elapsed_time;
	}
	else
	{
		if (this->have_ground)
			this->next_ani = Run;

		if(this->horizontal_acc < 0.1f && this->horizontal_acc > -0.1f)
			this->horizontal_acc = 0.0f;
		else if(this->horizontal_acc < MAX_HORIZONTAL_VELOCITY)
			this->horizontal_acc -= HORIZONTAL_ACCELERATION * this->elapsed_time;
		else
			this->horizontal_acc += HORIZONTAL_ACCELERATION * this->elapsed_time;
	}

	if (this->have_ground && this->jumping)
	{
		this->next_ani = Jump;
		this->vertical_acc += JUMP_ACCELERATION * this->elapsed_time;
	}
	else if (!this->have_ground && this->vertical_acc > MAX_FALL_VELOCITY)
	{
		this->next_ani = Jump;
		this->vertical_acc += MAX_FALL_VELOCITY * this->elapsed_time;
	}
	else
	{
		this->next_ani = Jump;
		this->vertical_acc = 0;
	}

	if (this->crouching && this->have_ground)
	{
		this->next_ani = Crouch;
		this->horizontal_acc = 0.0f;
	}*/