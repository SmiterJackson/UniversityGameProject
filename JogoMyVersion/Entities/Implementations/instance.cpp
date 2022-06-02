#pragma once

#include "../Headers/instance.h"

// STATIC INITIALIZATION
unsigned int Instance::id = 0;

// CONSTRUCTORS
Instance::Instance() :
	own_id(++id)
{
};
Instance::~Instance()
{

};



//ANTIGA VERSÃO

/*DrawableInstance::DrawableInstance() :
	texture(), sprites(), own_id(++id)
{
};
DrawableInstance::DrawableInstance(sf::Texture& Texture):
	texture(Texture), sprites(), own_id(++id)
{

};
DrawableInstance::DrawableInstance(std::string& fileName) :
	texture(), sprites(), own_id(++id)
{
	this->texture.loadFromFile(fileName);
};
DrawableInstance::DrawableInstance(sf::Texture& Texture, sf::Sprite singleSprite) :
	texture(Texture), sprites(), own_id(++id)
{
	this->sprites.push_back(singleSprite);
};
DrawableInstance::DrawableInstance(std::string& fileName, sf::Sprite singleSprite) :
	texture(), sprites(), own_id(++id)
{
	this->texture.loadFromFile(fileName);
	this->sprites.push_back(singleSprite);
};
DrawableInstance::DrawableInstance(sf::Texture& Texture, std::vector<sf::Sprite>* multSprites) :
	texture(Texture), sprites(), own_id(++id)
{
	if (multSprites != nullptr) {
		this->sprites.clear();
		this->sprites = *multSprites;
	}
};
DrawableInstance::DrawableInstance(std::string& fileName, std::vector<sf::Sprite>* multSprites) :
	texture(), sprites(), own_id(++id)
{
	if (!this->texture.loadFromFile(fileName))
		return;

	if (multSprites != nullptr) {
		this->sprites.clear();
		this->sprites = *multSprites;
	}
};
DrawableInstance::DrawableInstance(sf::Texture& Texture, std::vector<sf::IntRect>* multSpritesCuts) :
	texture(Texture), sprites(), own_id(++id)
{
	if (multSpritesCuts != nullptr)
	{
		std::vector<sf::IntRect>::const_iterator cit;

		this->sprites.clear();
		this->sprites.reserve(multSpritesCuts->size());

		for (cit = multSpritesCuts->cbegin(); cit < multSpritesCuts->cend(); ++cit)
			this->sprites.emplace_back(texture, *cit);
	}
};
DrawableInstance::DrawableInstance(std::string& fileName, std::vector<sf::IntRect>* multSpritesCuts) :
	texture(), sprites(), own_id(++id)
{
	if (!this->texture.loadFromFile(fileName))
		return;

	if (multSpritesCuts != nullptr)
	{
		std::vector<sf::IntRect>::const_iterator cit;

		this->sprites.clear();
		this->sprites.reserve(multSpritesCuts->size());

		for (cit = multSpritesCuts->cbegin(); cit < multSpritesCuts->cend(); ++cit)
			this->sprites.emplace_back(texture, *cit);
	}
};
DrawableInstance::DrawableInstance(sf::Texture& Texture, sf::IntRect* multSpritesCuts, unsigned int size):
	texture(Texture), sprites(), own_id(++id)
{
	if (multSpritesCuts != nullptr) {
		unsigned int i;

		this->sprites.reserve(size);

		for (i = 0; i < size; i++)
			this->sprites.emplace_back(texture, multSpritesCuts[i]);
	}
};
DrawableInstance::DrawableInstance(std::string& fileName, sf::Sprite* multSprites, unsigned int size):
	texture(), sprites(), own_id(++id)
{
	if (!this->texture.loadFromFile(fileName))
		return;

	if (multSprites != nullptr) {
		unsigned int i;

		this->sprites.reserve(size);

		for (i = 0; i < size; ++i)
			this->sprites.push_back(multSprites[i]);
	}
};
DrawableInstance::~DrawableInstance()
{
};*/