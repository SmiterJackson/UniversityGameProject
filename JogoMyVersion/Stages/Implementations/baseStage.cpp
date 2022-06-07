#pragma once

#include "../Headers/baseStage.h"

#define PLAYER1_SHEET std::string("JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_green.png")
#define TILE_SHEET std::string("JogoMyVersion\\Resources\\images\\backgrounds\\Tiles\\IndustrialTile_sheet.png")
#define BACKGROUND_SHEET std::string("JogoMyVersion\\Resources\\images\\backgrounds\\Background\\background_sheet.png")
#define FONT_REF std::string("JogoMyVersion\\Resources\\fonts\\hf-free-complete\\equipment-pro-v1.1\\EquipmentPro.ttf")
#define PLAYER_SIZE 48
#define TILE_SIZE 32
#define GRID_SIZE 32
#define FATOR_TAMANHO 2.0f
#define FATOR_TAMANHO_backgroung 3.0f

Stage::Stage(const sf::View& _view) :
	Printable(), view(_view), heros(), obstacles(), collider()
{
    Initialize();
};
Stage::Stage(const std::string& fileName, const sf::View& _view) :
    Printable(fileName), view(_view), heros(), obstacles(), collider()
{
	Initialize();
};
Stage::~Stage()
{};


void Stage::Initialize()
{
    unsigned int i = 0;

    sf::RectangleShape rect(sf::Vector2f(PLAYER_SIZE * FATOR_TAMANHO, PLAYER_SIZE * FATOR_TAMANHO));
    sf::RectangleShape tiles_rect(sf::Vector2f(TILE_SIZE * FATOR_TAMANHO, TILE_SIZE * FATOR_TAMANHO));

    VecAnimaValues AnimationsConstructors = { {0, 4, 2, 45, 48, 0.20f, true},
                                              {0, 5, 1, 45, 48, 0.20f, true},
                                              {5, 7, 2, 45, 48, 0.05f},
                                              {6, 7, 1, 45, 48, 0.20f},
                                              {0, 7, 0, 45, 48, 0.20f} };

    this->heros.emplace_back(rect, PLAYER1_SHEET, AnimationsConstructors, 3, 0.0f, true);
    heros[0].GetBody().move(sf::Vector2f(0.0f, -PLAYER_SIZE * FATOR_TAMANHO));

    this->obstacles = { static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)), 
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)),
                        static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET))};

    for (i = 0; i < obstacles.size(); ++i)
    {
        (*obstacles[i]).GetBody().move(sf::Vector2f((-TILE_SIZE * FATOR_TAMANHO * 5) + (i * TILE_SIZE * FATOR_TAMANHO), GRID_SIZE * 6));
        (*obstacles[i]).Execute();
    }

    /*std::vector<StaticObstacle*> obstacles_p;
    std::vector<BaseObstacle*> baseobstacles_p;

    for (i = 0; i < obstacles.size(); ++i)
        obstacles_p.emplace_back(&obstacles[i]);

    for (i = 0; i < obstacles_p.size(); ++i)
        baseobstacles_p.push_back(static_cast<BaseObstacle*>(obstacles_p[i]));

    for (i = 0; i < obstacles_p.size(); ++i)
        this->collider += baseobstacles_p[i];*/

    for (i = 0; i < this->obstacles.size(); ++i)
        this->collider += this->obstacles[i];

    this->collider += static_cast<LivingEntity*>(&heros[0]);
};
void Stage::Execute(float elapsedTime)
{
	unsigned int i = 0;

    // Executar parâmetros e execuções de entidades
    for (i = 0; i < heros.size(); ++i)
    {
        heros[i].SetElapsedTime(elapsedTime);
        heros[i].Execute();
    }
    
    // Após atualizar entidades executar colisões
    collider.SetElapsedTime(elapsedTime);
    collider.UpdateCollisions();

    this->view.setCenter(heros[0].GetBody().getPosition());
};
void Stage::TreatInput(sf::RenderWindow& window)
{
    unsigned int i = 0;
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::LostFocus:
            // PAUSE O JOGO
            break;
        case sf::Event::Resized:
            // Redimensionar as views
            break;
        case sf::Event::KeyPressed:
            for (i = 0; i < this->heros.size(); ++i)
                this->heros[i].PlayerInputHandler(event);
            break;
        case sf::Event::KeyReleased:
            for (i = 0; i < this->heros.size(); ++i)
                this->heros[i].PlayerInputHandler(event);
            break;
        case sf::Event::MouseButtonPressed:
            std::cout << "Foi tocado um botao do mouse!" << std::endl;
            break;
        case sf::Event::MouseButtonReleased:
            std::cout << "Foi solto um botao do mouse!" << std::endl;
            break;
        default:
            break;
        }
    }
};
void Stage::SelfPrint(sf::RenderWindow& window)
{
    unsigned int i = 0;
    sf::Sprite body(this->texture);
    body.setOrigin(body.getGlobalBounds().width / 2.0f, body.getGlobalBounds().height / 2.0f);
    body.setPosition(0.0f, 0.0f);
    body.setScale(FATOR_TAMANHO_backgroung, FATOR_TAMANHO_backgroung);
    body.move(0.0f, heros[0].GetBody().getPosition().y);
    // Desenhar entidades após atualizações, e colisões
    window.draw(body);

    for (i = 0; i < obstacles.size(); ++i)
        (*obstacles[i]).SelfPrint(window);

    for (i = 0; i < heros.size(); ++i)
        heros[i].SelfPrint(window);

    for (i = 0; i < obstacles.size(); ++i)
    {
    #ifdef _DEBUG
        (*obstacles[i]).stringInfoUptade();
        (*obstacles[i]).PrintInfo(window);
    #endif
    }

    for (i = 0; i < heros.size(); ++i)
    {
    #ifdef _DEBUG
        heros[i].stringInfoUptade();
        heros[i].PrintInfo(window);
    #endif
    }
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