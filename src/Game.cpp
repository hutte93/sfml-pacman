#include "Game.h"

Game::Game()
{
    window.create(sf::VideoMode(1280, 720), "SFML Pacman!", sf::Style::Close);
    //window.setFramerateLimit(60);
    running = true;
    hasFocus = true;
}

Game::~Game()
{
    running = false;
    std::cout << "Game Destruktor wurde aufgerufen" << std::endl;
}

void Game::Run()
{
    while (window.isOpen())
    {
        now = clock.getElapsedTime();
        frameDeltaTime = (now - then);
        then = now;

        CurrentState->HandleEvents(*this);

        if (hasFocus)
        {
            window.clear(sf::Color(0, 134, 194));
            CurrentState->Update(*this);
            CurrentState->Draw(*this);
        }

        window.display();
    }
}

bool Game::isRunning()
{
    return running;
}

void Game::ChangeState(gameStates newState)
{
    switch(newState)
    {
        case MAINMENU:
            CurrentState = std::move(std::unique_ptr<MainMenuState>(new MainMenuState));
            break;

        case PLAY:
            CurrentState = std::move(std::unique_ptr<PlayState>(new PlayState));
            break;
    }
}

std::string Game::NumberToString(int num)
{
    std::ostringstream ss;
    ss << num;
    return ss.str();
}
