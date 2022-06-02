#pragma once

#include "../Entities/Headers/entity.h"

class Hero : public Entities::LivingEntity, public Slipery{
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
	
	void Execute();
	void Died();
	void SelfPrintAll(sf::RenderWindow& window);
	void SelfPrintSelected(sf::RenderWindow& window);

public:
	enum animations { none = 0, Idle, Run, Crouch, Jump, Death };
	unsigned int next_animation;
};