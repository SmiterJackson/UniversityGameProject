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
	Entity(), Drawable_Animated(), next_animation(0), elapsed_time(0.0f)
{};
DrawableEntity::DrawableEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const bool FacesRight, const bool _have_ground) :
	Entity(Body, _have_ground), Drawable_Animated(texture, FacesRight), next_animation(0), elapsed_time(0.0f)
{};
DrawableEntity::DrawableEntity(const sf::RectangleShape& Body, const std::string& fileName, const bool FacesRight, const bool _have_ground) :
	Entity(Body, _have_ground), Drawable_Animated(fileName, FacesRight), next_animation(0), elapsed_time(0.0f)
{};
DrawableEntity::DrawableEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap,
	const VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight, const bool _have_ground) :
	Entity(Body, _have_ground), Drawable_Animated(texture, spriteMap, animationMap, FacesRight), next_animation(0), elapsed_time(0.0f)
{};
DrawableEntity::DrawableEntity(const sf::RectangleShape& Body, const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap,
	const VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight, const bool _have_ground) :
	Entity(Body, _have_ground), Drawable_Animated(fileName, spriteMap, animationMap, FacesRight), next_animation(0), elapsed_time(0.0f)
{};
DrawableEntity::DrawableEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap,
	const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight, const bool _have_ground) :
	Entity(Body, _have_ground), Drawable_Animated(texture, spriteMap, animationMap, FacesRight), next_animation(0), elapsed_time(0.0f)
{};
DrawableEntity::DrawableEntity(const sf::RectangleShape& Body, const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap,
	const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight, const bool _have_ground) :
	Entity(Body, _have_ground), Drawable_Animated(fileName, spriteMap, animationMap, FacesRight), next_animation(0), elapsed_time(0.0f)
{};
DrawableEntity::~DrawableEntity()
{};


LivingEntity::LivingEntity() :
	DrawableEntity(), life_count(0), alive(true)
{};
LivingEntity::LivingEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	DrawableEntity(Body, texture, FacesRight, _have_ground), life_count(_life_count), alive(true)
{};
LivingEntity::LivingEntity(const sf::RectangleShape& Body, const std::string& fileName, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	DrawableEntity(Body, fileName, FacesRight, _have_ground), life_count(_life_count), alive(true)
{};
LivingEntity::LivingEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
	const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	DrawableEntity(Body, texture, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count), alive(true)
{};
LivingEntity::LivingEntity(const sf::RectangleShape& Body, const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
	const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	DrawableEntity(Body, fileName, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count), alive(true)
{};
LivingEntity::LivingEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap,
	const std::unordered_map<unsigned int, Animation>& animationMap, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	DrawableEntity(Body, texture, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count), alive(true)
{};
LivingEntity::LivingEntity(const sf::RectangleShape& Body, const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap,
	const std::unordered_map<unsigned int, Animation>& animationMap, const unsigned int _life_count, const bool FacesRight, const bool _have_ground) :
	DrawableEntity(Body, fileName, spriteMap, animationMap, FacesRight, _have_ground), life_count(_life_count), alive(true)
{};
LivingEntity::~LivingEntity()
{};

void LivingEntity::Damaged()
{
	--(this->life_count);
};