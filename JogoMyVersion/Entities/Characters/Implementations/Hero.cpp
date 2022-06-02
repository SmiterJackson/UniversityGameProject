#include "../Entities/Characters/Headers/Hero.h"
using namespace sf;

#define HERO_HORIZONTAL_ACCELERETION 1.0f
#define HERO_MAX_HORIZONTAL_ACCELERETION 10.0f
#define HERO_VERTICAL_ACCELERETION 20.0f
#define HERO_VERTICAL_DESACCELERETION (HERO_VERTICAL_ACCELERETION/2)
#define HERO_MAX_FALL_VELOCITY -(HERO_VERTICAL_ACCELERETION/2)

Hero::Hero() :
	LivingEntity(), Slipery(), next_animation(Idle)
{
	this->body.setTexture(&this->texture);
};
Hero::Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, texture, _life_count, FacesRight, _have_ground), Slipery(), next_animation(Idle)
{
	this->body.setTexture(&this->texture);
};
Hero::Hero(const sf::RectangleShape& Body, const std::string& fileName, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, fileName, _life_count, FacesRight, _have_ground), Slipery(), next_animation(Idle)
{
	this->body.setTexture(&this->texture);
};
Hero::Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap, const std::vector<std::pair<unsigned int, AnimationDataType>>& animationMap,
			const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, texture, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), next_animation(Idle)
{
	this->body.setTexture(&this->texture);
};
Hero::Hero(const sf::RectangleShape& Body, const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap, const std::vector<std::pair<unsigned int, AnimationDataType>>& animationMap,
			const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, fileName, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), next_animation(Idle)
{
	this->body.setTexture(&this->texture);
};
Hero::Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
			const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, texture, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), next_animation(Idle)
{
	this->body.setTexture(&this->texture);
};
Hero::Hero(const sf::RectangleShape& Body, const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
			const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	LivingEntity(Body, fileName, spriteMap, animationMap, _life_count, FacesRight, _have_ground), Slipery(), next_animation(Idle)
{
	this->body.setTexture(&this->texture);
};
Hero::~Hero()
{};

void Hero::Execute()
{
	if(!(Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D))) // Caso ambas as direções estejam clicadas ignora a situação
	{
		if (Keyboard::isKeyPressed(Keyboard::A) && this->horizontal_acc > -HERO_MAX_HORIZONTAL_ACCELERETION)
		{
			this->faceRight = false;
			if(this->have_ground)
				this->next_animation = Run;
			this->horizontal_acc -= HERO_HORIZONTAL_ACCELERETION;
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && this->horizontal_acc < HERO_MAX_HORIZONTAL_ACCELERETION)
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
			this->horizontal_acc = 0.0f;
			if (this->have_ground)
				this->next_animation = Idle;
		}
			
		else if (this->horizontal_acc > 0.0f)
			this->horizontal_acc -= HERO_HORIZONTAL_ACCELERETION;
		else
			this->horizontal_acc += HERO_HORIZONTAL_ACCELERETION;
	}

	if(this->have_ground && Keyboard::isKeyPressed(Keyboard::S))
	{
		this->next_animation = Crouch;
	}

	if (this->have_ground && Keyboard::isKeyPressed(Keyboard::W)) // Caso esteja no chão e pule, acelera para cima
	{
		this->next_animation = Jump;
		this->vertical_acc = HERO_VERTICAL_ACCELERETION;
	}
	else if (!this->have_ground && this->vertical_acc > HERO_MAX_FALL_VELOCITY) // Caso esteja no ar começa a desacelerar e cair 
		this->vertical_acc -= HERO_VERTICAL_DESACCELERETION;
	else
		this->vertical_acc = 0.0f;

	this->horizontal_acc *= (this->friction_coefficient * this->global_friction);
	this->body.move(sf::Vector2f(this->horizontal_acc, this->vertical_acc));
};
void Hero::Died()
{
	this->horizontal_acc = 0.0f;

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