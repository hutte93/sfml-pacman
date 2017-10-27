#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <iostream>

class Game;

class Gamestate
{
public:
    virtual void HandleEvents(Game& game) = 0;
    virtual void Update(Game& game) = 0;
    virtual void Draw(Game& game) = 0;

    virtual ~Gamestate()
    {
        std::cout << "Basisdestruktor wurde aufgerufen" << std::endl;
    };
};

#endif // GAMESTATE_H_INCLUDED
