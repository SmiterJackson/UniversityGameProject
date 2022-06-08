#pragma once

#include "../Headers/Hero.h"
using namespace sf;

#define MAX_HORIZONTAL_VELOCITY 16.0f
#define HORIZONTAL_ACCELERATION 6.0f

#define JUMP_ACCELERATION -8.0f // coeffficiente para o tamanho do pulo
#define MAX_FALL_VELOCITY -(JUMP_ACCELERATION / 2.0f)
#define VERTICAL_ACCELERATION -(JUMP_ACCELERATION / 16.0f) // proporção de tempo para desaceleração do pulo, o mais confortável que percebi foi 16

#define INVENCIBILITY_FRAMES_TIME 3.0f

unsigned int Hero::PlayersNums = 0;
Hero::Hero() :
	LivingEntity(), Animated(), invec_current_timer(0.0f), invenc_frames(false), crouching(false), playerId(PlayersNums++)
{
	Initialize();
};
Hero::Hero(const std::string fileName, const sf::RectangleShape& _body, const VecAnimaValues& _animationMap, const unsigned int _life_count, const bool _have_ground, const float _weight_ceffic) :
	LivingEntity(fileName, _body, _life_count, _have_ground, _weight_ceffic), Animated(_animationMap),invec_current_timer(0.0f), 
	invenc_frames(false), crouching(false), playerId(PlayersNums++)
{
	Initialize();
};
Hero::~Hero()
{
	--PlayersNums;
};

void Hero::Initialize()
{
	this->next_ani = Idle;

	this->body.setTexture(&this->texture);
	this->body.setOrigin((this->body.getSize() / 2.0f));

	this->invec_current_timer = 0.0f;

	this->walk_right = false;
	this->walk_left = false;
	this->crouching = false;
};
void Hero::Execute()
{	
	if (!this->alive)
	{
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

			this->horizontal_acc = 0.f;
	}

	if (!this->have_ground)
	{
		//this->next_ani = Fall;
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
void Hero::PlayerInputHandler(const sf::Event& event)
{
	// Ativa as ações baseado no id de cada player para relacionar os botões do teclado
	if(event.type == sf::Event::KeyPressed)
		switch (event.key.code)
		{
		case sf::Keyboard::A:
			if(this->playerId == 0)
				this->InvertWalkLeft();
			break;
		case sf::Keyboard::D:
			if (this->playerId == 0)
				this->InvertWalkRight();
			break;
		case sf::Keyboard::S:
			if (this->playerId == 0)
				this->InvertCrouching();
			break;
		case sf::Keyboard::W:
			if (this->playerId == 0)
				this->InvertJumping();
			break;
		case sf::Keyboard::Left:
			if (this->playerId == 1)
				this->InvertWalkLeft();
			break;
		case sf::Keyboard::Right:
			if (this->playerId == 1)
				this->InvertWalkRight();
			break;
		case sf::Keyboard::Up:
			if (this->playerId == 1)
				this->InvertCrouching();
			break;
		case sf::Keyboard::Down:
			if (this->playerId == 1)
				this->InvertJumping();
			break;
		default:
			break;
		}
	else
		switch (event.key.code)
		{
		case sf::Keyboard::A:
			if (this->playerId == 0)
				this->InvertWalkLeft();
			break;
		case sf::Keyboard::D:
			if (this->playerId == 0)
				this->InvertWalkRight();
			break;
		case sf::Keyboard::S:
			if (this->playerId == 0)
				this->InvertCrouching();
			break;
		case sf::Keyboard::W:
			if (this->playerId == 0)
				this->InvertJumping();
			break;
		case sf::Keyboard::Left:
			if (this->playerId == 1)
				this->InvertWalkLeft();
			break;
		case sf::Keyboard::Right:
			if (this->playerId == 1)
				this->InvertWalkRight();
			break;
		case sf::Keyboard::Up:
			if (this->playerId == 1)
				this->InvertCrouching();
			break;
		case sf::Keyboard::Down:
			if (this->playerId == 1)
				this->InvertJumping();
			break;
		default:
			break;
		}
};
void Hero::SelfPrint(sf::RenderWindow& window)
{
	if (this->lastUsedAni != this->next_ani)
		this->animationVec[this->lastUsedAni].ResetAnimation();

	this->lastUsedAni = this->next_ani;
	this->body.setTextureRect(this->animationVec[this->next_ani].update(this->elapsed_time, this->faceRight));
	window.draw(this->body);
};
