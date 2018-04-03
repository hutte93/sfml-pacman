#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
    font.loadFromFile("font/Ubuntu-B.ttf");

    txtStartGame.setFont(font);
    txtStartGame.setString("Let me play!");
    txtStartGame.setCharacterSize(30);
    sf::FloatRect txtRect1 = txtStartGame.getGlobalBounds();
    txtStartGame.setOrigin(txtRect1.left + txtRect1.width / 2.0f,
                           txtRect1.top + txtRect1.height / 2.0f);
    txtStartGame.setPosition(1280 / 2, 720 / 2 - 50);

    txtQuitGame.setFont(font);
    txtQuitGame.setString("That's enough!");
    txtQuitGame.setCharacterSize(30);
    sf::FloatRect txtRect2 = txtQuitGame.getGlobalBounds();
    txtQuitGame.setOrigin(txtRect2.left + txtRect2.width / 2.0f,
                           txtRect2.top + txtRect2.height / 2.0f);
    txtQuitGame.setPosition(1280 / 2, 720 / 2 + 50);

    bStartGameSelected = false;
    bQuitGameSelected = false;
}

void MainMenuState::HandleEvents(Game& game)
{
    sf::Event event;

    while (game.window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            game.window.close();
            game.running = false;
        }

        // Maustaste gedrückt
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == 0)
            {
                if (bStartGameSelected)
                {
                    game.ChangeState(Game::PLAY);
                }
                else if (bQuitGameSelected)
                {
                    game.window.close();
                    game.running = false;
                }
            }
        }
    }
}

void MainMenuState::Update(Game& game)
{
    if (txtStartGame.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtStartGame.getFillColor() != sf::Color::Green)
    {
        txtStartGame.setFillColor(sf::Color::Green);
        bStartGameSelected = true;
    }
    else if (!txtStartGame.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtStartGame.getFillColor() == sf::Color::Green)
    {
        txtStartGame.setFillColor(sf::Color::White);
        bStartGameSelected = false;
    }

    if (txtQuitGame.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtQuitGame.getFillColor() != sf::Color::Green)
    {
        txtQuitGame.setFillColor(sf::Color::Green);
        bQuitGameSelected = true;
    }
    else if (!txtQuitGame.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtQuitGame.getFillColor() == sf::Color::Green)
    {
        txtQuitGame.setFillColor(sf::Color::White);
        bQuitGameSelected = false;
    }
}

void MainMenuState::Draw(Game& game)
{
    game.window.draw(txtStartGame);
    game.window.draw(txtQuitGame);
}

MainMenuState::~MainMenuState()
{
    std::cout << "MainMenueState Destruktor aufgerufen." << std::endl;
}
