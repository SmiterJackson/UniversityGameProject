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


WithAnimation::WithAnimation() :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
WithAnimation::WithAnimation(const std::vector<Animation>& _animationMap) :
	animationVec(_animationMap), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{};
WithAnimation::WithAnimation(const VecAnimaValues& _animationMap) :
	animationVec(), next_ani(0), lastUsedAni(0), elapsed_time(0.0f)
{
	size_t diff = this->animationVec.capacity() - this->animationVec.size();
	this->animationVec.reserve(diff + _animationMap.size());

	for (unsigned int i = 0; i < _animationMap.size(); ++i)
		this->animationVec.emplace_back(_animationMap[i]);
};
WithAnimation::~WithAnimation()
{};


SingleSpriteDrawable::SingleSpriteDrawable() :
	BaseDrawable(), WithAnimation(), sprite()
{
	sprite.setTexture(this->texture);
};
SingleSpriteDrawable::SingleSpriteDrawable(const sf::Sprite& _sprite, const sf::Texture& texture, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), WithAnimation(), sprite(_sprite)
{
	sprite.setTexture(this->texture);
};
SingleSpriteDrawable::SingleSpriteDrawable(const sf::Sprite& _sprite, const std::string texture_fileName, const bool FacesRight) :
	BaseDrawable(texture_fileName, FacesRight), WithAnimation(), sprite(_sprite)
{
	sprite.setTexture(this->texture);
};
SingleSpriteDrawable::~SingleSpriteDrawable()
{};


MultipleSpriteDrawable::MultipleSpriteDrawable() :
	BaseDrawable(), WithAnimation(), spritesVec()
{};
MultipleSpriteDrawable::MultipleSpriteDrawable(const std::vector<sf::Sprite>& _spritesVec, const sf::Texture& texture, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), WithAnimation(), spritesVec(_spritesVec)
{
	sf::FloatRect rect;

	for (unsigned int i = 0; i < spritesVec.size(); ++i)
	{
		spritesVec[i].setTexture(this->texture);
		rect = this->spritesVec[i].getGlobalBounds();
		spritesVec[i].setOrigin((rect.width - rect.left) / 2.0f, (rect.height - rect.top) / 2.0f);
	}
};
MultipleSpriteDrawable::MultipleSpriteDrawable(const std::vector<sf::IntRect>& _spritesVecValues, const std::string texture_fileName, const bool FacesRight) :
	BaseDrawable(texture_fileName, FacesRight), WithAnimation(), spritesVec()
{
	sf::FloatRect rect;
	size_t diff = this->spritesVec.capacity() - this->spritesVec.size();
	this->spritesVec.reserve(diff + _spritesVecValues.size());

	for (unsigned int i = 0; i < _spritesVecValues.size(); ++i)
	{
		this->spritesVec.emplace_back(this->texture, _spritesVecValues[i]);
		rect = this->spritesVec[i].getGlobalBounds();
		this->spritesVec[i].setOrigin((rect.width - rect.left) / 2.0f, (rect.height - rect.top) / 2.0f);
	}
};
MultipleSpriteDrawable::~MultipleSpriteDrawable()
{};


SingleRectangleDrawable::SingleRectangleDrawable() :
	BaseDrawable(), WithAnimation(), body()
{
	this->body.setTexture(&this->texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
SingleRectangleDrawable::SingleRectangleDrawable(const sf::RectangleShape& _body, const sf::Texture& texture, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), WithAnimation(), body(_body)
{
	this->body.setTexture(&this->texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
SingleRectangleDrawable::SingleRectangleDrawable(const sf::RectangleShape& _body, const std::string texture_fileName, const bool FacesRight) :
	BaseDrawable(texture_fileName, FacesRight), WithAnimation(), body(_body)
{
	this->body.setTexture(&this->texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
SingleRectangleDrawable::SingleRectangleDrawable(const sf::RectangleShape& _body, const sf::Texture& texture, const VecAnimaValues& _animationMap, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), WithAnimation(_animationMap), body(_body)
{
	this->body.setTexture(&this->texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
SingleRectangleDrawable::SingleRectangleDrawable(const sf::RectangleShape& _body, const std::string texture_fileName, const VecAnimaValues& _animationMap, const bool FacesRight) :
	BaseDrawable(texture_fileName, FacesRight), WithAnimation(_animationMap), body(_body)
{
	this->body.setTexture(&this->texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
SingleRectangleDrawable::SingleRectangleDrawable(const sf::RectangleShape& _body, const sf::Texture& texture, const std::vector<Animation>& _animationMap, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), WithAnimation(_animationMap), body(_body)
{
	this->body.setTexture(&this->texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
SingleRectangleDrawable::SingleRectangleDrawable(const sf::RectangleShape& _body, const std::string texture_fileName, const std::vector<Animation>& _animationMap, const bool FacesRight) :
	BaseDrawable(texture_fileName, FacesRight), WithAnimation(_animationMap), body(_body)
{
	this->body.setTexture(&this->texture);
	this->body.setOrigin(this->body.getSize() / 2.0f);
};
SingleRectangleDrawable::~SingleRectangleDrawable()
{};


MultipleRectangleDrawable::MultipleRectangleDrawable() :
	BaseDrawable(), WithAnimation(), bodiesVec()
{};
MultipleRectangleDrawable::MultipleRectangleDrawable(const std::vector<sf::RectangleShape>& _bodiesVec, const sf::Texture& texture, const bool FacesRight) :
	BaseDrawable(texture, FacesRight), WithAnimation(), bodiesVec(_bodiesVec)
{};
MultipleRectangleDrawable::~MultipleRectangleDrawable()
{};