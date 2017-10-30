#include "Spielfigur.h"

Spielfigur::Spielfigur(sf::Vector2f rect, sf::Color col, sf::Vector2f pos, sf::String textur)
{
    setSize(rect);
    //setFillColor(col);
    setOrigin(getSize().x / 2, getSize().y / 2);
    setPosition(pos);

    texture.loadFromFile(textur);
    texture.setSmooth(true);
    setTexture(&texture, true);

    initPos = pos;
    velocity = 0.f;
    direction = 1;
    isRunning = false;

    frame = 1;
    frames = 4;
    frameWidth = texture.getSize().x / 4;
    frameHeight = texture.getSize().y / 4;
}

Spielfigur::~Spielfigur()
{
    //dtor
}

void Spielfigur::Init()
{
    setPosition(initPos);
    velocity = 300.f;
    isRunning = true;
}

void Spielfigur::setKeyUp(sf::Keyboard::Key k)
{
    Up = k;
}

void Spielfigur::setKeyDown(sf::Keyboard::Key k)
{
    Down = k;
}

void Spielfigur::setKeyLeft(sf::Keyboard::Key k)
{
    Left = k;
}

void Spielfigur::setKeyRight(sf::Keyboard::Key k)
{
    Right = k;
}

void Spielfigur::Update(sf::RenderWindow &window, sf::Time elapsed)
{
    if (isRunning == false)
    {
        setTextureRect(sf::IntRect(frameWidth * frame, direction*frameHeight, frameWidth, frameHeight));
    }
    else
    {
        tempElapsedTime += elapsed;

        if (tempElapsedTime.asSeconds() >= 0.08)
        {
            if (frame < frames - 1)
            {
                frame++;
            }
            else
            {
                frame = 0;
            }

            tempElapsedTime = tempElapsedTime.Zero;
            setTextureRect(sf::IntRect(frameWidth * frame, direction * frameHeight, frameWidth, frameHeight));
        }
    }

    if (sf::Keyboard::isKeyPressed(Up))
    {
        direction = 2;
    }
    else if (sf::Keyboard::isKeyPressed(Down))
    {
        direction = 3;
    }
    else if (sf::Keyboard::isKeyPressed(Left))
    {
        direction = 1;
    }
    else if (sf::Keyboard::isKeyPressed(Right))
    {
        direction = 0;
    }

    switch (direction)
    {
        case 2:
            if (getPosition().y > getGlobalBounds().height / 2 + 41)
                move(sf::Vector2f(0.f, -velocity * elapsed.asSeconds()));
            break;
        case 3:
            if (getPosition().y < (window.getSize().y - getGlobalBounds().height / 2) - 5)
                move(sf::Vector2f(0.f, velocity * elapsed.asSeconds()));
            break;
        case 1:
            if (getPosition().x > getGlobalBounds().width / 2 + 5)
                move(sf::Vector2f(-velocity * elapsed.asSeconds(), 0.f));
            break;
        case 0:
            if (getPosition().x < (window.getSize().x - getGlobalBounds().width / 2) - 5)
                move(sf::Vector2f(velocity * elapsed.asSeconds(), 0.f));
            break;
    }
}

bool Spielfigur::getIsRunning()
{
    return isRunning;
}

