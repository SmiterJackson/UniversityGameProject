#include "../Headers/obstacles.h"
using namespace obstacles;


BaseObstacle::BaseObstacle() :
	Entity(), textureCut()
{
	Initialize();
};
BaseObstacle::BaseObstacle(const std::string _fileName, const sf::RectangleShape& _body, const sf::IntRect& _textureCut, const float _weight_ceffic) :
	Entity(_fileName, _body, _weight_ceffic), textureCut(_textureCut)
{
	Initialize();
};
BaseObstacle::~BaseObstacle()
{};

void BaseObstacle::Initialize()
{
	this->body.setTexture(&this->texture);
	this->body.setTextureRect(this->textureCut);
};
void BaseObstacle::Execute()
{
	Initialize();
};
void BaseObstacle::SelfPrint(sf::RenderWindow& window)
{
	window.draw(this->body);
};