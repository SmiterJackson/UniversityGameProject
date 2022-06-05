#include "../Entities/Characters/Headers/Hero.h"
using namespace sf;
using namespace traits;
using namespace entities;

#define HERO_HORIZONTAL_ACCELERETION 1.0f
#define HERO_MAX_HORIZONTAL_DESACCELERETION HERO_HORIZONTAL_ACCELERETION
#define HERO_MAX_HORIZONTAL_ACCELERETION 10.0f
#define HERO_VERTICAL_ACCELERETION 36.0f
#define HERO_VERTICAL_DESACCELERETION (HERO_VERTICAL_ACCELERETION/18)
#define HERO_MAX_FALL_VELOCITY (HERO_VERTICAL_ACCELERETION/2)
#define HERO_INVENCIBILITY_FRAMES_TIME 3.0f

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
				this->next_ani = Run;
			this->horizontal_acc -= HERO_HORIZONTAL_ACCELERETION;
		}
		if (isD_pressed && this->horizontal_acc < HERO_MAX_HORIZONTAL_ACCELERETION)
		{
			this->faceRight = true;
			if (this->have_ground)
				this->next_ani = Run;
			this->horizontal_acc += HERO_HORIZONTAL_ACCELERETION;
		}
	}
	else {
		if (this->horizontal_acc >= -0.1f || this->horizontal_acc <= 0.1f)
		{
			//this->horizontal_acc = 0.0f;

			if (this->have_ground)
				this->next_ani = Idle;
		}

		if (this->horizontal_acc > 0.0f)
			this->horizontal_acc -= HERO_MAX_HORIZONTAL_DESACCELERETION;

		if (this->horizontal_acc < 0.0f)
			this->horizontal_acc += HERO_MAX_HORIZONTAL_DESACCELERETION;
	}

	if(this->have_ground && Keyboard::isKeyPressed(Keyboard::S))
	{
		this->next_ani = Crouch;
	}

	if (this->have_ground && Keyboard::isKeyPressed(Keyboard::W)) // Caso esteja no chão e pule, acelera para cima
	{
		this->have_ground = false;
		this->next_ani = Jump;
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
		this->invec_current_timer = HERO_INVENCIBILITY_FRAMES_TIME;
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

/*Hero::Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(_life_count, _have_ground, &body), SingleRectangleDrawable(_body, texture, FacesRight), Slipery(), invec_current_timer(0.0f), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const std::string& fileName, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(_life_count, _have_ground, &body), SingleRectangleDrawable(_body, fileName, FacesRight), Slipery(), invec_current_timer(0.0f), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const std::vector<Animation>& _animationMap, const unsigned int _life_count,
	const bool FacesRight, const bool _have_ground) :
	LivingEntity(_life_count, _have_ground, &body), SingleRectangleDrawable(_body, texture, _animationMap, FacesRight), Slipery(), invec_current_timer(0.0f), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const std::string& fileName, const std::vector<Animation>& _animationMap, const unsigned int _life_count,
	const bool FacesRight, const bool _have_ground) :
	LivingEntity(_life_count, _have_ground, &body), SingleRectangleDrawable(_body, fileName, _animationMap, FacesRight), Slipery(), invec_current_timer(0.0f), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const VecAnimaValues& _animationMap, const unsigned int _life_count,
	const bool FacesRight, const bool _have_ground) :
	LivingEntity(_life_count, _have_ground, &body), SingleRectangleDrawable(_body, texture, _animationMap, FacesRight), Slipery(), invec_current_timer(0.0f), invenc_frames(false)
{
	Initialize();
};
Hero::Hero(const sf::RectangleShape& _body, const std::string& fileName, const VecAnimaValues& _animationMap, const unsigned int _life_count,
	const bool FacesRight, const bool _have_ground) :
	LivingEntity(_life_count, _have_ground, &body), SingleRectangleDrawable(_body, fileName, _animationMap, FacesRight), Slipery(), invec_current_timer(0.0f), invenc_frames(false)
{
	Initialize();
};*/