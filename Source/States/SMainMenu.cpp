#include "SMainMenu.h"

#include <iostream>

#include "Application.h"

#include "../Util/Random.h"
#include "../ResourceManager/ResourceHolder.h"

namespace State
{
    MainMenu::MainMenu(Application& app)
    :   StateBase   (app)
    ,   m_frontMenu (220.0f)
    {
        m_menuMusic.openFromFile("res/music/menu.ogg");
        m_menuMusic.play();
        m_menuMusic.setLoop(true);

        m_banner.setSize({(float)WINDOW_WIDTH, 200.0f});
        m_banner.setTexture(&ResourceHolder::getTexure("logo"));

        m_frontMenu.addComponent<GUI::BasicButton>("Play",
        [&]()
        {
            std::cout << "Play button pressed\n";
        });

        m_frontMenu.addComponent<GUI::BasicButton>("Settings",
        [&]()
        {

        });

        m_frontMenu.addComponent<GUI::BasicButton>("Exit",
        [&]()
        {

        });
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
        m_frontMenu.update(m_pApplication->getWindow(), e);
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
        m_frontMenu.draw(window);
    }

}
