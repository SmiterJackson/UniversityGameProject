#include "game.h"

#include "GUI/Buttons/Headers/button.h"
#define FONT_REF std::string("JogoMyVersion\\Resources\\fonts\\hf-free-complete\\equipment-pro-v1.1\\EquipmentPro.ttf")
#define BACKGROUND_REF "JogoMyVersion\\Resources\\images\\Background\\cyberpunk-street-files\\PNG\\cyberpunk-street.png"
#define GRID_SIZE_FLOAT 32.f
#define GRID_SIZE_INT 32

Game::Game()
{};
Game::~Game()
{};

void Game::Execute()
{
    sf::RenderWindow window(sf::VideoMode(1728, 972), "Janela do Jogo");
    sf::View Myview(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(window.getSize()));
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    Stage stage(window, "", BACKGROUND_REF);

    std::vector<Button*> buttons;
    sf::Font font;
    font.loadFromFile(FONT_REF);

    buttons.emplace_back(new Button(Myview, sf::Vector2f(200, 100), font, "INICIAR", 16));
    buttons.emplace_back(new Button(Myview, sf::Vector2f(200, 200), font, "PULAR", 16));
    buttons.emplace_back(new Button(Myview, sf::Vector2f(200, 300), font, "FOODA-SE", 16));

    sf::RectangleShape ref;
    ref.setOutlineColor(sf::Color(255,0,0));
    ref.setSize(sf::Vector2f(32.f, 32.f));
    ref.setOutlineThickness(2.f);
    ref.setOrigin(ref.getSize() / 2.f);
    // Myview.getCenter().x, Myview.getCenter().y + Myview.getCenter().y / 2.0f
    float timediff = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        //Definir o tempo decorrido desdde o último ciclo
        timediff = clock.restart().asSeconds();
        
        // Atualiza as posições relativas do mouse
        this->mouseToDesktop = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
        this->mouseToWindow = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        this->mouseToView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        this->mouseToGrid = sf::Vector2i(this->mouseToView / GRID_SIZE_FLOAT);

        for (Button* bt : buttons)
            if (bt->isPressed())
                std::cout << "Foi tocado o botao de (" << bt->GetText() << ")." << std::endl;

        stage.Execute(window, timediff);

        for (Button* bt : buttons)
            bt->update(mouseToView);

        for (Button* bt : buttons)
            bt->SelfPrint(window);

        //ref.setPosition();
        window.draw(ref);

        window.display();
        window.clear();
    }
};