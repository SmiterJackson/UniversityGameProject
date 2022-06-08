#include "../Headers/livingEntity.h"
using namespace entities;

LivingEntity::LivingEntity() :
	Entity(), Movable(), Alive()
{};
LivingEntity::LivingEntity(const sf::Texture& _texture, const sf::RectangleShape& _body, const unsigned int _life_count, const bool _have_ground, const float _weight_ceffic) :
	Entity(_texture, _body, _weight_ceffic), Movable(_have_ground), Alive(_life_count)
{};
LivingEntity::LivingEntity(const std::string _fileName, const sf::RectangleShape& _body, const unsigned int _life_count, const bool _have_ground, const float _weight_ceffic) :
	Entity(_fileName, _body, _weight_ceffic), Movable(_have_ground), Alive(_life_count)
{};
LivingEntity::~LivingEntity()
{};