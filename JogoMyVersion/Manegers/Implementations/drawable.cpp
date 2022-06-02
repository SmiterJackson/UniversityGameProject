#pragma once

#include "../Manegers/Headers/drawble.h"
using namespace drawable;

BaseDrawable::BaseDrawable() :
	texture(), faceRight(true)
{
};
BaseDrawable::BaseDrawable(const sf::Texture& texture, const bool FacesRight) :
	texture(texture), faceRight(FacesRight)
{};
BaseDrawable::BaseDrawable(const std::string fileName, const bool FacesRight) :
	texture(), faceRight(FacesRight)
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
Printable::Printable(const sf::Texture& texture, const bool FacesRight):
	BaseDrawable(texture, FacesRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{};
Printable::Printable(const std::string& fileName, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{};
Printable::Printable(const sf::Texture& texture, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), intToSprite_map(spriteMap.cbegin(), spriteMap.cend()), intToAnimation_map(animationMap.cbegin(), animationMap.cend()), lastUsedAnimation(0)
{};
Printable::Printable(const std::string& fileName, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight) :
	BaseDrawable(fileName, FacesRight), intToSprite_map(spriteMap.cbegin(), spriteMap.cend()), intToAnimation_map(animationMap.cbegin(), animationMap.cend()), lastUsedAnimation(0)
{};
Printable::Printable(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), intToSprite_map(spriteMap), intToAnimation_map(animationMap), lastUsedAnimation(0)
{};
Printable::Printable(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight) :
	BaseDrawable(fileName, FacesRight), intToSprite_map(spriteMap), intToAnimation_map(animationMap), lastUsedAnimation(0)
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

std::unordered_map<unsigned int, Animation>& Printable::GetAnimationsMap()
{
	return this->intToAnimation_map;
};
const std::unordered_map<unsigned int, Animation>& Printable::GetConsAnimationstMap()
{
	return this->intToAnimation_map;
};

void Printable::SetSpritesMap(const std::unordered_map<unsigned int, sf::Sprite>& map)
{ 
	this->intToSprite_map = map; 
};
void Printable::SetSpritesMap(const VecOfPair_key_cutOfSprite& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToSprite_map[mapValues[i].first] = sf::Sprite(this->texture, mapValues[i].second);
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
void Printable::SetAnimationsMap(const VecOfPair_key_AnimationDataType& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToAnimation_map[mapValues[i].first] = Animation(mapValues[i].second);
};
