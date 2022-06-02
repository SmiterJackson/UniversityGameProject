#pragma once

//#include "Header/stdafx.h"
#include "stdafx.cpp"
#include "Manegers/Headers/animation.h"
#include "Entities/Headers/entity.h"
#include "Manegers/Headers/drawble.h"
#include "Entities/Headers/animatedEntity.h"
#include "Lists/Headers/myList.h"

#define PLAYER1_SHEET std::string("JogoMyVersion/Resources/Images/Sprites/Players/Player_1/player_1_sheet.png")

int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 850), "Janela do Jogo");
    window.setVerticalSyncEnabled(true);

    float fator = 3.0f;
    float timediff = 0.0f;
    int animacao = 0;
    bool direita = true;

    //{
    //    std::vector<std::string> ints = { {"Eduardo"}, {"Leonardo"}, {"Gabriel"}, {"Juvenal"} };
    //    MyList<std::string> intList;
    //    intList.Push_back(std::string("Gabriele"));
    //    intList.Pop_back();
    //    intList += ints;
    //}
    

    sf::Texture texture;
    texture.loadFromFile(PLAYER1_SHEET);
    sf::RectangleShape rect(sf::Vector2f(135.0f * fator, 135.0f * fator));
    std::pair<unsigned int, AnimationDataType> AnimationsConstructors[] =  {{0, {0, 10, 0, 135, 0.20f}},
                                                                            {1, {0, 9, 1, 135, 0.20f}},
                                                                            {2, {0, 6, 2, 135, 0.20f}},
                                                                            {3, {6, 10, 2, 135, 0.20f}},
                                                                            {4, {0, 5, 3, 135, 0.20f}},
                                                                            {5, {5, 9, 3, 135, 0.20f}},
                                                                            {6, {0, 3, 4, 135, 0.20f}},
                                                                            {7, {3, 5, 4, 135, 0.20f}},
                                                                            {8, {4, 6, 4, 135, 0.20f}}};
    rect.setPosition(sf::Vector2f(350.0f, 200.0f));
    AnimatedEntity hero(texture, AnimationsConstructors, 9, rect);

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
                if (event.key.code == sf::Keyboard::A) {
                    animacao++;
                    if (animacao >= 8)
                        animacao = 0;
                }
                else if (event.key.code == sf::Keyboard::D) {
                    animacao--;
                    if (animacao <= 0)
                        animacao = 8;
                }
                std::cout << "Foi tocado um botao do teclado!" << std::endl;
                break;
            case sf::Event::KeyReleased:
                std::cout << "Foi solto um botao do teclado!" << std::endl;
                break;
            case sf::Event::MouseButtonPressed:
                direita = false;
                std::cout << "Foi tocado um botao do mouse!" << std::endl;
                break;
            case sf::Event::MouseButtonReleased:
                direita = true;
                std::cout << "Foi solto um botao do mouse!" << std::endl;
                break;
            default:
                break;
            }
        }

        window.clear(sf::Color(100U, 100U, 100U));

        hero.SelfPrintSelected(window, animacao, timediff);

        window.display();
    }

    return 0;
}