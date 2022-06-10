#pragma once

#include "../Entities/Projectiles/Headers/heroProjectile.h"
#include "../Entities/Obstacles/Headers/obstacles.h"
#include "../Entities/Characters/Headers/Hero.h"
#include "../Manegers/Headers/collider.h"
#include "../Lists//Headers/myList.h"
using namespace projectiles;

namespace std
{
	template<typename _type1, typename _type2, typename _type3>
	class trio
	{
	public:
		trio(const _type1& _type1_value = _type1(), const _type2& _type2_value = _type2(), const _type3& _type3_value = _type3()) :
			first(_type1_value), second(_type2_value), third(_type3_value)
		{};
		~trio()
		{};

		_type1 first;
		_type2 second;
		_type3 third;
	};
}

class Stage : public Printable
{
public:
	Stage(sf::RenderWindow& window);
	Stage(sf::RenderWindow& window, const std::string& stage_fileName, const std::string& texture_fileName);
	~Stage();

	sf::View& GetView() { return this->view; };
	const sf::View& GetConstView() { return this->view; };
	void SetView(sf::View& _view) { this->view = _view; };

	void Initialize(sf::RenderWindow& _window);
	void Execute(sf::RenderWindow& window, float elapsedTime);
	void UpdateEntities(sf::RenderWindow& window, float elapsedTime);
	void TreatInput(sf::RenderWindow& window);
	void SelfPrint(sf::RenderWindow& window);
	void ReadArchive(const std::string& fileName);

protected:
	sf::View view;
	sf::Sprite background;
	MyList<Hero*> heros;
	MyList<BaseObstacle*> obstacles;
	MyList<HeroProjectile> projectiles;


	int acumuladorhorizontal;
	Collider collider;
};