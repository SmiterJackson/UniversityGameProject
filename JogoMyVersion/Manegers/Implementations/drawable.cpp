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


Drawable_Animated::Drawable_Animated() :
	BaseDrawable(), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{
};
Drawable_Animated::Drawable_Animated(const sf::Texture& texture, const bool FacesRight):
	BaseDrawable(texture, FacesRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{};
Drawable_Animated::Drawable_Animated(const std::string& fileName, const bool FacesRight) :
	BaseDrawable(fileName, FacesRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{};
Drawable_Animated::Drawable_Animated(const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{
	unsigned int i = 0;
	for(i = 0; i < spriteMap.size(); i++)
		intToSprite_map[spriteMap[i].first] = sf::Sprite(this->texture, spriteMap[i].second);

	for (i = 0; i < animationMap.size(); ++i)
		intToAnimation_map[animationMap[i].first] = Animation(animationMap[i].second);
};
Drawable_Animated::Drawable_Animated(const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight) :
	BaseDrawable(fileName, FacesRight), intToSprite_map(), intToAnimation_map(), lastUsedAnimation(0)
{
	unsigned int i = 0;
	for (i = 0; i < spriteMap.size(); i++)
		intToSprite_map[spriteMap[i].first] = sf::Sprite(this->texture, spriteMap[i].second);

	for (i = 0; i < animationMap.size(); ++i)
		intToAnimation_map[animationMap[i].first] = Animation(animationMap[i].second);
};
Drawable_Animated::Drawable_Animated(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), intToSprite_map(spriteMap), intToAnimation_map(animationMap), lastUsedAnimation(0)
{};
Drawable_Animated::Drawable_Animated(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight) :
	BaseDrawable(fileName, FacesRight), intToSprite_map(spriteMap), intToAnimation_map(animationMap), lastUsedAnimation(0)
{};
Drawable_Animated::~Drawable_Animated()
{
};

// Sets / Gets - Drawable
std::unordered_map<unsigned int, sf::Sprite>& Drawable_Animated::GetSpritesMap() 
{ 
	return this->intToSprite_map; 
};
const std::unordered_map<unsigned int, sf::Sprite>& Drawable_Animated::GetConstSpritesMap() 
{ 
	return this->intToSprite_map; 
};

std::unordered_map<unsigned int, Animation>& Drawable_Animated::GetAnimationsMap()
{
	return this->intToAnimation_map;
};
const std::unordered_map<unsigned int, Animation>& Drawable_Animated::GetConsAnimationstMap()
{
	return this->intToAnimation_map;
};

void Drawable_Animated::SetSpritesMap(const std::unordered_map<unsigned int, sf::Sprite>& map)
{ 
	this->intToSprite_map = map; 
};
void Drawable_Animated::SetSpritesMap(const VecOfPair_key_cutOfSprite& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToSprite_map[mapValues[i].first] = sf::Sprite(this->texture, mapValues[i].second);
};

void Drawable_Animated::SetAnimationsMap(const std::unordered_map<unsigned int, Animation>& map)
{
	this->intToAnimation_map = map;
};
void Drawable_Animated::SetAnimationsMap(const std::vector<std::pair<unsigned int, Animation>>& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToAnimation_map[mapValues[i].first] = mapValues[i].second;
};
void Drawable_Animated::SetAnimationsMap(const VecOfPair_key_AnimationDataType& mapValues)
{
	for (unsigned int i = 0; i < mapValues.size(); i++)
		intToAnimation_map[mapValues[i].first] = Animation(mapValues[i].second);
};
