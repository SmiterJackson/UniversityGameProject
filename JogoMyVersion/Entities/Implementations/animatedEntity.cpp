#pragma once

#include "stdafx.h"
#include "../Headers/animatedEntity.h"

// CONSTRUCTORS
/*AnimatedEntity::AnimatedEntity() :
	Entity(), animations()
{
};
AnimatedEntity::AnimatedEntity(sf::Texture& texture, IntToAnimation::value_type* animationMaping):
	Entity(texture), animations(animationMaping, animationMaping + 1 + sizeof(animationMaping))
{
};
AnimatedEntity::AnimatedEntity(std::string fileName, IntToAnimation::value_type* animationMaping) :
	Entity(fileName), animations(animationMaping, animationMaping + 1 + sizeof(animationMaping))
{
};
AnimatedEntity::AnimatedEntity(sf::Texture& texture, sf::RectangleShape& position, IntToAnimation::value_type* animationMaping) :
	Entity(texture,  position), animations(animationMaping, animationMaping + 1 + sizeof(animationMaping))
{
};
AnimatedEntity::AnimatedEntity(std::string fileName, sf::RectangleShape& position, IntToAnimation::value_type* animationMaping) :
	Entity(fileName, position), animations(animationMaping, animationMaping + 1 + sizeof(animationMaping))
{
};
AnimatedEntity::AnimatedEntity(sf::Texture& texture, sf::Sprite& sprite, sf::RectangleShape& position, IntToAnimation::value_type* animationsMap) :
	Entity(texture, sprite, position), animations(animationsMap, animationsMap + 1 + sizeof(animationsMap))
{
};
AnimatedEntity::AnimatedEntity(std::string fileName, sf::Sprite& sprite, sf::RectangleShape& position, IntToAnimation::value_type* animationsMap):
	Entity(fileName, sprite, position), animations(animationsMap, animationsMap + 1 + sizeof(animationsMap))
{
};
AnimatedEntity::~AnimatedEntity()
{
};*/


// FUNCTIONS
/*void AnimatedEntity::Execute()
{

};
void AnimatedEntity::SelfPrint(sf::RenderWindow& Window, unsigned int animationKey, float TimeDiff, bool direita)
{
	this->body.setTextureRect(this->animations.find(animationKey)->second.update(TimeDiff, direita));

	Window.draw(this->body);
};*/



//AnimatedEntity::AnimatedEntity():
//	Entity(), animations()
//{
//};
//AnimatedEntity::AnimatedEntity(sf::Texture& Texture, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(Texture, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(std::string& fileName, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(fileName, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(sf::Texture& Texture, sf::Sprite singleSprite, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(Texture, singleSprite, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(std::string& fileName, sf::Sprite singleSprite, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(fileName, singleSprite, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(sf::Texture& Texture, std::vector<sf::Sprite>* multSprites, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(Texture, multSprites, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(std::string& fileName, std::vector<sf::Sprite>* multSprites, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(fileName, multSprites, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(sf::Texture& Texture, std::vector<sf::IntRect>* multSpritesCuts, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(Texture, multSpritesCuts, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(std::string& fileName, std::vector<sf::IntRect>* multSpritesCuts, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(fileName, multSpritesCuts, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(sf::Texture& Texture, sf::IntRect* multSpritesCuts, unsigned int size, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(Texture, multSpritesCuts, size, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::AnimatedEntity(std::string& fileName, sf::Sprite* multSprites, unsigned int size, sf::Vector2f entity_position, std::vector<Animation>& animationsVec):
//	Entity(fileName, multSprites, size, entity_position), animations(animationsVec)
//{
//};
//AnimatedEntity::~AnimatedEntity()
//{
//};
// FUNCTIONS
//AnimatedEntity::
//AnimatedEntity::
//sf::IntRect rects[9] = { {0, 0, SIZE, SIZE},
//                        {0 * SIZE, 1 * SIZE, SIZE, SIZE},
//                        {0 * SIZE, 2 * SIZE, SIZE, SIZE},
//                        {6 * SIZE, 2 * SIZE, SIZE, SIZE},
//                        {0 * SIZE, 3 * SIZE, SIZE, SIZE},
//                        {5 * SIZE, 3 * SIZE, SIZE, SIZE},
//                        {0 * SIZE, 4 * SIZE, SIZE, SIZE},
//                        {3 * SIZE, 4 * SIZE, SIZE, SIZE},
//                        {5 * SIZE, 4 * SIZE, SIZE, SIZE} };
//
//Animation Animas[9] = { {0, 10, 0, 135, 0.20f},
//                       {0, 9, 1, 135, 0.20f},
//                       {0, 6, 2, 135, 0.20f},
//                       {6, 10, 2, 135, 0.20f},
//                       {0, 5, 3, 135, 0.20f},
//                       {5, 9, 3, 135, 0.20f},
//                       {0, 3, 4, 135, 0.20f},
//                       {3, 5, 4, 135, 0.20f},
//                       {4, 6, 4, 135, 0.20f} };


/*if (animationMaping == nullptr)
	return;

IntToAnimation::iterator it;
int i;

this->animations.reserve(sizeof(animationMaping));

for (it = this->animations.begin(), i = 0; it != this->animations.end(); ++it, ++i);
	this->animations.emplace(animationMaping[i].first, animationMaping[i].second);*/