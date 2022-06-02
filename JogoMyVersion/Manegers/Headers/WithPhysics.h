#pragma once

#include "stdafx.h"

namespace WithPhysics
{
	class Movable
	{
	public:
		Movable(const float _horizontal_acc = 0.0f, const float _vertical_acc = 0.0f);
		~Movable();

		const float GetVerticalACC() { return this->vertical_acc; };
		void SetVerticalACC(const float newVelocity) { this->vertical_acc = newVelocity; };
		const float GetHorizontalACC() { return this->vertical_acc; };
		void SetHorizontalACC(const float newVelocity) { this->vertical_acc = newVelocity; };

		static float global_gravity;
	protected:
		float horizontal_acc;
		float vertical_acc;
	};

	// outros ...
}