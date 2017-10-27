#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "Gamestate.h"
#include "Spielfigur.h"
#include "Fresspunkt.h"


class PlayState : public Gamestate
{
    public:
        PlayState();
        virtual ~PlayState();

        void HandleEvents(Game &game);
        void Update(Game &game);
        void Draw(Game &game);

    protected:

    private:
        std::shared_ptr<Spielfigur> pacman;
        std::shared_ptr<Fresspunkt> fresspunkt[21][11];

        sf::RectangleShape background;
        sf::RectangleShape topBorder;
        sf::RectangleShape bottomBorder;
        sf::RectangleShape leftBorder;
        sf::RectangleShape rightBorder;

        sf::Font font;
        sf::Text txtScoreLabel;
        sf::Text txtScore;

        int score;
        int targets;
};

#endif // PLAYSTATE_H
