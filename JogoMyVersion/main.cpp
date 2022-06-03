#pragma once

//#include "Header/stdafx.h"
#include "stdafx.cpp"
#include "Manegers/Headers/animation.h"
#include "Entities/Headers/entity.h"
#include "Manegers/Headers/drawble.h"
#include "Lists/Headers/myList.h"
#include "Entities/Characters/Headers/Hero.h"
#include "Entities/Obstacles/Headers/Obstacles.h"

#define PLAYER1_SHEET std::string("JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_green.png")
#define TILE_SHEET std::string("JogoMyVersion\\Resources\\images\\backgrounds\\Tiles\\IndustrialTile_sheet.png")
#define PLAYER_SIZE 48.0f
#define TILE_SIZE 32.0f

int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 850), "Janela do Jogo");
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    float fator = 4.0f;
    float timediff = 0.0f;
    int animacao = 0, i = 0;
    bool direita = true;

    sf::Texture texture;
    texture.loadFromFile(PLAYER1_SHEET);

    sf::RectangleShape rect(sf::Vector2f(PLAYER_SIZE * fator, PLAYER_SIZE * fator));
    sf::RectangleShape tiles_rect[] = { sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator)),
                                        sf::RectangleShape(sf::Vector2f(TILE_SIZE * fator, TILE_SIZE * fator))};

    sf::IntRect tiles_textureCur = sf::IntRect(2 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE);
    
    std::vector<std::pair<unsigned int, AnimaData>> AnimationsConstructors =  {{Hero::animations::Idle,   {0, 4, 2, 48, 0.20f, true} },
                                                                                       {Hero::animations::Crouch, {5, 7, 2, 48, 0.20f} },
                                                                                       {Hero::animations::Jump,   {6, 7, 1, 48, 0.20f} },
                                                                                       {Hero::animations::Run,    {0, 5, 1, 48, 0.20f, true} },
                                                                                       {Hero::animations::Death,  {0, 7, 0, 48, 0.20f} }};
    VecOfPair_key_cutOfSprite sprites{};
    rect.move(sf::Vector2f(350.0f, 200.0f));
    Hero hero(rect, PLAYER1_SHEET, sprites, AnimationsConstructors, 5, true, true);

    std::vector<obstacles::BaseObstacle> obs = {{tiles_rect[0], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[1], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[2], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[3], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[4], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[5], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[6], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[7], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[8], TILE_SHEET, tiles_textureCur}, 
                                            {tiles_rect[9], TILE_SHEET, tiles_textureCur}};

    for (i = 0; i < obs.size(); ++i)
        obs[i].GetRectShape().move(sf::Vector2f(100.0f + (i * TILE_SIZE * fator), 400.0f));
        

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
                std::cout << "Foi tocado um botao do teclado!" << std::endl;
                break;
            case sf::Event::KeyReleased:
                std::cout << "Foi solto um botao do teclado!" << std::endl;
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

        window.clear(sf::Color(100U, 100U, 100U));

        for (i = 0; i < obs.size(); ++i)
            obs[i].SelfPrintSelected(window);

        hero.Execute();
        hero.SetElapsedTime(timediff);
        hero.SelfPrintSelected(window);

        window.display();
    }

    return 0;
}