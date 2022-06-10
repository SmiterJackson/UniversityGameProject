#include "../Headers/movable.h"
using namespace traits;

float Movable::global_gravity = 1.0f;

Movable::Movable(const bool _have_ground) :
	horizontal_acc(0.0f), vertical_acc(0.0f), have_ground(_have_ground), walk_right(false), walk_left(false), jumping(false)
{};
Movable::~Movable()
{};