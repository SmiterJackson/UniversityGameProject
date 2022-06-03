#include "../Entities/Characters/Headers/Hero.h"
using namespace sf;

#define HERO_HORIZONTAL_ACCELERETION 1.0f
#define HERO_MAX_HORIZONTAL_DESACCELERETION HERO_HORIZONTAL_ACCELERETION
#define HERO_MAX_HORIZONTAL_ACCELERETION 10.0f
#define HERO_VERTICAL_ACCELERETION 36.0f
#define HERO_VERTICAL_DESACCELERETION (HERO_VERTICAL_ACCELERETION/18)
#define HERO_MAX_FALL_VELOCITY (HERO_VERTICAL_ACCELERETION/2)
#define HERO_INVENCIBILITY_FRAMES_TIME 3.0f

Hero::Hero() :
	LivingEntity(), Slipery(), invec_time(HERO_INVENCIBILITY_FRAMES_TIME), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, texture, _life_count, FacesRight, _have_ground), Slipery(), invec_time(HERO_INVENCIBILITY_FRAMES_TIME), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& Body, const std::string& fileName, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, fileName, _life_count, FacesRight, _have_ground), Slipery(), invec_time(HERO_INVENCIBILITY_FRAMES_TIME), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap, const std::vector<std::pair<unsigned int, AnimaData>>& animationMap,
	const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, texture, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), invec_time(HERO_INVENCIBILITY_FRAMES_TIME), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& Body, const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap, const std::vector<std::pair<unsigned int, AnimaData>>& animationMap,
	const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, fileName, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), invec_time(HERO_INVENCIBILITY_FRAMES_TIME), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
	const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, texture, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), invec_time(HERO_INVENCIBILITY_FRAMES_TIME), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& Body, const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
	const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, fileName, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), invec_time(HERO_INVENCIBILITY_FRAMES_TIME), invenc_frames(false)
{
	Initialize();
};
Hero::~Hero()
{};

void Hero::Initialize()
{
	this->next_animation = Idle;
	this->body.setTexture(&this->texture);
	this->body.setOrigin((this->body.getSize() / 2.0f));
	this->friction_coefficient = 0.75f;
	this->invec_current_timer = 0.0f;
};
void Hero::Execute()
{	
	if (!this->alive) {
		Died();
		return;
	}

	bool isA_pressed = Keyboard::isKeyPressed(Keyboard::A), isD_pressed = Keyboard::isKeyPressed(Keyboard::D);

	if((!isA_pressed && isD_pressed) || (isA_pressed && !isD_pressed))
	{
		if (isA_pressed && this->horizontal_acc > -HERO_MAX_HORIZONTAL_ACCELERETION)
		{
			this->faceRight = false;
			if(this->have_ground)
				this->next_animation = Run;
			this->horizontal_acc -= HERO_HORIZONTAL_ACCELERETION;
		}
		if (isD_pressed && this->horizontal_acc < HERO_MAX_HORIZONTAL_ACCELERETION)
		{
			this->faceRight = true;
			if (this->have_ground)
				this->next_animation = Run;
			this->horizontal_acc += HERO_HORIZONTAL_ACCELERETION;
		}
	}
	else {
		if (this->horizontal_acc >= -0.1f || this->horizontal_acc <= 0.1f)
		{
			//this->horizontal_acc = 0.0f;

			if (this->have_ground)
				this->next_animation = Idle;
		}

		if (this->horizontal_acc > 0.0f)
			this->horizontal_acc -= HERO_MAX_HORIZONTAL_DESACCELERETION;

		if (this->horizontal_acc < 0.0f)
			this->horizontal_acc += HERO_MAX_HORIZONTAL_DESACCELERETION;
	}

	if(this->have_ground && Keyboard::isKeyPressed(Keyboard::S))
	{
		this->next_animation = Crouch;
	}

	if (this->have_ground && Keyboard::isKeyPressed(Keyboard::W)) // Caso esteja no chão e pule, acelera para cima
	{
		this->have_ground = false;
		this->next_animation = Jump;
		this->vertical_acc = -HERO_VERTICAL_ACCELERETION;
	}

	if (!this->have_ground)
		if(this->vertical_acc < HERO_MAX_FALL_VELOCITY)
			this->vertical_acc += HERO_VERTICAL_DESACCELERETION;
	else
		this->vertical_acc = 0.0f;

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
		this->invec_current_timer = this->invec_time;
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

	if (this->horizontal_acc >= -0.1f || this->horizontal_acc <= 0.1f)
		this->horizontal_acc = 0.0f;

	if (this->horizontal_acc > 0.0f)
		this->horizontal_acc -= HERO_MAX_HORIZONTAL_DESACCELERETION;

	if (this->horizontal_acc < 0.0f)
		this->horizontal_acc += HERO_MAX_HORIZONTAL_DESACCELERETION;

	if (!this->have_ground && this->vertical_acc > HERO_MAX_FALL_VELOCITY)
		this->vertical_acc -= HERO_VERTICAL_DESACCELERETION;
	else
		this->vertical_acc = 0.0f;

	this->next_animation = Death;
	this->body.move(sf::Vector2f(this->horizontal_acc, this->vertical_acc));
};
void Hero::SelfPrintAll(sf::RenderWindow& window)
{};
void Hero::SelfPrintSelected(sf::RenderWindow& window) 
{
	if (this->lastUsedAnimation != this->next_animation)
		this->intToAnimation_map[this->lastUsedAnimation].ResetAnimation();

	this->lastUsedAnimation = this->next_animation;
	this->body.setTextureRect(this->intToAnimation_map[this->next_animation].update(this->elapsed_time, this->faceRight));
	window.draw(this->body);
};