#include "SMainMenu.h"

#include <iostream>

#include "Application.h"

#include "../Util/Random.h"
#include "../ResourceManager/ResourceHolder.h"

#include "GUIMeni/BasicButton.h"
#include "GUIMeni/VariableButton.h"

namespace State
{
    MainMenu::MainMenu(Application& app)
    :   StateBase   (app)
    ,   m_frontMenu         (220.0f)
    ,   m_statSelectionMenu (20.0f)
    {
        m_menuMusic.openFromFile("res/music/menu.ogg");
        m_menuMusic.play();
        m_menuMusic.setLoop(true);

        m_banner.setSize({(float)WINDOW_WIDTH, 200.0f});
        m_banner.setTexture(&ResourceHolder::getTexure("logo"));

        initMenu();
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
        m_activeMenu->update(m_pApplication->getWindow(), e);
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
        if (m_menuState == Menu_State::Front)
        {
            window.draw(m_banner);
        }
        else if (m_menuState == Menu_State::Attribute)
        {

        }

        for (auto& bubble : m_bubbles)
        {
            bubble.draw(window);
        }
        m_activeMenu->draw(window);
    }

    void MainMenu::initMenu()
    {
        m_frontMenu.addComponent<GUI::BasicButton>("Play",
        [&]()
        {
            m_menuState     = Menu_State::Attribute;
            m_activeMenu    = &m_statSelectionMenu;
            m_skillPoints   = 10;
            m_stats.reset();
        });

        m_frontMenu.addComponent<GUI::BasicButton>("Exit",
        [&]()
        {
            m_pApplication->popState();
        });

        m_statSelectionMenu.addComponent<GUI::VariableButton>("Charm",
        [&]()
        {
            if (m_skillPoints > 0)
            {
                m_stats.charm++;
                m_skillPoints--;
            }
        },
        [&]()
        {
            if (m_stats.charm > 0)
            {
                m_stats.charm--;
                m_skillPoints++;
            }
        });

        m_statSelectionMenu.addComponent<GUI::VariableButton>("Intelligence",
        [&]()
        {
            if (m_skillPoints > 0)
            {
                m_stats.intelligence++;
                m_skillPoints--;
            }
        },
        [&]()
        {
            if (m_stats.intelligence > 0)
            {
                m_stats.intelligence--;
                m_skillPoints++;
            }
        });

        m_statSelectionMenu.addComponent<GUI::BasicButton>("Back",
        [&]()
        {
            m_menuState = Menu_State::Front;
            m_activeMenu = &m_frontMenu;
        });


    }


}
