#include "PlayState.h"

PlayState::PlayState()
{
    pacman = std::make_shared<Spielfigur>(sf::Vector2f(40.f, 40.f), sf::Color::Yellow, sf::Vector2f(1280/2.f, 720/2+15.f), "img/pacman.png");

    targets = 0;
    int nX = 40;
    int nY = 75;
    for (int j = 0; j < 11; j++)
    {
        for (int i = 0; i < 21; i++)
        {
            if (targets % 10 == 0)
            {
                fresspunkt[i][j] = std::make_shared<Fresspunkt>(6.5f, sf::Color::Yellow, sf::Vector2f(nX, nY), pacman);
                fresspunkt[i][j]->setValue(50);
             }
            else
            {
                fresspunkt[i][j] = std::make_shared<Fresspunkt>(5.f, sf::Color::White, sf::Vector2f(nX, nY), pacman);
            }
            targets++;
            nX += 60;
        }
        nY += 60;
        nX = 40;
    }

    fresspunkt[10][5]->setValue(0);
    targets--;

    font.loadFromFile("font/Ubuntu-B.ttf");

    // ready screen
    sf::Vector2f readySize(1280.f, 100.f);
    ready.setSize(readySize);
    ready.setOrigin(ready.getSize().x / 2, ready.getSize().y / 2);
    ready.setPosition(1280/2.f, 200.f);
    ready.setFillColor(sf::Color(66,66,66));

    txtReady.setFont(font);
    txtReady.setCharacterSize(50);
    txtReady.setFillColor(sf::Color::Green);
    txtReady.setString("Ready ?");
    sf::FloatRect txtRect1 = txtReady.getGlobalBounds();
    txtReady.setOrigin(txtRect1.left + txtRect1.width / 2.0f,
                       txtRect1.top + txtRect1.height / 2.0f);
    txtReady.setPosition(1280/2.f, 200.f);

    // background
    sf::Vector2f windowSize(1280.f, 720.f);
    background.setSize(windowSize);
    background.setFillColor(sf::Color::Black);

    // borders
    sf::Vector2f horizontalBorderSize(1280.f, 4.f);
    sf::Vector2f verticalBorderSize(4.f, 680.f);
    topBorder.setSize(horizontalBorderSize);
    topBorder.setFillColor(sf::Color::Blue);
    topBorder.setPosition(0.f, 36.f);
    bottomBorder.setSize(horizontalBorderSize);
    bottomBorder.setFillColor(sf::Color::Blue);
    bottomBorder.setPosition(0.f, 716.f);
    leftBorder.setSize(verticalBorderSize);
    leftBorder.setFillColor(sf::Color::Blue);
    leftBorder.setPosition(0.f, 40.f);
    rightBorder.setSize(verticalBorderSize);
    rightBorder.setFillColor(sf::Color::Blue);
    rightBorder.setPosition(1276.f, 40.f);

    // texts
    txtScoreLabel.setFont(font);
    txtScoreLabel.setCharacterSize(25);
    txtScoreLabel.setFillColor(sf::Color::Yellow);
    txtScoreLabel.setString("Score: ");
    txtScoreLabel.setPosition(20.f, 3.f);

    txtScore.setFont(font);
    txtScore.setCharacterSize(25);
    txtScoreLabel.setFillColor(sf::Color::Yellow);
    txtScore.setString("0");
    txtScore.setPosition(100.f, 3.f);

    // keybinding
    pacman->setKeyUp(sf::Keyboard::Up);
    pacman->setKeyDown(sf::Keyboard::Down);
    pacman->setKeyLeft(sf::Keyboard::Left);
    pacman->setKeyRight(sf::Keyboard::Right);

    score = 0;
}

PlayState::~PlayState()
{
    //dtor
}

void PlayState::HandleEvents(Game &game)
{

    sf::Event event;

    while (game.window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            game.window.close();
            game.running = false;
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::F1)
            {
                game.ChangeState(Game::MAINMENU);
            }

            if (event.key.code == sf::Keyboard::Space)
            {
                pacman->Init();
            }
        }
    }
}

void PlayState::Update(Game &game)
{
    pacman->Update(game.window, game.frameDeltaTime);

    for (int j = 0; j < 11; j++)
    {
        for (int i = 0; i < 21; i++)
        {
            fresspunkt[i][j]->Update(game.window, game.frameDeltaTime);
        }
    }

    txtScore.setString(game.NumberToString(score));
}

void PlayState::Draw(Game &game)
{
    game.window.draw(background);
    game.window.draw(topBorder);
    game.window.draw(bottomBorder);
    game.window.draw(leftBorder);
    game.window.draw(rightBorder);

    for (int j = 0; j < 11; j++)
    {
        for (int i = 0; i < 21; i++)
        {
            if (fresspunkt[i][j]->isEaten() == false)
            {
                game.window.draw(*fresspunkt[i][j]);
            }
            else
            {
                if (fresspunkt[i][j]->getValue() > 0)
                {
                    score += fresspunkt[i][j]->getValue();
                    fresspunkt[i][j]->setValue(0);
                    targets--;
                }
            }
        }
    }

    game.window.draw(*pacman);
    game.window.draw(txtScoreLabel);
    game.window.draw(txtScore);

    if (pacman->getIsRunning() == false)
    {
        game.window.draw(ready);
        game.window.draw(txtReady);
    }

    if (targets == 0)
    {
        game.ChangeState(Game::END);
    }
}
