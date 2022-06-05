#include "../Entities/Obstacles/Headers/Obstacles.h"
using namespace obstacles;


BaseObstacle::BaseObstacle() :
	CollidableEntity(), Printable()
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& _body, const sf::Texture& texture, const float _weight_ceffic, const bool FacesRight) :
	CollidableEntity(_body, _weight_ceffic), Printable(texture, FacesRight)
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& _body, const std::string fileName, const float _weight_ceffic, const bool FacesRight) :
	CollidableEntity(_body, _weight_ceffic), Printable(fileName, FacesRight)
{};
BaseObstacle::~BaseObstacle()
{};


StaticObstacle::StaticObstacle() :
	BaseObstacle()
{
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& _body, const sf::Texture& texture, const float _weight_ceffic, const bool FacesRight) :
	BaseObstacle(_body, texture, _weight_ceffic, FacesRight)
{
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& _body, const std::string fileName, const float _weight_ceffic, const bool FacesRight) :
	BaseObstacle(_body, fileName, _weight_ceffic, FacesRight)
{
	Initialize();
};
StaticObstacle::~StaticObstacle()
{};

void StaticObstacle::Initialize()
{
	this->body.setTexture(&this->texture);
	this->body.setTextureRect(sf::IntRect(2 * 32, 0, 32, 32));
};
void StaticObstacle::Execute()
{
	this->body.setTexture(&this->texture);
};
void StaticObstacle::SelfPrint(sf::RenderWindow& window)
{
	window.draw(this->body);
};