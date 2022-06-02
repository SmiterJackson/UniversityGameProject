#pragma once

#include "../Manegers/Headers/drawble.h"
using namespace drawable;

BaseDrawable::BaseDrawable() :
	texture(), faceRight(true)
{
};
BaseDrawable::BaseDrawable(const sf::Texture& texture, bool FacecRight) :
	texture(texture), faceRight(FacecRight)
{
};
BaseDrawable::BaseDrawable(const std::string fileName, bool FacecRight) :
	texture(), faceRight(FacecRight)
{
	texture.loadFromFile(fileName);
};
BaseDrawable::~BaseDrawable()
{
};


Printable::Printable() :
	BaseDrawable(), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{
};
Printable::Printable(const sf::Texture& texture, const bool FacecRight = true):
	BaseDrawable(texture, FacecRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{};
Printable::Printable(const std::string& fileName, const bool FacecRight = true) :
	BaseDrawable(texture, FacecRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{};
Printable::Printable(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, bool FacecRight) :
	BaseDrawable(texture, FacecRight), intToSprite_map(spriteMap), intToAnimation_map(animationMap), lastUsedAnimation(0)
{};
Printable::Printable(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, bool FacecRight) :
	BaseDrawable(fileName, FacecRight), intToSprite_map(spriteMap), intToAnimation_map(animationMap), lastUsedAnimation(0)
{};
Printable::Printable(const sf::Texture& texture, const std::vector<std::pair<unsigned int, sf::IntRect>>& spriteMap, std::vector<std::pair<unsigned int, AnimationDataType>>& animationMap, bool FacecRight) :
	BaseDrawable(texture, FacecRight), intToSprite_map(spriteMap.cbegin(), spriteMap.cend()), intToAnimation_map(animationMap.cbegin(), animationMap.cend()), lastUsedAnimation(0)
{};
Printable::Printable(const std::string& fileName, const std::vector<std::pair<unsigned int, sf::IntRect>>& spriteMap, std::vector<std::pair<unsigned int, AnimationDataType>>& animationMap, bool FacecRight) :
	BaseDrawable(fileName, FacecRight), intToSprite_map(spriteMap.cbegin(), spriteMap.cend()), intToAnimation_map(animationMap.cbegin(), animationMap.cend()), lastUsedAnimation(0)
{};
Printable::~Printable()
{
};

// Sets / Gets - Drawable
std::unordered_map<unsigned int, sf::Sprite>& Printable::GetSpritesMap() 
{ 
	return this->intToSprite_map; 
};
const std::unordered_map<unsigned int, sf::Sprite>& Printable::GetConstSpritesMap() 
{ 
	return this->intToSprite_map; 
};
void Printable::SetSpritesMap(const std::unordered_map<unsigned int, sf::Sprite>& map)
{ 
	this->intToSprite_map = map; 
};
void Printable::SetSpritesMap(const std::vector<std::pair<unsigned int, sf::IntRect>>& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToSprite_map[mapValues[i].first] = sf::Sprite(this->texture, mapValues[i].second);
};

std::unordered_map<unsigned int, Animation>& Printable::GetAnimationsMap() 
{ 
	return this->intToAnimation_map; 
};
const std::unordered_map<unsigned int, Animation>& Printable::GetConsAnimationstMap()
{
	return this->intToAnimation_map; 
};
void Printable::SetAnimationsMap(const std::unordered_map<unsigned int, Animation>& map)
{
	this->intToAnimation_map = map;
};
void Printable::SetAnimationsMap(const std::vector<std::pair<unsigned int, Animation>>& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToAnimation_map[mapValues[i].first] = mapValues[i].second;
};
void Printable::SetAnimationsMap(const std::vector<std::pair<unsigned int, AnimationDataType>>& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToAnimation_map[mapValues[i].first] = Animation(mapValues[i].second);
};
