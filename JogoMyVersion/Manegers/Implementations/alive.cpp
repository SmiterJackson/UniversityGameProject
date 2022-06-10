#include "../Headers/alive.h"
using namespace traits;

Alive::Alive(const unsigned int _life_count) :
	life_count(_life_count), alive(true)
{};
Alive::~Alive()
{};

void Alive::InvertLifeState()
{
	this->alive = !this->alive;
};