#include "Fresspunkt.h"

Fresspunkt::Fresspunkt(float radius, sf::Color col, sf::Vector2f pos, std::shared_ptr<Spielfigur> pacman)
{
    setRadius(radius);
    setFillColor(col);
    setOrigin(getRadius(), getRadius());
    setPosition(pos);

    player = pacman;

    eaten = false;
    setValue(10);
}

Fresspunkt::~Fresspunkt()
{
    //dtor
}

void Fresspunkt::Update(sf::RenderWindow &window, sf::Time elapsed)
{
    // collision detection
    if (getGlobalBounds().left < player->getPosition().x + player->getSize().x / 2 &&
        getGlobalBounds().left + getGlobalBounds().width > player->getPosition().x - (player->getSize().x / 2) &&
        getGlobalBounds().top + getGlobalBounds().height >= player->getPosition().y - player->getSize().y / 2 &&
        getGlobalBounds().top <= player->getPosition().y + player->getSize().y / 2)
    {
        this->setEaten(true);
    }
}

bool Fresspunkt::isEaten()
{
    return eaten;
}

void Fresspunkt::setEaten(bool bEaten)
{
    eaten = bEaten;
}

int Fresspunkt::getValue()
{
    return value;
}

void Fresspunkt::setValue(int newValue)
{
    value = newValue;
}
