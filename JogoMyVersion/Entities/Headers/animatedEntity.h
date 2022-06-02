#pragma once

#include "stdafx.h"
#include "entity.h"
#include "../Manegers/Headers/animation.h"

/*typedef std::unordered_map<int, Animation> IntToAnimation;
class AnimatedEntity : public AnimatedEntity {
public:
	// CONSTRUCTORS
	AnimatedEntity();
	AnimatedEntity(sf::Texture& texture, IntToAnimation::value_type* animationMaping);
	AnimatedEntity(std::string fileName, IntToAnimation::value_type* animationMaping);
	AnimatedEntity(sf::Texture& texture, sf::RectangleShape& position, IntToAnimation::value_type* animationMaping);
	AnimatedEntity(std::string fileName, sf::RectangleShape& position, IntToAnimation::value_type* animationMaping);
	AnimatedEntity(sf::Texture& texture, sf::Sprite& sprite, sf::RectangleShape& position, IntToAnimation::value_type* animationsMap);
	AnimatedEntity(std::string fileName, sf::Sprite& sprite, sf::RectangleShape& position, IntToAnimation::value_type* animationsMap);
	~AnimatedEntity();

	// SETS / GETS
	IntToAnimation& GetAnimations() { return animations; };
	void SetAnimations(IntToAnimation& AnimationsVec) { animations = AnimationsVec; };

	// FUNCTIONS
	void Execute();
	void SelfPrint(sf::RenderWindow& Window, unsigned int animationKey, float TimeDiff, bool direita);

protected:
	IntToAnimation animations;
};*/