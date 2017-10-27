#ifndef MAINMENUSTATE_H_INCLUDED
#define MAINMENUSTATE_H_INCLUDED

#include "Game.h"
#include <memory>
#include <SFML/Graphics.hpp>

class MainMenuState : public Gamestate
{
public:
    MainMenuState();
    ~MainMenuState();

    void HandleEvents(Game& game);
    void Update(Game& game);
    void Draw(Game& game);

private:
    bool bStartGameSelected;
    bool bQuitGameSelected;

    sf::Font font;
    sf::Text txtStartGame;
    sf::Text txtQuitGame;

//    sf::SoundBuffer sbSelect;
//    sf::SoundBuffer sbClick;
//    sf::Sound sndSelect;
//    sf::Sound sndClick;
};

#endif // MAINMENUSTATE_H_INCLUDED
