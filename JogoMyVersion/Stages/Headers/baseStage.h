#pragma once

#include "../Lists/Headers/myList.h"
#include "../Entities/Headers/entity.h"
#include "../Entities/Headers/instance.h"

class BaseStage : public Entities::DrawableEntity {
public:
	BaseStage(const sf::RenderWindow* contextWindow = nullptr);
	~BaseStage();

	void Execute(sf::Event& event);
	void SelfPrintAll(sf::RenderWindow& window, float timeDiff);
	void SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff);

protected:
	sf::RenderWindow* contextWindow;
	MyList<Entities::DrawableEntity> myEntities;
	std::vector<sf::RectangleShape> hitableBounds;
};
