#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
#include "../Entities/Obstacles/Headers/obstacles.h"
#include "../Entities/Characters/Headers/Hero.h"
#include "../Manegers/Headers/collider.h"
using namespace entities;


class Stage : public Printable
{
public:
	Stage();
	Stage(const std::string& fileName, sf::RenderWindow* contextWindow = nullptr);
	~Stage();

	void Execute();
	void SelfPrint();
	void Initialize();
	void TreatInput(sf::Event event);
	void ReadArchive(const std::string& fileName);

protected:
	sf::RenderWindow* contextWindow;
	std::vector<Hero> heros;
	std::vector<BaseObstacle> obstacles;
	//std::vector<Projectile*> projectiles;

	Collider collider;
};