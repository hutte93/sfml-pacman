#ifndef FRESSPUNKT_H
#define FRESSPUNKT_H

#include "Spielfigur.h"
#include <memory>


class Fresspunkt : public sf::CircleShape
{
    public:
        Fresspunkt(float rad, sf::Color col, sf::Vector2f pos, std::shared_ptr<Spielfigur> pacman);
        virtual ~Fresspunkt();

        void Update(sf::RenderWindow &window, sf::Time elapsed);

        bool isEaten();
        void setEaten(bool);
        int getValue();
        void setValue(int);
    protected:
    private:
        bool eaten;
        int value;
        std::shared_ptr<Spielfigur> player;
};

#endif // FRESSPUNKT_H
