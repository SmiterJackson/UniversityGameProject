#pragma once

#include "stdafx.h"

namespace WithPhysics
{
	class Movable
	{
	public:
		Movable(const float _horizontal_acc = 0.0f, const float _vertical_acc = 0.0f, const bool _have_ground = false);
		~Movable();

		const float GetVerticalACC() { return this->vertical_acc; };
		void SetVerticalACC(const float newVelocity) { this->vertical_acc = newVelocity; };

		const float GetHorizontalACC() { return this->vertical_acc; };
		void SetHorizontalACC(const float newVelocity) { this->vertical_acc = newVelocity; };

		const bool GetHaveGround() { return this->have_ground; };
		void SetHaveGround(const bool state) { this->have_ground = state; };
		void InvertHaveGround() { this->have_ground = !this->have_ground; };

	public:
		static float global_gravity;

	protected:
		float horizontal_acc;
		float vertical_acc;
		bool have_ground;
	};

	class Slipery {
	public:
		Slipery(const float _coefficient = 1.0f);
		~Slipery();

		const float GetSliperyCoefficient() { return this->coefficient; };
		void GetSliperyCoefficient(const float new_coefficient) { this->coefficient = new_coefficient; };

	public:
		static float global_friction;

	protected:
		float coefficient;
	};
	// outros ...
}