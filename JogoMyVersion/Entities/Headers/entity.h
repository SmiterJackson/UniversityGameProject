#pragma once

#include "stdafx.h"
#include "instance.h"
#include "../Manegers/Headers/drawble.h"
#include "../Manegers/Headers/WithPhysics.h"
using namespace drawable;
using namespace WithPhysics;

namespace Entities
{
	// Estrutura base para uma entidade, cuja tem as vari�veis para se movimentar, � uma instancia no no jogo, e cont�m um "corpo"
	class Entity : public Instance, public Movable {
	public:
		Entity(const bool _have_ground = false);
		Entity(const sf::RectangleShape& Body, const bool _have_ground = false);
		~Entity();

		// SETS/ GETS
		sf::RectangleShape& GetRectShape() { return this->body; };
		const sf::RectangleShape& GetConstRectShape() { return this->body; };
		void SetEntityBody(const sf::RectangleShape& newPosition) { this->body = newPosition; };

		// FUNCTIONS
		virtual void Execute() = 0;

	protected:
		sf::RectangleShape body;
	};

	// Herdando a Entidade base, essa se diferencia por ser desenh�vel
	class DrawableEntity : public Entity, public Printable {
	public:
		DrawableEntity();
		DrawableEntity(const sf::Texture& texture, const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const std::string& fileName, const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const sf::Texture& texture, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap, 
						const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const std::string& fileName, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap,
						const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
						const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
						const bool FacesRight = true, const bool _have_ground = false);
		~DrawableEntity();

		// FUNCTIONS
		virtual void Execute() = 0;
		virtual void SelfPrintAll() = 0;
		virtual void SelfPrintSelected() = 0;
	};

	// Herdando a Entidade desenh�vel, essa cont�m vari�vel e fun��es para controlar a vida de uma entidade "viva"
	class LivingEntity : public DrawableEntity
	{
	public:
		LivingEntity();
		LivingEntity(const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const std::string& fileName, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const sf::Texture& texture, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap,
					const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const std::string& fileName, VecOfPair_key_cutOfSprite& spriteMap, VecOfPair_key_AnimationDataType& animationMap,
					const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
					const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
					const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		~LivingEntity();

		const unsigned int Getlife_count() { return this->life_count; };
		void Setlife_count(const unsigned int _life_count) { this->life_count = _life_count; };

		void Damaged();
		virtual void Execute() = 0;
		virtual void SelfPrintAll() = 0;
		virtual void SelfPrintSelected() = 0;

	protected:
		unsigned int life_count;
	};
}
