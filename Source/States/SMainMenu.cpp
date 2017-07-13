#include "SMainMenu.h"

#include <iostream>

#include "Application.h"

#include "../Util/Random.h"

#include "../ResourceManager/ResourceHolder.h"

namespace State
{
    constexpr static int    SIZE            = 40,
                            MIN_LIFE_SECS   = 4,
                            MAX_LIFE_SECS   = 8;

    //bubble :o
    Bubble::Bubble()
    {
        m_sprite.setSize({SIZE, SIZE});
        reset();
    }

    void Bubble::update(float dt)
    {
        constexpr auto p = 3.14159f / 2.0f;

        m_sprite.move(sin(m_lifeTime.getElapsedTime().asSeconds()) * dt, -ySpeed * dt);
        m_sprite.setTexture(&ResourceHolder::getTexure("bubble"));

        if (m_lifeTime.getElapsedTime() > m_deathTime)
        {
            reset();
        }

        auto time       = m_lifeTime.getElapsedTime().asSeconds();
        auto deathTime  = m_deathTime.asSeconds();
        auto fade  = (std::sin((time * (p / deathTime)) * 2 ));
        auto alpha = fade * 255;
        auto c = sf::Color::White;
        c.a = alpha;
        m_sprite.setFillColor(c);
    }

    void Bubble::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
    }

    void Bubble::reset()
    {
        m_deathTime = sf::seconds(Random::get().intInRange(MIN_LIFE_SECS, MAX_LIFE_SECS));

        auto x = Random::get().floatInRange(0, 1280 - SIZE);
        auto y = Random::get().floatInRange(SIZE, 350);

        ySpeed = Random::get().floatInRange(13, 22);

        m_sprite.setPosition({x, y});

        m_normalisedCycle = 3.14159f / m_deathTime.asSeconds();

        m_lifeTime.restart();
    }



    MainMenu::MainMenu(Application& app)
    :   StateBase   (app)
    {
        m_menuMusic.openFromFile("res/music/menu.ogg");
        m_menuMusic.play();
        m_menuMusic.setLoop(true);

        m_banner.setSize({ (float)app.getWindow().getSize().x, 200.0f});
        m_banner.setTexture(&ResourceHolder::getTexure("logo"));
    }

    MainMenu::~MainMenu()
    {
        m_menuMusic.stop();
    }

    void MainMenu::handleInput()
    {

    }

    void MainMenu::handleEvent(sf::Event e)
    {

    }

    void MainMenu::update(float dt)
    {
        for (auto& bubble : m_bubbles)
        {
            bubble.update(dt);
        }
    }

    void MainMenu::fixedUpdate(float dt)
    {

    }

    void MainMenu::draw(sf::RenderWindow& window)
    {
        for (auto& bubble : m_bubbles)
        {
            bubble.draw(window);
        }
        window.draw(m_banner);
    }

}
