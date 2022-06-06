#pragma once

#include "Entities/Characters/Headers/Hero.h"
#include "Entities/Obstacles/Headers/obstacles.h"
#include "Manegers/Headers/collider.h"
#include "Manegers/Headers/parallax.h"
using namespace obstacles;

#define PLAYER1_SHEET std::string("JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_green.png")
#define TILE_SHEET std::string("JogoMyVersion\\Resources\\images\\backgrounds\\Tiles\\IndustrialTile_sheet.png")
#define BACKGROUND_SHEET std::string("JogoMyVersion\\Resources\\images\\backgrounds\\Background\\background_sheet.png") 
#define FONT_REF std::string("JogoMyVersion\\Resources\\fonts\\hf-free-complete\\equipment-pro-v1.1\\EquipmentPro.ttf")
#define PLAYER_SIZE 48
#define TILE_SIZE 32

// Por algum motivo desconhecido a estrutura vector está constantemente desconectando o ponteira da estrutura base drawable dos objetos
int main()
{
    sf::RenderWindow window(sf::VideoMode(1536, 864), "Janela do Jogo");
    sf::View Myview(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1400.0f, 850.0f));
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    float fator = 3.5f;
    float timediff = 0.0f;
    int animacao = 0, i = 0;
    bool direita = true;

    sf::Texture texture;
    texture.loadFromFile(PLAYER1_SHEET);

    sf::RectangleShape rect(sf::Vector2f(PLAYER_SIZE * fator, PLAYER_SIZE * fator));
    sf::RectangleShape tiles_rect(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator));    
    VecAnimaValues AnimationsConstructors =  {{0, 4, 2, 45, 48, 0.20f, true},
                                              {0, 5, 1, 45, 48, 0.20f, true},
                                              {5, 7, 2, 45, 48, 0.05f},
                                              {6, 7, 1, 45, 48, 0.20f},
                                              {0, 7, 0, 45, 48, 0.20f}};
    
    Hero hero(rect, PLAYER1_SHEET, AnimationsConstructors, 3, 0.0f, true);
    hero.GetBody().move(sf::Vector2f(0.0f, -PLAYER_SIZE * fator));

    std::vector<StaticObstacle> obs = {{tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET},
                                       {tiles_rect, TILE_SHEET}};

    for (i = 0; i < obs.size(); ++i)
    {
        obs[i].GetBody().move(sf::Vector2f((-TILE_SIZE * fator * 5) + (i * TILE_SIZE * fator), 200.0f));
        obs[i].Execute();
    }

    Hero* hero_p = &hero;
    std::vector<StaticObstacle*> obstacles_p;
    std::vector<BaseObstacle*> baseobstacles_p;

    for (i = 0; i < obs.size(); ++i)
        obstacles_p.emplace_back(&obs[i]);

    for (i = 0; i < obstacles_p.size(); ++i)
        baseobstacles_p.push_back(static_cast<BaseObstacle*>(obstacles_p[i]));

    Collider maneger;

    for (i = 0; i < obstacles_p.size(); ++i)
        maneger += baseobstacles_p[i];
    
    maneger += static_cast<LivingEntity*>(&hero);

    sf::Clock clock;
    while(window.isOpen())
    {
        timediff = clock.restart().asSeconds();

        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::LostFocus:
                std::cout << "Perdeu o foco !" << std::endl;
                break;
            case sf::Event::GainedFocus:
                std::cout << "Ganhou o foco !" << std::endl;
                break;
            case sf::Event::Resized:
                std::cout << "Redimensionado !" << std::endl;
                break;
            case sf::Event::KeyPressed:
                std::cout << "Foi apertado um botao do teclado!" << std::endl;
                switch (event.key.code)
                {
                case sf::Keyboard::A:
                    hero.InvertWalkLeft();
                    break;
                case sf::Keyboard::D:
                    hero.InvertWalkRight();
                    break;
                case sf::Keyboard::S:
                    hero.InvertCrouching();
                    break;
                case sf::Keyboard::W:
                    hero.InvertJumping();
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::KeyReleased:
                std::cout << "Foi solto um botao do teclado!" << std::endl;
                switch (event.key.code)
                {
                case sf::Keyboard::A:
                    hero.InvertWalkLeft();
                    break;
                case sf::Keyboard::D:
                    hero.InvertWalkRight();
                    break;
                case sf::Keyboard::S:
                    hero.InvertCrouching();
                    break;
                case sf::Keyboard::W:
                    hero.InvertJumping();
                    break;
                default:
                    break;
                }
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
        // Limpar tela
        window.clear(sf::Color(100U, 100U, 100U));

        // Atualizar relação de tempo para entidades
        hero.SetElapsedTime(timediff);

        // Executar parâmetros e execuções de entidades
        hero.Execute();

        // Após atualizar entidades executar colisões
        maneger.UpdateCollisions();

        // Atualizar tela
        window.setView(Myview);
        Myview.setCenter(hero.GetConstBody().getPosition());

        // Desenhar entidades após atualizações, e colisões
        for (i = 0; i < obs.size(); ++i)
            obs[i].SelfPrint(window);
        hero.SelfPrint(window);

#ifdef _DEBUG
        for (i = 0; i < obs.size(); ++i) {
            obs[i].stringInfoUptade();
            obs[i].PrintInfo(window);
        }
        hero.stringInfoUptade();
        hero.PrintInfo(window);
#endif

        window.display();
    }

    return 0;
}