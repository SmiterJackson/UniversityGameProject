#include "../Headers/heroProjectile.h"
using namespace projectiles;

#define BULET_REF std::string("JogoMyVersion\\Resources\\images\\sprites\\Characters\\TeamGunner_By_SecretHideout_060519\\EXTRAS\\SpongeBullet.png")
#define BULET_SPEED 0.4f

HeroProjectile::HeroProjectile(sf::Vector2f position, bool _direction) :
	Entity(BULET_REF, sf::RectangleShape(sf::Vector2f(3.f, 1.f)), 0.0f), Movable(true), origin(position)
{
	this->faceRight = _direction;
	Initialize();
};
HeroProjectile::~HeroProjectile()
{};

void HeroProjectile::Initialize()
{
	this->body.setTexture(&this->texture);
	this->body.setPosition(this->origin.x, this->origin.y + 4);

	if (!this->faceRight)
		this->body.scale(-1.0f, 1.0f);
};
void HeroProjectile::Execute()
{
	this->body.setTexture(&this->texture);
	if(this->faceRight)
		this->body.move(BULET_SPEED, 0.f);
	else
		this->body.move(-BULET_SPEED, 0.f);
};
void HeroProjectile::SelfPrint(sf::RenderWindow& window)
{
	window.draw(this->body);
};