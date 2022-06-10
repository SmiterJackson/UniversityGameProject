#pragma once

#include "stdafx.h"

namespace traits
{
	class Animated
	{
	public:
		// Classe Adaptada da original, pelo canal Hilze Vonck 
		class Animation
		{
		public:
			class AnimaData
			{
			public:
				AnimaData();
				AnimaData(const unsigned int _start, const unsigned int _end, const unsigned int _row, const unsigned int _height,
					const unsigned int _width, const float _switchTime, const bool _repeatable = false);
				~AnimaData();

			public:
				unsigned int start, end, row, height, width;
				float switchTime;
				bool repeatable;
			};

			Animation();
			Animation(const AnimaData& Data);
			~Animation();

			void Initialize(const AnimaData& Data);
			void ResetAnimation();
			const sf::IntRect& update(float timeDiff, bool right = true);

			Animation operator= (const Animation& other)
			{
				if (&other != this)
				{
					this->img_token = other.img_token;
					this->start = other.start;
					this->end = other.end;
					this->row = other.row;
					this->current = other.current;
					this->time = other.time;
					this->switchTime = other.switchTime;
					this->repeatable = other.repeatable;
				}

				return *this;
			}
			const bool operator== (const Animation& other)
			{
				if (&other == this)
					return true;

				return false;
			}
			const bool operator!= (const Animation& other)
			{
				if (&other != this)
					return true;

				return false;
			}

		private:
			sf::IntRect img_token;
			unsigned int start, end, row, current;
			float time, switchTime;
			bool repeatable;
		};
		typedef std::vector<Animation::AnimaData> VecAnimaValues;

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
		void operator+= (const Animation::AnimaData& _animation)
		{
			this->animationVec.emplace_back(_animation);
		}

	protected:
		std::vector<Animation> animationVec;
		unsigned int next_ani, lastUsedAni;
		float elapsed_time;
	};
}

// DESCARTADO

/*
		class Slipery {
	public:
		Slipery(const float _coefficient = 1.0f);
		~Slipery();

		const float GetSliperyCoeffic() { return this->friction_coefficient; };
		void GetSliperyCoeffic(const float new_coefficient) { this->friction_coefficient = new_coefficient; };

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
*/