#pragma once

#include "../Entities/BaseEntities/Headers/livingEntity.h"
#include "../Manegers//Headers/traits.h"
#include "../Lists/Headers/myList.h"
using namespace entities;
using namespace traits;

class Hero : public LivingEntity, public Animated
{
public:
	Hero();
	Hero(const std::string fileName, const sf::RectangleShape& _body, const VecAnimaValues& _animationMap, 
		 const unsigned int _life_count = 0, const bool _have_ground = false, const float _weight_ceffic = 1.0f);
	~Hero();

	const bool& GetIfAttacked() { return this->attacked; };

	void Initialize();
	void Execute();
	void Damaged();
	void Attacked();
	void Died();
	void PlayerInputHandler(const sf::Event& event);
	void SelfPrint(sf::RenderWindow& window);

public:
	static unsigned int PlayersNums;

protected:
	enum animations { Idle, Run, Crouch, Jump, Fall, Death, Attack };
	float invec_current_timer;
	bool invenc_frames, crouching, attacked;
	const unsigned int playerId;
private:
	sf::Texture texture_muzzle, texture_stream;
	sf::Sprite stream, muzzle;
};