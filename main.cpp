#include <iostream>
#include "Game.h"

int main()
{
    Game game;
        game.ChangeState(Game::MAINMENU);

    while (game.isRunning())
    {
        game.Run();
    }

    return 0;
}
