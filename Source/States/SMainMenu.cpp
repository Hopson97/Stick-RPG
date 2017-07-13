#include "SMainMenu.h"

#include <iostream>

#include "Application.h"

#include "../Util/Random.h"
#include "../ResourceManager/ResourceHolder.h"

namespace State
{
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
