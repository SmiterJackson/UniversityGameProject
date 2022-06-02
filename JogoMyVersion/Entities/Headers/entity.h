#pragma once

#include "stdafx.h"
#include "instance.h"
#include "../Manegers/Headers/drawble.h"
using namespace drawable;

class Entity : public Instance {
public:
	Entity();
	Entity(sf::Texture& texture, bool facingRight = true);
	Entity(sf::Texture& texture, sf::RectangleShape& Body, bool facingRight = true);
	~Entity();

	// SETS/ GETS
	sf::RectangleShape& GetRectShape() { return this->body; };
	const sf::RectangleShape& GetConstRectShape() { return this->body; };
	void SetEntityBody(sf::RectangleShape& newPosition) { this->body = newPosition; };
	
	// FUNCTIONS
	void Execute();
	void SelfPrintAll(sf::RenderWindow& window, float timeDiff);
	void SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff);

protected:
	sf::RectangleShape body;
};

class AnimatedEntity : public Entity, public Animated {
public:
	AnimatedEntity();
	AnimatedEntity(sf::Texture& texture);
	AnimatedEntity(std::string& fileName);
	AnimatedEntity(sf::Texture& texture, std::unordered_map<unsigned int, Animation>& animationMap, sf::RectangleShape& Body);
	AnimatedEntity(sf::Texture& texture, std::unordered_map<unsigned int, Animation>::value_type*& animationValuesPair, sf::RectangleShape& Body);
	AnimatedEntity(sf::Texture& texture, std::pair<unsigned int, AnimationDataType>* animationConstructorMap, unsigned int Size, sf::RectangleShape& Body);
	AnimatedEntity(std::string& fileName, std::pair<unsigned int, AnimationDataType>* animationConstructorMap, unsigned int Size, sf::RectangleShape& Body);
	~AnimatedEntity();

	// SETS/ GETS


	// FUNCTIONS
	void Execute();
	void SelfPrintAll(sf::RenderWindow& window, float timeDiff);
	void SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff);

protected:
	float velocity;
};

// Versão ainda não utilizada

/*
class MultipleSpriteEntity : public MultipleSpriteDrawble, public Instance {
public:
	MultipleSpriteEntity();
	MultipleSpriteEntity(sf::Texture& texture, IntToSpriteMap::value_type& singlePair, sf::RectangleShape& position);
	MultipleSpriteEntity(std::string fileName, IntToSpriteMap::value_type& singlePair, sf::RectangleShape& position);
	MultipleSpriteEntity(sf::Texture& texture, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts, sf::RectangleShape& position);
	MultipleSpriteEntity(std::string fileName, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts, sf::RectangleShape& position);
	~MultipleSpriteEntity();

	const sf::RectangleShape& GetEntityPosition() { return this->position; };
	void SetEntityPosition(sf::RectangleShape& newPosition) { this->position = newPosition; };

	void Execute();
	void SelfPrint(sf::RenderWindow& Window, float time);

protected:
	sf::RectangleShape position;
};*/