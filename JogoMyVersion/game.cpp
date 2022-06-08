#include "game.h"

Game::Game()
{};
Game::~Game()
{};

void Game::Execute()
{
    sf::RenderWindow window(sf::VideoMode(1728, 972), "Janela do Jogo");
    sf::View Myview(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(960.0f, 540.0f));
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    Stage stage(window, "", BACKGROUND_REF);

    float timediff = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        //Definir o tempo decorrido desdde o último ciclo
        timediff = clock.restart().asSeconds();

        // Tratar os Inputs
        stage.TreatInput(window);

        // Limpar tela
        window.clear(sf::Color(100U, 100U, 100U));

        // Executar a fase antes de desenha-la
        stage.Execute(window, timediff);

        // Desenhar a fase antes de pedir ooo display
        stage.SelfPrint(window);

        window.display();
    }
};