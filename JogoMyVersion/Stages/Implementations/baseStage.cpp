#pragma once

#include "../Headers/baseStage.h"

BaseStage::BaseStage()
	//DrawableEntity(), contextWindow(nullptr), myEntities(), hitableBounds()
{
	Initialize();
};
BaseStage::BaseStage(const std::string& fileName, sf::RenderWindow* contextWindow)
	//DrawableEntity(), contextWindow(contextWindow), myEntities(), hitableBounds()
{
	Initialize();
};
BaseStage::~BaseStage()
{};


void BaseStage::Initialize()
{
	
};
void BaseStage::Execute(sf::Event& event)
{
	
};
void BaseStage::SelfPrintAll(sf::RenderWindow& window, float timeDiff)
{
	
};
void BaseStage::SelfPrintSelected(sf::RenderWindow& window, unsigned int animationKey, float timeDiff)
{
	
};
void BaseStage::ReadArchive(const std::string& fileName)
{
	std::ifstream inStream(fileName, std::ifstream::in | std::ifstream::binary);
	if (inStream.is_open())
	{
		std::cerr << "Não foi possível abrir o arquivo para inicializar a fase." << std::endl;
		return;
	}

	// formatar um meio para ler um arquivo e inicializar a fase

	inStream.close();
};