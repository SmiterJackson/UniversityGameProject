#pragma once

#include "Manegers/Headers/parallax.h"
#include "Stages/Headers/baseStage.h"

#define STAGE_BACKGROUND std::string("JogoMyVersion\\Resources\\images\\backgrounds\\Background\\Background.png")

int main()
{
    sf::RenderWindow window(sf::VideoMode(1728, 972), "Janela do Jogo");
    sf::View Myview(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(960.0f, 540.0f));
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    Stage stage(STAGE_BACKGROUND, Myview);

    

    float timediff = 0.0f;
    sf::Clock clock;

    while(window.isOpen())
    {
        //Definir o tempo decorrido desdde o último ciclo
        timediff = clock.restart().asSeconds();

        // Tratar os Inputs
        stage.TreatInput(window);

        // Limpar tela
        window.clear(sf::Color(100U, 100U, 100U));

        window.setView(stage.GetConstView());

        // Executar a fase antes de desenha-la
        stage.Execute(timediff);

        // Desenhar a fase antes de pedir ooo display
        stage.SelfPrint(window);

        window.display();
    }

    return 0;
}