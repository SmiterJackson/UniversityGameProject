#pragma once

#include "stdafx.h"
#include "instance.h"
#include "../Manegers/Headers/drawble.h"
#include "../Manegers/Headers/WithPhysics.h"
using namespace drawable;
using namespace WithPhysics;

namespace Entities
{
	// Estrutura base para uma entidade, cuja tem as variáveis para se movimentar, é uma instancia no no jogo, e contém um "corpo"
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
		virtual void Initialize() = 0;

	protected:
		sf::RectangleShape body;
	};

	// Herdando a Entidade base, essa se diferencia por ser desenhável
	class DrawableEntity : public Entity, public Drawable_Animated {
	public:
		DrawableEntity();
		DrawableEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const sf::RectangleShape& Body, const std::string& fileName, const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
						const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const sf::RectangleShape& Body, const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
						const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
						const bool FacesRight = true, const bool _have_ground = false);
		DrawableEntity(const sf::RectangleShape& Body, const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
						const bool FacesRight = true, const bool _have_ground = false);
		~DrawableEntity();

		const float GetElapsedTime() { return elapsed_time; };
		void SetElapsedTime(const float _elapsed_time) { this->elapsed_time = _elapsed_time; };

		// FUNCTIONS
		virtual void Execute() = 0;
		virtual void Initialize() = 0;
		virtual void SelfPrintAll(sf::RenderWindow& window) = 0;
		virtual void SelfPrintSelected(sf::RenderWindow& window) = 0;

	protected:
		unsigned int next_animation;
		float elapsed_time;
	};

	// Herdando a Entidade desenhável, essa contém variável e funções para controlar a vida de uma entidade "viva"
	class LivingEntity : public DrawableEntity
	{
	public:
		LivingEntity();
		LivingEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const sf::RectangleShape& Body, const std::string& fileName, const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
						const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const sf::RectangleShape& Body, const std::string& fileName, const VecOfPair_key_cutOfSprite& spriteMap, const VecOfPair_key_AnimationDataType& animationMap,
						const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
						const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		LivingEntity(const sf::RectangleShape& Body, const std::string& fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap, const std::unordered_map<unsigned int, Animation>& animationMap,
						const unsigned int _life_count, const bool FacesRight = true, const bool _have_ground = false);
		~LivingEntity();

		const unsigned int Getlife_count() { return this->life_count; };
		void Setlife_count(const unsigned int _life_count) { this->life_count = _life_count; };

		virtual void Damaged();
		virtual void Execute() = 0;
		virtual void Initialize() = 0;
		virtual void SelfPrintAll(sf::RenderWindow& window) = 0;
		virtual void SelfPrintSelected(sf::RenderWindow& window) = 0;

	protected:
		unsigned int life_count;
		bool alive;
	};
}
