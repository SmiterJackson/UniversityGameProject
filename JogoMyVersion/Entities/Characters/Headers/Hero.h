#pragma once

#include "../Manegers/Headers/traits.h"
#include "../Entities/BaseEntities/Headers/entity.h"
using namespace traits;
using namespace entities;

class Hero : public LivingEntity, public Printable, public Animated, public Slipery
{
public:
	Hero();
	Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const unsigned int _life_count = 3, const float _weight_ceffic = 0.0f, 
		const bool _have_ground = false);
	Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const VecAnimaValues& _animationMap, const unsigned int _life_count = 3, 
		const float _weight_ceffic = 0.0f, const bool _have_ground = false);
	Hero(const sf::RectangleShape& _body, const sf::Texture& texture, const std::vector<Animation>& _animationMap, const unsigned int _life_count = 3, 
		const float _weight_ceffic = 0.0f, const bool _have_ground = false);
	Hero(const sf::RectangleShape& _body, const std::string fileName, const unsigned int _life_count = 3, const float _weight_ceffic = 0.0f, 
		const bool _have_ground = false);
	Hero(const sf::RectangleShape& _body, const std::string fileName, const VecAnimaValues& _animationMap, const unsigned int _life_count = 3, 
		const float _weight_ceffic = 0.0f, const bool _have_ground = false);
	Hero(const sf::RectangleShape& _body, const std::string fileName, const std::vector<Animation>& _animationMap, const unsigned int _life_count = 3, 
		const float _weight_ceffic = 0.0f, const bool _have_ground = false);
	~Hero();

	void Initialize();
	void Execute();
	void Damaged();
	void Died();
	void SelfPrint(sf::RenderWindow& window);

public:
	enum animations { Idle, Run, Crouch, Jump, Death, Attack};
	float invec_current_timer;
	bool invenc_frames;
};