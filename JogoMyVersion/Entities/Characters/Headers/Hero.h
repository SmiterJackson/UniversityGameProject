#pragma once

#include "../Entities/Headers/entity.h"

class Hero : public entities::LivingEntity, public Slipery{
public:
	Hero();
	Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
	Hero(const sf::RectangleShape& Body, const std::string& fileName, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
	Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
		const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
	Hero(const sf::RectangleShape& Body, const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
		const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
	Hero(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
		const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
	Hero(const sf::RectangleShape& Body, const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
		const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
	~Hero();
	
	void Initialize();
	void Execute();
	void Damaged();
	void Died();
	void SelfPrintAll(sf::RenderWindow& window);
	void SelfPrintSelected(sf::RenderWindow& window);

public:
	enum animations { Idle, Run, Crouch, Jump, Death };
	const float invec_time;
	float invec_current_timer;
	bool invenc_frames;
};