#pragma once

namespace traits
{
	class Movable
	{
	public:
		Movable(const bool _have_ground = false);
		~Movable();

		const float GetVerticalAcc() { return this->vertical_acc; };
		void SetVerticalACC(const float newVelocity) { this->vertical_acc = newVelocity; };

		const float GetHorizontalAcc() { return this->horizontal_acc; };
		void SetHorizontalACC(const float newVelocity) { this->horizontal_acc = newVelocity; };

		void SetHaveGround(const bool state) { this->have_ground = state; };
		void InvertHaveGround() { this->have_ground = !this->have_ground; };

		void SetWalkRight(const bool state) { this->walk_right = state; };
		void InvertWalkRight() { this->walk_right = !this->walk_right; };

		void SetWalkLeft(const bool state) { this->walk_left = state; };
		void InvertWalkLeft() { this->walk_left = !this->walk_left; };

		void SetJumping(const bool state) { this->jumping = state; };
		void InvertJumping() { this->jumping = !this->jumping; };

	public:
		static float global_gravity;

	protected:
		float horizontal_acc;
		float vertical_acc;
		bool have_ground, walk_right, walk_left, jumping;
	};
}