#include "EndState.h"

EndState::EndState()
{
    font.loadFromFile("font/Ubuntu-B.ttf");

    txtRestart.setFont(font);
    txtRestart.setString("Restart");
    txtRestart.setCharacterSize(30);
    sf::FloatRect txtRect1 = txtRestart.getGlobalBounds();
    txtRestart.setOrigin(txtRect1.left + txtRect1.width / 2.0f,
                           txtRect1.top + txtRect1.height / 2.0f);
    txtRestart.setPosition(1280 / 2, 720 / 2 - 50);

    txtMainMenu.setFont(font);
    txtMainMenu.setString("Back to the MainMenu");
    txtMainMenu.setCharacterSize(30);
    sf::FloatRect txtRect2 = txtMainMenu.getGlobalBounds();
    txtMainMenu.setOrigin(txtRect2.left + txtRect2.width / 2.0f,
                           txtRect2.top + txtRect2.height / 2.0f);
    txtMainMenu.setPosition(1280 / 2, 720 / 2 + 50);

    bRestartGameSelected = false;
    bBackToMainMenuSelected = false;
}

void EndState::HandleEvents(Game& game)
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
                if (bRestartGameSelected)
                {
                    game.ChangeState(Game::PLAY);
                }
                else if (bBackToMainMenuSelected)
                {
                    game.ChangeState(Game::MAINMENU);
                }
            }
        }
    }
}

void EndState::Update(Game& game)
{
    if (txtRestart.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtRestart.getColor() != sf::Color::Green)
    {
        txtRestart.setColor(sf::Color::Green);
        bRestartGameSelected = true;
    }
    else if (!txtRestart.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtRestart.getColor() == sf::Color::Green)
    {
        txtRestart.setColor(sf::Color::White);
        bRestartGameSelected = false;
    }

    if (txtMainMenu.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtMainMenu.getColor() != sf::Color::Green)
    {
        txtMainMenu.setColor(sf::Color::Green);
        bBackToMainMenuSelected = true;
    }
    else if (!txtMainMenu.getGlobalBounds().contains(
        sf::Mouse::getPosition(game.window).x,
        sf::Mouse::getPosition(game.window).y) &&
        txtMainMenu.getColor() == sf::Color::Green)
    {
        txtMainMenu.setColor(sf::Color::White);
        bBackToMainMenuSelected = false;
    }
}

void EndState::Draw(Game& game)
{
    game.window.draw(txtRestart);
    game.window.draw(txtMainMenu);
}

EndState::~EndState()
{
    std::cout << "EndState Destruktor aufgerufen." << std::endl;
}
