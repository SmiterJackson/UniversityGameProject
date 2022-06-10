#pragma once

#include "../Entities/Projectiles/Headers/heroProjectile.h"
#include "../Entities/BaseEntities/Headers/livingEntity.h"
#include "../Lists/Headers/myList.h"
using namespace projectiles;

class Hero : public LivingEntity, public Animated
{
public:
	Hero();
	Hero(const sf::Vector2f& windowSize, const sf::Vector2f& backgroundSize, const std::string fileName, const sf::RectangleShape& _body, const VecAnimaValues& _animationMap,
		 const unsigned int _life_count = 0, const bool _have_ground = false, const float _weight_ceffic = 1.0f);
	~Hero();

	const bool& GetIfAttacked() { return this->attacked; };
	const sf::View& GetView() { return this->playerPerspec; };

	void UpdatePlayerPerspective(const sf::Vector2f& windowSize);
	void Initialize();
	void Execute();
	void Damaged();
	void Died();
	void PlayerInputHandler(const sf::Event& event);
	void SelfPrint(sf::RenderWindow& window);
	HeroProjectile* Attack();

public:
	static unsigned int PlayersNums;

private:
	enum animations { Idle, Run, Crouch, Jump, Fall, Death };
	bool invenc_frames, crouching, attacked;
	float invec_current_timer;
	sf::Vector2f background_size;
	sf::View playerPerspec;
	const unsigned int playerId;
};