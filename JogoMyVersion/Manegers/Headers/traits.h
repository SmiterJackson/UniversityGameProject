#pragma once

#include "animation.h"
/*#include "../Entities/Obstacles/Headers/obstacles.h"
using namespace obstacles;*/

namespace traits
{
	class Movable
	{
	public:
		Movable(const bool _have_ground = false, const float _horizontal_acc = 0.0f, const float _vertical_acc = 0.0f);
		~Movable();

		const float GetVerticalAcc() { return this->vertical_acc; };
		void SetVerticalACC(const float newVelocity) { this->vertical_acc = newVelocity; };

		const float GetHorizontalAcc() { return this->vertical_acc; };
		void SetHorizontalACC(const float newVelocity) { this->vertical_acc = newVelocity; };

		const bool GetHaveGround() { return this->have_ground; };
		void SetHaveGround(const bool state) { this->have_ground = state; };
		void InvertHaveGround() { this->have_ground = !this->have_ground; };

		const bool GetWalkRight() { return this->walk_right; };
		void SetWalkRight(const bool state) { this->walk_right = state; };
		void InvertWalkRight() { this->walk_right = !this->walk_right; };

		const bool GetWalkLeft() { return this->walk_left; };
		void SetWalkLeft(const bool state) { this->walk_left = state; };
		void InvertWalkLeft() { this->walk_left = !this->walk_left; };

		const bool GetJumping() { return this->jumping; };
		void SetJumping(const bool state) { this->jumping = state; };
		void InvertJumping() { this->jumping = !this->jumping; };

	public:
		static float global_gravity;

	protected:
		float horizontal_acc;
		float vertical_acc;
		bool have_ground, walk_right, walk_left, jumping;
	};

	class Slipery {
	public:
		Slipery(const float _coefficient = 1.0f);
		~Slipery();

		const float GetSliperyCoefficient() { return this->friction_coefficient; };
		void GetSliperyCoefficient(const float new_coefficient) { this->friction_coefficient = new_coefficient; };

	protected:
		float friction_coefficient;
	};

	class ForcesAtDirect
	{
	public:
		ForcesAtDirect(const float _surface_acceler = 0.0f, const bool dir_is_right = true);
		~ForcesAtDirect();

		const float GetSurfaceAcceleration() { return this->surface_acceler; };
		void SetSurfaceAcceleration(const float _surface_acceler) { this->surface_acceler = _surface_acceler; };

		void InvertDirection();

	protected:
		float surface_acceler;
		bool dir_is_right;
	};
	
	class Alive
	{
	public:
		Alive(const unsigned int life_count = 0);
		~Alive();

		const unsigned int& GetLifeCount() { return this->life_count; };
		void SetLifeCount(const unsigned int& _life_count) { this->life_count = _life_count; };

		const bool IsClassAlive() { return this->alive; };
		void InvertLifeState();

	protected:
		unsigned int life_count;
		bool alive;
	};

	class Printable
	{
	public:
		Printable();
		Printable(const sf::Texture& texture, const bool FacesRight = true);
		Printable(const std::string fileName, const bool FacesRight = true);
		~Printable();

		sf::Texture& GetTexture() { return this->texture; };
		const sf::Texture& GetConstTexture() { return this->texture; };
		void SetTexture(const sf::Texture& texture) { this->texture = texture; };
		void SetTexture(const std::string& fileName) { this->texture.loadFromFile(fileName); };

		void InvertTextureOrientation();

		virtual void SelfPrint(sf::RenderWindow& window) = 0;

	public:
		sf::Texture texture;
		bool faceRight;
	};

	class Collidable
	{
	public:
		Collidable(sf::RectangleShape& _body, const float _weight_ceffic = 0.0f);
		~Collidable();

		sf::RectangleShape& GetBodyRef() { return this->rect; };
		void SetBodyRef(const sf::RectangleShape& _body) { this->rect = _body; };

		const float& GetWeightCoefficient() { return this->weight_coeffic; };
		void SetWeightCoefficient(const float _weight_coeffic) { this->weight_coeffic = _weight_coeffic; };

		//bool CheckCollision(BaseObstacle& item_2);

	protected:
		sf::RectangleShape& rect;
		float weight_coeffic;
	};

	typedef std::vector<AnimaData> VecAnimaValues;
	class Animated
	{
	public:
		Animated();
		Animated(const std::vector<Animation>& _animationVec);
		Animated(const VecAnimaValues& _animationVec);
		~Animated();

		const std::vector<Animation>& GetConstAnimationVec() const { return this->animationVec; };
		void SetAnimationVec(const std::vector<Animation>& _animationVec) { this->animationVec = _animationVec; };

		const float GetElapsedTime() const { return elapsed_time; };
		void SetElapsedTime(const float _elapsed_time) { this->elapsed_time = _elapsed_time; };

		void operator+= (const std::vector<Animation>& _animationVec)
		{
			this->animationVec = _animationVec;
		}
		void operator+= (const VecAnimaValues& _animationVec)
		{
			size_t diff = this->animationVec.capacity() - this->animationVec.size();
			this->animationVec.reserve(diff + _animationVec.size());

			for (unsigned int i = 0; i < _animationVec.size(); ++i)
				this->animationVec.emplace_back(_animationVec[i]);
		}
		void operator+= (const AnimaData& _animation)
		{
			this->animationVec.emplace_back(_animation);
		}

	protected:
		std::vector<Animation> animationVec;
		unsigned int next_ani, lastUsedAni;
		float elapsed_time;
	};
}