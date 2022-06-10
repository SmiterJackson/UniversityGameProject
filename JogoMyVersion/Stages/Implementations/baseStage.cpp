#pragma once

#include "../Headers/baseStage.h"

#define FONT_REF "JogoMyVersion\\Resources\\fonts\\hf-free-complete\\equipment-pro-v1.1\\EquipmentPro.ttf"
#define TILE_SHEET "JogoMyVersion\\Resources\\images\\backgrounds\\Tiles\\IndustrialTile_sheet.png"
#define PLAYER1_SHEET "JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_green.png"
#define PLAYER2_SHEET "JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_black.png"
#define PLAYER3_SHEET "JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_red.png"
#define PLAYER4_SHEET "JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_yellow.png"

#define PLAYER_SIZE 48
#define TILE_SIZE 32
#define GRID_SIZE 32

Stage::Stage(sf::RenderWindow& _window) :
	Printable(), background(), heros(), obstacles(), collider()
{
    Initialize(_window);
};
Stage::Stage(sf::RenderWindow& _window, const std::string& stage_fileName, const std::string& texture_fileName) :
    Printable(texture_fileName), background(), heros(), obstacles(), collider(Collider::MapBounds(0, 0, this->texture.getSize().x * 2.4f, this->texture.getSize().y * 2.4f - 68))
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
    this->background.setPosition(sf::Vector2f(0.0f, 0.0f));
    this->background.setTexture(this->texture, false);
    this->background.setScale(2.4f, 2.4f);

    sf::RectangleShape rect(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
    sf::RectangleShape tiles_rect(sf::Vector2f(TILE_SIZE, TILE_SIZE));

    VecAnimaValues AnimationsConstructors = { {0, 4, 2, 45, 48, 0.20f, true},
                                              {0, 5, 1, 45, 48, 0.20f, true},
                                              {5, 7, 2, 45, 48, 0.05f},
                                              {6, 6, 1, 45, 48, 1.0f},
                                              {7, 7, 1, 45, 48, 1.0f},
                                              {0, 7, 0, 45, 48, 0.20f} };

    //Criando um hero
    this->heros += new Hero(windowSize, sf::Vector2f(background.getGlobalBounds().width, background.getGlobalBounds().height),
                            PLAYER1_SHEET, rect, AnimationsConstructors, 3, true, 0.0f);
    heros[0]->GetBody().move(sf::Vector2f( 400 + PLAYER_SIZE, 100 + PLAYER_SIZE));

    /*this->heros += new Hero(windowSize, sf::Vector2f(background.getGlobalBounds().width, background.getGlobalBounds().height),
                            PLAYER2_SHEET, rect, AnimationsConstructors, 3, true, 0.0f);
    heros[1]->GetBody().move(sf::Vector2f(450 + PLAYER_SIZE, 100 + PLAYER_SIZE));*/

    if(heros.GetSize() >= 2)
    {
        for (i = 0; i < heros.GetSize(); ++i)
            heros[i]->UpdatePlayerPerspective(static_cast<sf::Vector2f>(_window.getSize()));
    }

    //Criando blocos
    for (int i = 0; i < 10; i++)
        this->obstacles += new BaseObstacle(TILE_SHEET, tiles_rect, sf::IntRect(2 * 32, 0, 32, 32));

    // Posicionando as plaaformas
    for (i = 0; i < this->obstacles.GetSize(); ++i)
        obstacles[i]->GetBody().move(sf::Vector2f(400.f + -(TILE_SIZE * 4) + (i * TILE_SIZE), 100.f + GRID_SIZE * 5));

    // Joga o hero para dentro do colisor
    for(i = 0; i < this->heros.GetSize(); ++i)
    this->collider += static_cast<LivingEntity*>(heros[i]);

    //Joga os obstaculos locais para dentro do colisor, para que tenha referencia de cada obstaculo
    for (i = 0; i < this->obstacles.GetSize(); ++i)
        this->collider += this->obstacles[i];
};
void Stage::Execute(sf::RenderWindow& window, float elapsedTime)
{
    TreatInput(window);
    UpdateEntities(window, elapsedTime);
    SelfPrint(window);
};
void Stage::UpdateEntities(sf::RenderWindow& window, float elapsedTime)
{
    unsigned int i = 0;

    for (i = 0; i < heros.GetSize(); ++i)
    {
        heros[i]->SetElapsedTime(elapsedTime);
        heros[i]->Execute();
        if (heros[i]->GetIfAttacked())
            this->projectiles.Push_back(*heros[i]->Attack());
    }

    for (i = 0; i < this->projectiles.GetSize(); ++i)
        projectiles[i].Execute();

    collider.UpdateCollisions(elapsedTime);
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
            for (i = 0; i < this->heros.GetSize(); ++i)
                this->heros[i]->PlayerInputHandler(event);
            break;
        case sf::Event::KeyReleased:
            for (i = 0; i < this->heros.GetSize(); ++i)
                this->heros[i]->PlayerInputHandler(event);
            break;
        case sf::Event::MouseButtonPressed:
            //std::cout << "Foi tocado um botao do mouse!" << std::endl;
            break;
        case sf::Event::MouseButtonReleased:
            //std::cout << "Foi solto um botao do mouse!" << std::endl;
            break;
        default:
            break;
        }
    }
};
void Stage::SelfPrint(sf::RenderWindow& window)
{
    // Desenhar entidades após atualizações, e colisões
    unsigned int i = 0, j = 0;

    for (i = 0; i < heros.GetSize(); ++i)
    {
        // Defini a 'view' (perpectiva) do jogador x cuja tela será preenchida
        window.setView(heros[i]->GetView());

        // PS: desenhar a tela de fundo antes dos players
        window.draw(this->background);

        // Desenhar os jogadores antes do jogardor atual
        for(j = 0; j < i; ++j)
            heros[j]->SelfPrint(window);

        // Desenhar os jogadores depois do jogardor atual
        for (j = i + 1; j < this->heros.GetSize(); ++j)
            heros[j]->SelfPrint(window);

        heros[i]->SelfPrint(window);

        for (j = 0; j < this->projectiles.GetSize(); ++j)
            projectiles[j].SelfPrint(window);

        for (j = 0; j < this->obstacles.GetSize(); ++j)
            obstacles[j]->SelfPrint(window);

    #ifdef _DEBUG
        for (j = 0; j < obstacles.GetSize(); ++j)
        {
            obstacles[j]->stringInfoUptade();
            obstacles[j]->PrintInfo(window);
        }
        for (j = 0; j < heros.GetSize(); ++j)
        {
            heros[j]->stringInfoUptade();
            heros[j]->PrintInfo(window);
        }
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