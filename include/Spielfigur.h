#ifndef SPIELFIGUR_H
#define SPIELFIGUR_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>


class Spielfigur : public sf::RectangleShape
{
    public:
        Spielfigur(sf::Vector2f rect, sf::Color col, sf::Vector2f pos, sf::String textur);
        virtual ~Spielfigur();

        void Init();
        void Update(sf::RenderWindow &window, sf::Time elapsed);
        void setKeyUp(sf::Keyboard::Key k);
        void setKeyDown(sf::Keyboard::Key k);
        void setKeyLeft(sf::Keyboard::Key k);
        void setKeyRight(sf::Keyboard::Key k);

    protected:

    private:
        sf::Keyboard::Key Up;
        sf::Keyboard::Key Down;
        sf::Keyboard::Key Left;
        sf::Keyboard::Key Right;

        sf::Vector2f initPos;
        sf::Time tempElapsedTime;
        sf::Texture texture;

        bool isAlive;
        int direction;

        float velocity;
        int frame;
        int frames;
        int frameWidth;
        int frameHeight;
};

#endif // SPIELFIGUR_H
