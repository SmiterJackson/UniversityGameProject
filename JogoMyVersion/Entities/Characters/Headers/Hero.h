#pragma once

#include "../Entities/BaseEntities/Headers/livingEntity.h"
#include "../Lists/Headers/myList.h"
using namespace entities;

class Hero : public LivingEntity, public Animated
{
public:
	Hero();
	Hero(const std::string fileName, const sf::RectangleShape& _body, const VecAnimaValues& _animationMap, 
		 const unsigned int _life_count = 0, const bool _have_ground = false, const float _weight_ceffic = 1.0f);
	~Hero();

	const bool GetCrouching() { return this->crouching; };
	void SetCrouching(const bool state) { this->crouching = state; };
	void InvertCrouching() { this->crouching = !this->crouching; };

	void Initialize();
	void Execute();
	void Damaged();
	void Died();
	void PlayerInputHandler(const sf::Event& event);
	void SelfPrint(sf::RenderWindow& window);

public:
	static unsigned int PlayersNums;

protected:
	enum animations { Idle, Run, Crouch, Jump, Fall, Death, Attack };
	float invec_current_timer;
	bool invenc_frames, crouching;
	const unsigned int playerId;
};