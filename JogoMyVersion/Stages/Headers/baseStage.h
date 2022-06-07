#pragma once

#include "../Entities/BaseEntities/Headers/entity.h"
#include "../Entities/Obstacles/Headers/obstacles.h"
#include "../Entities/Characters/Headers/Hero.h"
#include "../Manegers/Headers/collider.h"
#include "../Manegers/Headers/parallax.h"
using namespace entities;


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
	Stage(const sf::View& _view = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(400.0f, 400.0f)));
	Stage(const std::string& fileName, const sf::View& _view = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(400.0f, 400.0f)));
	~Stage();

	std::vector<BackGround>& GetView() { return this->views; };
	const std::vector<BackGround>& GetConstView() { return this->views; };
	void SetView(const std::vector<BackGround>& _views) { this->views = _views; };

	void Initialize();
	void Execute(float elapsedTime);
	void TreatInput(sf::RenderWindow& window);
	void SelfPrint(sf::RenderWindow& window);
	void ReadArchive(const std::string& fileName);

protected:
	std::vector<BackGround> views;
	std::vector<Hero> heros;
	std::vector<BaseObstacle*> obstacles;
	//std::vector<Projectile*> projectiles;

	Collider collider;
};