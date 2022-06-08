#pragma once

#include "../Headers/baseStage.h"

#define FONT_REF "JogoMyVersion\\Resources\\fonts\\hf-free-complete\\equipment-pro-v1.1\\EquipmentPro.ttf"
#define TILE_SHEET "JogoMyVersion\\Resources\\images\\backgrounds\\Tiles\\IndustrialTile_sheet.png"
#define PLAYER1_SHEET "JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_green.png"

#define PLAYER_SIZE 48
#define TILE_SIZE 32
#define GRID_SIZE 32

Stage::Stage(sf::RenderWindow& _window) :
	Printable(), background(), heros(), obstacles(), collider()
{
    Initialize(_window);
};
Stage::Stage(sf::RenderWindow& _window, const std::string& stage_fileName, const std::string& texture_fileName) :
    Printable(texture_fileName), background(), heros(), obstacles(), collider()
{
	Initialize(_window);
};
Stage::~Stage()
{};


void Stage::Initialize(sf::RenderWindow& _window)
{
    unsigned int i = 0;
    acumuladorhorizontal = 0;
    sf::Vector2f windowSize(static_cast<sf::Vector2f>(_window.getSize()));

    this->texture.setRepeated(true);

    this->background.setTexture(this->texture);
    this->background.setPosition(sf::Vector2f(0.0f, 0.0f));
    this->background.setScale(2.4f, 2.4f);

    this->view.setSize(windowSize / 3.0f);
    this->view.setCenter(windowSize / 2.0f);
    //_window.setView(view);

    sf::RectangleShape rect(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
    sf::RectangleShape tiles_rect(sf::Vector2f(TILE_SIZE, TILE_SIZE));

    VecAnimaValues AnimationsConstructors = { {0, 4, 2, 45, 48, 0.20f, true},
                                              {0, 5, 1, 45, 48, 0.20f, true},
                                              {5, 7, 2, 45, 48, 0.05f},
                                              {6, 6, 1, 45, 48, 1.0f},
                                              {7, 7, 1, 45, 48, 1.0f},
                                              {0, 7, 0, 45, 48, 0.20f} };

    //Criando um hero
    this->heros.emplace_back(rect, PLAYER1_SHEET, AnimationsConstructors, 3, 0.0f, true);
    heros[0].GetBody().move(sf::Vector2f( 400 + PLAYER_SIZE, 100 + PLAYER_SIZE));

    //Criando blocos
    for (int i = 0; i < 8; i++)
        this->obstacles.push_back(static_cast<BaseObstacle*>(new StaticObstacle(tiles_rect, TILE_SHEET)));

    //Posicionando os blocos, e executando-os uma vez (atualiza valores internos)
    for (i = 0; i < obstacles.size(); ++i)
    {
        (*obstacles[i]).GetBody().move(sf::Vector2f(400.f + -(TILE_SIZE * 4) + (i * TILE_SIZE), 100.f + GRID_SIZE * 5));
        (*obstacles[i]).Execute();
    }

    // Joga o hero para dentro do colisor
    this->collider += static_cast<LivingEntity*>(&heros[0]);

    //Joga os obstaculos locais para dentro do colisor, para que tenha referencia de cada obstaculo
    for (i = 0; i < this->obstacles.size(); ++i)
        this->collider += this->obstacles[i];
};
void Stage::Execute(sf::RenderWindow& window, float elapsedTime)
{
	unsigned int i = 0;
    //sf::Vector2f viewPosOffSet(heros[0].GetBody().getOrigin().x - window.getSize().x / 2, heros[0].GetBody().getOrigin().y - window.getSize().y / 2);

    // Executar parâmetros e execuções de entidades
    for (i = 0; i < heros.size(); ++i)
    {
        heros[i].SetElapsedTime(elapsedTime);
        heros[i].Execute();
    }
    
    // Após atualizar entidades executar colisões
    collider.SetElapsedTime(elapsedTime);
    collider.UpdateCollisions();

    //if (viewPosOffSet.x > (window.getSize().x / 2))
       // viewPosOffSet.x = heros[0].GetBody().getOrigin().x;
    //else
       // viewPosOffSet.x = window.getSize().x / 2;

    //acumuladorhorizontal += 1;
    //this->background.setTextureRect(sf::IntRect(acumuladorhorizontal, 0, round(this->texture.getSize().x), round(this->texture.getSize().y)));
    //this->view.setCenter(heros[0].GetBody().getPosition());
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
    // Desenhar entidades após atualizações, e colisões
    unsigned int i = 0;

    window.draw(this->background);

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