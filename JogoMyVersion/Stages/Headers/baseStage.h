#pragma once

#include "stdafx.h"
#include "../Lists/Headers/myList.h"
#include "../Entities/BaseEntities/Headers/entity.h"
using namespace entities;

// Para inicializar qualquer estrutura em vector, map ou list, utilize a função Initialize atravez do vector para todo item nele. 
class BaseStage  {
public:
	BaseStage();
	BaseStage(const std::string& fileName, sf::RenderWindow* contextWindow = nullptr);
	~BaseStage();

	void Initialize();
	void Execute(sf::Event& event);
	void ReadArchive(const std::string& fileName);
	void SelfPrintAll(sf::RenderWindow& window, float timeDiff);
	void SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff);

protected:
	sf::RenderWindow* contextWindow;
	
};