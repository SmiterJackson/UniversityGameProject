#include "../Entities/Obstacles/Headers/Obstacles.h"
using namespace obstacles;

BaseObstacle::BaseObstacle() :
	BaseEntity(), SingleRectangleDrawable()
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const bool FacesRight) :
	BaseEntity(), SingleRectangleDrawable(body, texture, FacesRight)
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const bool FacesRight) :
	BaseEntity(), SingleRectangleDrawable(body, texture_fileName, FacesRight)
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const VecAnimaValues& _animationMap, const bool FacesRight) :
	BaseEntity(), SingleRectangleDrawable(body, texture, _animationMap, FacesRight)
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const VecAnimaValues& _animationMap, const bool FacesRight) :
	BaseEntity(), SingleRectangleDrawable(body, texture_fileName, _animationMap, FacesRight)
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const std::vector<Animation>& _animationMap, const bool FacesRight) :
	BaseEntity(), SingleRectangleDrawable(body, texture, _animationMap, FacesRight)
{};
BaseObstacle::BaseObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const std::vector<Animation>& _animationMap, const bool FacesRight) :
	BaseEntity(), SingleRectangleDrawable(body, texture_fileName, _animationMap, FacesRight)
{};
BaseObstacle::~BaseObstacle()
{};


StaticObstacle::StaticObstacle(const float _surface_acceler, const bool dir_is_right, const float _coefficient) :
	BaseObstacle(), Slipery(_coefficient), ForcesAtDirect(_surface_acceler, dir_is_right)
{
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const sf::IntRect& textureCut, const bool FacesRight,
								const float _surface_acceler, const bool dir_is_right, const float _coefficient) :
	BaseObstacle(body, texture, FacesRight), Slipery(_coefficient), ForcesAtDirect(_surface_acceler, dir_is_right)
{
	this->body.setTextureRect(textureCut);
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const sf::IntRect& textureCut, const bool FacesRight,
								const float _surface_acceler, const bool dir_is_right, const float _coefficient) :
	BaseObstacle(body, texture_fileName, FacesRight), Slipery(_coefficient), ForcesAtDirect(_surface_acceler, dir_is_right)
{
	this->body.setTextureRect(textureCut);
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const VecAnimaValues& _animationMap, const sf::IntRect& textureCut,
								const bool FacesRight, const float _surface_acceler, const bool dir_is_right, const float _coefficient) :
	BaseObstacle(body, texture, _animationMap, FacesRight), Slipery(_coefficient), ForcesAtDirect(_surface_acceler, dir_is_right)
{
	this->body.setTextureRect(textureCut);
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const VecAnimaValues& _animationMap, const sf::IntRect& textureCut,
								const bool FacesRight, const float _surface_acceler, const bool dir_is_right, const float _coefficient) :
	BaseObstacle(body, texture_fileName, _animationMap, FacesRight), Slipery(_coefficient), ForcesAtDirect(_surface_acceler, dir_is_right)
{
	this->body.setTextureRect(textureCut);
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& body, const sf::Texture& texture, const std::vector<Animation>& _animationMap, const sf::IntRect& textureCut,
								const bool FacesRight, const float _surface_acceler, const bool dir_is_right, const float _coefficient) :
	BaseObstacle(body, texture, _animationMap, FacesRight), Slipery(_coefficient), ForcesAtDirect(_surface_acceler, dir_is_right)
{
	this->body.setTextureRect(textureCut);
	Initialize();
};
StaticObstacle::StaticObstacle(const sf::RectangleShape& body, const std::string texture_fileName, const std::vector<Animation>& _animationMap, const sf::IntRect& textureCut,
								const bool FacesRight, const float _surface_acceler, const bool dir_is_right, const float _coefficient) :
	BaseObstacle(body, texture_fileName, _animationMap, FacesRight), Slipery(_coefficient), ForcesAtDirect(_surface_acceler, dir_is_right)
{
	this->body.setTextureRect(textureCut);
	Initialize();
};
StaticObstacle::~StaticObstacle()
{};

void StaticObstacle::Initialize()
{
	this->body.setTexture(&this->texture);
};
void StaticObstacle::Execute()
{
	this->body.setTexture(&this->texture);
};
void StaticObstacle::SelfPrint(sf::RenderWindow& window)
{
	window.draw(this->body);
};


/*Obstacle::Obstacle() :
	DrawableEntity()
{};
Obstacle::Obstacle(const sf::RectangleShape& Body, const sf::Texture& texture, const bool FacesRight) :
	DrawableEntity(Body, texture, FacesRight)
{};
Obstacle::Obstacle(const sf::RectangleShape& Body, const std::string& texture_fileName, const bool FacesRight) :
	DrawableEntity(Body, texture_fileName, FacesRight)
{};
Obstacle::Obstacle(const sf::RectangleShape& Body, const sf::Texture& texture, const VecOfPair_key_cutOfSprite& spriteMap,
	const VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight) :
	DrawableEntity(Body, texture, spriteMap, animationMap, FacesRight)
{};
Obstacle::Obstacle(const sf::RectangleShape& Body, const std::string& texture_fileName, const VecOfPair_key_cutOfSprite& spriteMap,
	const VecOfPair_key_AnimationDataType& animationMap, const bool FacesRight) :
	DrawableEntity(Body, texture_fileName, spriteMap, animationMap, FacesRight)
{};
Obstacle::Obstacle(const sf::RectangleShape& Body, const sf::Texture& texture, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap,
	const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight) :
	DrawableEntity(Body, texture, spriteMap, animationMap, FacesRight)
{};
Obstacle::Obstacle(const sf::RectangleShape& Body, const std::string& texture_fileName, const std::unordered_map<unsigned int, sf::Sprite>& spriteMap,
	const std::unordered_map<unsigned int, Animation>& animationMap, const bool FacesRight) :
	DrawableEntity(Body, texture_fileName, spriteMap, animationMap, FacesRight)
{};
Obstacle::~Obstacle()
{};*/