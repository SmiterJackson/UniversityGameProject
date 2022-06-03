#pragma once

//#include "Header/stdafx.h"
#include "stdafx.cpp"
#include "Manegers/Headers/animation.h"
#include "Entities/Headers/entity.h"
#include "Manegers/Headers/drawble.h"
#include "Lists/Headers/myList.h"
#include "Entities/Characters/Headers/Hero.h"

#define PLAYER1_SHEET std::string("JogoMyVersion\\Resources\\images\\sprites\\Characters\\gunner_green.png")
#define PLAYER_SIZE 48.0f

int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 850), "Janela do Jogo");
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    float fator = 4.0f;
    float timediff = 0.0f;
    int animacao = 0;
    bool direita = true;

    sf::Texture texture;
    texture.loadFromFile(PLAYER1_SHEET);

    sf::RectangleShape rect(sf::Vector2f(PLAYER_SIZE * fator, PLAYER_SIZE * fator));
    //rect.setScale(sf::Vector2f(fator, fator));
    rect.move(sf::Vector2f(350.0f, 200.0f));

    std::vector<std::pair<unsigned int, AnimationDataType>> AnimationsConstructors =  {{Hero::animations::none,   {0, 0, 0, 0, 1.00f}} ,
                                                                                       {Hero::animations::Idle,   {0, 4, 2, 48, 0.20f, true} },
                                                                                       {Hero::animations::Crouch, {5, 7, 2, 48, 0.20f} },
                                                                                       {Hero::animations::Jump,   {6, 7, 1, 48, 0.20f} },
                                                                                       {Hero::animations::Run,    {0, 5, 1, 48, 0.20f, true} },
                                                                                       {Hero::animations::Death,  {0, 7, 0, 48, 0.20f} }};
    VecOfPair_key_cutOfSprite sprites{};
    
    Hero hero(rect, PLAYER1_SHEET, sprites, AnimationsConstructors, 5, true, true);
    sf::Vector2i pos;
    sf::FloatRect bounds;

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
                    hero.Died();
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

        hero.Execute();
        hero.SetElapsedTime(timediff);
        hero.SelfPrintSelected(window);

        window.display();
    }

    return 0;
}