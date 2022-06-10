#include "../Headers/collidable.h"
using namespace traits;

Collidable::Collidable(sf::RectangleShape& _body, const float _weight_ceffic) :
	rect(_body), weight_coeffic(std::min(std::max(_weight_ceffic, 0.0f), 1.0f))
{};
Collidable::~Collidable()
{};