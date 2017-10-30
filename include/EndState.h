#ifndef ENDSTATE_H
#define ENDSTATE_H

#include "Game.h"
#include <memory>
#include <SFML/Graphics.hpp>


class EndState : public Gamestate
{
    public:
        EndState();
        ~EndState();

        void HandleEvents(Game& game);
        void Update(Game& game);
        void Draw(Game& game);

    private:
        bool bRestartGameSelected;
        bool bBackToMainMenuSelected;

        sf::Font font;
        sf::Text txtRestart;
        sf::Text txtMainMenu;
};

#endif // ENDSTATE_H
