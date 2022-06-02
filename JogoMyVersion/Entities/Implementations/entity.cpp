#pragma once

#include "stdafx.h"
#include "../Headers/entity.h"

Entity::Entity() :
	Instance(), body()
{};
Entity::Entity(sf::Texture& texture, bool facingRight) :
	Instance(), body()
{
	this->body.setTexture(texture);
};
Entity::Entity(sf::Texture& texture, sf::RectangleShape& Body, bool facingRight) :
	Instance(), body()
{
	this->body.setTexture(texture);
};
Entity::~Entity()
{};

void Entity::SelfPrintAll(sf::RenderWindow& window, float timeDiff) 
{
	
};
void Entity::SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff) 
{
	
};


// CONSTRUCTORS
AnimatedEntity::AnimatedEntity() :
	Entity(), Animated(), velocity()
{};
AnimatedEntity::AnimatedEntity(sf::Texture& texture) :
	Entity(texture), Animated(), velocity()
{};
AnimatedEntity::AnimatedEntity(std::string& fileName) :
	Entity(fileName), Animated(), velocity()
{};
AnimatedEntity::AnimatedEntity(sf::Texture& texture, std::unordered_map<unsigned int, Animation>& animationMap, sf::RectangleShape& Body) :
	Entity(texture, animationMap, Body), Animated(), velocity()
{};
AnimatedEntity::AnimatedEntity(sf::Texture& texture, std::unordered_map<unsigned int, Animation>::value_type*& animationValuesPair, sf::RectangleShape& Body) :
	Entity(), Animated(), velocity()
{};
AnimatedEntity::AnimatedEntity(sf::Texture& texture, std::pair<unsigned int, AnimationDataType>* animationConstructorMap, unsigned int Size, sf::RectangleShape& Body) :
	Entity(), Animated(), velocity()
{};
AnimatedEntity::AnimatedEntity(std::string& fileName, std::pair<unsigned int, AnimationDataType>* animationConstructorMap, unsigned int Size, sf::RectangleShape& Body) :
	Entity(), Animated(), velocity()
{};
AnimatedEntity::~AnimatedEntity()
{};

void AnimatedEntity::SelfPrintAll(sf::RenderWindow& window, float timeDiff)
{
	std::unordered_map<unsigned int, Animation>::iterator it;
	for (it = this->intToAnimation_map.begin(); it != this->intToAnimation_map.end(); ++it)
	{
		this->body.setTextureRect(it->second.update(timeDiff, this->right));
		window.draw(body);
	}
};
void AnimatedEntity::SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff)
{
	// atualiza a animação e insere-a como posição na textura do "body"
	sf::IntRect newsprite = this->intToAnimation_map.find(animationKey)->second.update(timeDiff, this->right);
	this->body.setTextureRect(newsprite);
	window.draw(this->body);
};



/*Entity::Entity() :
	SingleSpriteDrawble(), body()
{
};
Entity::Entity(sf::Texture& texture):
	SingleSpriteDrawble(texture), Instance(), body()
{
	this->body.setTexture(&texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
Entity::Entity(std::string fileName) :
	SingleSpriteDrawble(fileName), Instance(), body(body)
{
	this->body.setTexture(&texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
Entity::Entity(sf::Texture& texture, sf::RectangleShape& position):
	SingleSpriteDrawble(texture), Instance(), body(position)
{
	this->body.setTexture(&texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
Entity::Entity(std::string fileName, sf::RectangleShape& position) :
	SingleSpriteDrawble(fileName), Instance(), body(position)
{
	this->body.setTexture(&texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
Entity::Entity(sf::Texture& texture, sf::Sprite& sprite, sf::RectangleShape& position) :
	SingleSpriteDrawble(texture, sprite), Instance(), body(position)
{
	this->body.setTexture(&texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
Entity::Entity(std::string fileName, sf::Sprite& sprite, sf::RectangleShape& position) :
	SingleSpriteDrawble(fileName, sprite), Instance(), body(position)
{
	this->body.setTexture(&texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
Entity::~Entity()
{
};

void Entity::Execute()
{
};
void Entity::SelfPrint(sf::RenderWindow& Window, float time)
{
};*/

/*
MultipleSpriteEntity::MultipleSpriteEntity() :
	MultipleSpriteDrawble(), Instance(), position()
{
};
MultipleSpriteEntity::MultipleSpriteEntity(sf::Texture& texture, IntToSpriteMap::value_type& singlePair, sf::RectangleShape& position) :
	MultipleSpriteDrawble(texture, singlePair), Instance(), position(position)
{
};
MultipleSpriteEntity::MultipleSpriteEntity(std::string fileName, IntToSpriteMap::value_type& singlePair, sf::RectangleShape& position) :
	MultipleSpriteDrawble(fileName, singlePair), Instance(), position(position)
{
};
MultipleSpriteEntity::MultipleSpriteEntity(sf::Texture& texture, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts, sf::RectangleShape& position) :
	MultipleSpriteDrawble(texture, multiPairs, spritesCuts), Instance(), position(position)
{
};
MultipleSpriteEntity::MultipleSpriteEntity(std::string fileName, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts, sf::RectangleShape& position) :
	MultipleSpriteDrawble(fileName, multiPairs, spritesCuts), Instance(), position(position)
{
};
MultipleSpriteEntity::~MultipleSpriteEntity()
{
};

void MultipleSpriteEntity::Execute()
{
};
void MultipleSpriteEntity::SelfPrint(sf::RenderWindow& Window, float time)
{
};*/