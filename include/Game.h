#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Gamestate.h"
#include "MainMenuState.h"
#include "PlayState.h"

class Game
{
public:
    Game();
    ~Game();

    enum gameStates {MAINMENU, PLAY};

    void Run();
    bool isRunning();
    void ChangeState(gameStates newState);
    std::string NumberToString(int num);

    bool running;
    bool hasFocus;
    sf::RenderWindow window;

    sf::Clock clock;
    sf::Time then = clock.getElapsedTime();
    sf::Time now;
    sf::Time frameDeltaTime;

private:
    std::unique_ptr<Gamestate> CurrentState;
};

#endif
