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


/*Animated::Animated() :
	BaseDrawable(), intToAnimation_map(), lastUsedAnimation(0)
{
};
Animated::Animated(sf::Texture& texture, bool FacecRight) :
	BaseDrawable(texture, FacecRight), intToAnimation_map(), lastUsedAnimation(0)
{};
Animated::Animated(std::string& fileName, bool FacecRight) :
	BaseDrawable(fileName, FacecRight), intToAnimation_map(), lastUsedAnimation(0)
{};
Animated::Animated(sf::Texture& texture, std::unordered_map<unsigned int, Animation>& animationMap, bool FacecRight) :
	BaseDrawable(texture, FacecRight), intToAnimation_map(animationMap), lastUsedAnimation(0)
{};
Animated::Animated(sf::Texture& texture, std::unordered_map<unsigned int, Animation>::value_type*& animationValuesPair, bool FacecRight) :
	BaseDrawable(texture, FacecRight), intToAnimation_map(animationValuesPair, animationValuesPair + 1 + sizeof(animationValuesPair)), lastUsedAnimation(0)
{};
Animated::Animated(sf::Texture& texture, std::pair<unsigned int, AnimationDataType>*& animationConstructorMap, unsigned int Size, bool FacecRight) :
	BaseDrawable(texture, FacecRight), intToAnimation_map(), lastUsedAnimation(0)
{
	if (animationConstructorMap != nullptr)
	{
		for (unsigned int i = 0; i < Size; ++i)
			this->intToAnimation_map.insert(std::pair<unsigned int, Animation>(animationConstructorMap[i].first, Animation(animationConstructorMap[i].second)));
	}
};
Animated::Animated(std::string& fileName, std::pair<unsigned int, AnimationDataType>*& animationConstructorMap, unsigned int Size, bool FacecRight) :
	BaseDrawable(fileName, FacecRight), intToAnimation_map(), lastUsedAnimation(0)
{
	if (animationConstructorMap != nullptr)
	{
		for (unsigned int i = 0; i < Size; ++i)
			this->intToAnimation_map.insert(std::pair<unsigned int, Animation>(animationConstructorMap[i].first, Animation(animationConstructorMap[i].second)));
	}
};
Animated::~Animated()
{
};*/
/*SingleSpriteDrawble::SingleSpriteDrawble() :
	BaseDrawable(), sprite()
{
};
SingleSpriteDrawble::SingleSpriteDrawble(sf::Texture& texture): 
	BaseDrawable(texture), sprite()
{
	this->sprite.setTexture(this->texture);
};
SingleSpriteDrawble::SingleSpriteDrawble(std::string fileName) :
	BaseDrawable(fileName), sprite()
{
	this->sprite.setTexture(this->texture);
};
SingleSpriteDrawble::SingleSpriteDrawble(sf::Texture& texture, sf::Sprite& sprite):
	BaseDrawable(texture), sprite(sprite)
{
	this->sprite.setTexture(this->texture);
};
SingleSpriteDrawble::SingleSpriteDrawble(std::string fileName, sf::Sprite& sprite):
	BaseDrawable(fileName), sprite(sprite)
{
	this->sprite.setTexture(this->texture);
};
SingleSpriteDrawble::~SingleSpriteDrawble()
{
};

void SingleSpriteDrawble::SelfPrint(sf::RenderWindow& Window)
{
	Window.draw(this->sprite);
};



MultipleSpriteDrawble::MultipleSpriteDrawble() :
	BaseDrawable(), sprites()
{
};
MultipleSpriteDrawble::MultipleSpriteDrawble(sf::Texture& Texture, IntToSpriteMap& sprites):
	BaseDrawable(Texture), sprites(sprites)
{
};
MultipleSpriteDrawble::MultipleSpriteDrawble(std::string FileName, IntToSpriteMap& sprites) :
	BaseDrawable(FileName), sprites(sprites)
{
};
MultipleSpriteDrawble::MultipleSpriteDrawble(sf::Texture& Texture, IntToSpritesCutsMap::value_type* multiCuts) :
	BaseDrawable(Texture), sprites(multiCuts, multiCuts + 1 + sizeof(multiCuts))
{
};
MultipleSpriteDrawble::MultipleSpriteDrawble(std::string FileName, IntToSpritesCutsMap::value_type* multiCuts) :
	BaseDrawable(FileName), sprites(multiCuts, multiCuts + 1 + sizeof(multiCuts))
{
};
MultipleSpriteDrawble::MultipleSpriteDrawble(sf::Texture& Texture, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts) :
	BaseDrawable(Texture), sprites(multiPairs, multiPairs + 1 + sizeof(multiPairs))
	//ao saber o tipo do array pode-se usar a função "sizeof" para calcular o fim do array, assim sem parâmetro de tamanho é corretamente passado o pointeiro para o fim do array
{
	IntToSpriteMap::iterator it;
	unsigned int i;

	for (it = sprites.begin(), i = 0; it != sprites.end(); ++it, ++i)
		it->second.setTextureRect(spritesCuts[i]);
};
MultipleSpriteDrawble::MultipleSpriteDrawble(std::string FileName, IntToSpriteMap::value_type* multiPairs, sf::IntRect* spritesCuts) :
	BaseDrawable(FileName), sprites(multiPairs, multiPairs +  1 + sizeof(multiPairs))
{
	IntToSpriteMap::iterator it;
	unsigned int i;

	for (it = sprites.begin(), i = 0; it != sprites.end(); ++it, ++i)
		it->second.setTextureRect(spritesCuts[i]);
};
MultipleSpriteDrawble::~MultipleSpriteDrawble()
{
};

void MultipleSpriteDrawble::SelfPrint(sf::RenderWindow& Window)
{
	IntToSpriteMap::iterator it;

	for(it = sprites.begin(); it != sprites.end(); ++it)
		Window.draw(it->second);
};
void MultipleSpriteDrawble::SelfPrint(sf::RenderWindow& Window, int*& spritesKeys)
{
	if (spritesKeys == nullptr)
		return;

	IntToSpriteMap::iterator it;

	for(int i = 0; i < 1 + sizeof(spritesKeys); ++i)
	{
		it = sprites.find(spritesKeys[i]);
		if(it != sprites.end())
			Window.draw(it->second);
	}
};*/