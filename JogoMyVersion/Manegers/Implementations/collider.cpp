#include "../Manegers/Headers/collider.h"
using namespace collision;

Collidable::Collidable(sf::RectangleShape* _body = nullptr, bool* _haveGround = nullptr) :
	rect(_body), _haveGround(_haveGround)
{};
Collidable::~Collidable()
{};

CollisionManager::CollisionManager() :
	singleBody_entities(), multipleBodies_entities()
{};
CollisionManager::CollisionManager(const std::vector<drawable::SingleRectangleDrawable*>& _singleBody_entities, const std::vector<drawable::MultipleRectangleDrawable*>& _multipleBodies_entities) :
	singleBody_entities(_singleBody_entities), multipleBodies_entities(_multipleBodies_entities)
{};
CollisionManager::~CollisionManager()
{};

void CollisionManager::VerifyCollisions()
{

	
	
};

bool CollisionCheck(const sf::RectangleShape& obj_1, const sf::RectangleShape& obj_2)
{
	sf::Vector2f pos_1 = obj_1.getPosition(), pos_2 = obj_2.getPosition();
	sf::Vector2f radius_1 = obj_1.getSize() / 2.0f, radius_2 = obj_2.getSize() / 2.0f;
	sf::Vector2f delta_distance(abs(pos_1.x - pos_2.x), abs(pos_1.y - pos_2.y));


}