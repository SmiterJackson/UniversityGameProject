#pragma once

#include "../Headers/baseStage.h"

Stage::Stage() :
	Printable(), contextWindow(), heros(), obstacles(), collider()
{
	Initialize();
};
Stage::Stage(const std::string& fileName, sf::RenderWindow* contextWindow) :
	Printable(), contextWindow(), heros(), obstacles(), collider()
{
	Initialize();
};
Stage::~Stage()
{};


void Stage::Initialize()
{
	
};
void Stage::ReadArchive(const std::string& fileName)
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