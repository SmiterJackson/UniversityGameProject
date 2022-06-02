#pragma once

#include "stdafx.h"
#include "../Headers/entity.h"
using namespace Entities;

Entity::Entity(const bool _have_ground) :
	Instance(), Movable(_have_ground), body()
{};
Entity::Entity(const sf::RectangleShape& Body, const bool _have_ground) :
	Instance(), Movable(_have_ground), body(Body)
{};
Entity::~Entity()
{};


DrawableEntity::DrawableEntity() :
	Entity(), Printable()
{};
DrawableEntity::DrawableEntity(const sf::Texture& texture, const bool FacesRight, const bool _have_ground) :
	Entity(_have_ground), Printable(texture, FacesRight)
{};
DrawableEntity::DrawableEntity(const std::string& fileName, const bool FacesRight, const bool _have_ground) :
	Entity(_have_ground), Printable(fileName, FacesRight)
{};
DrawableEntity::DrawableEntity(const sf::Texture& texture, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap,
	const bool FacesRight, const bool _have_ground) :
	Entity(_have_ground), Printable(texture, spriteMap, animationMap, FacesRight)
{};
DrawableEntity::DrawableEntity(const std::string& fileName, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap,
	const bool FacesRight, const bool _have_ground) :
	Entity(_have_ground), Printable(fileName, spriteMap, animationMap, FacesRight)
{};
DrawableEntity::DrawableEntity(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
	const bool FacesRight, const bool _have_ground) :
	Entity(_have_ground), Printable(texture, spriteMap, animationMap, FacesRight)
{};
DrawableEntity::DrawableEntity(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
	const bool FacesRight, const bool _have_ground) :
	Entity(_have_ground), Printable(fileName, spriteMap, animationMap, FacesRight)
{};
DrawableEntity::~DrawableEntity()
{};


LivingEntity::LivingEntity() :
	DrawableEntity(), life_count(0)
{};
LivingEntity::LivingEntity(const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false) :
	DrawableEntity(texture, FacesRight, _have_ground), life_count(_life_count)
{};
LivingEntity::LivingEntity(const std::string& fileName, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false) :
	DrawableEntity(fileName, FacesRight, _have_ground), life_count(_life_count)
{};
LivingEntity::LivingEntity(const sf::Texture& texture, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap,
	const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false) :
	DrawableEntity(texture, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count)
{};
LivingEntity::LivingEntity(const std::string& fileName, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap,
	const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false) :
	DrawableEntity(fileName, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count)
{};
LivingEntity::LivingEntity(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
	const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false) :
	DrawableEntity(texture, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count)
{};
LivingEntity::LivingEntity(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
	const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false) :
	DrawableEntity(fileName, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count)
{};
LivingEntity::~LivingEntity()
{};

void LivingEntity::Damaged()
{
	--this->life_count;
};