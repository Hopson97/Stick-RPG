#include "SMainMenu.h"

#include <iostream>

#include "Application.h"

#include "../ResourceManager/ResourceHolder.h"

namespace State
{
    MainMenu::MainMenu(Application& app)
    :   StateBase   (app)
    {
        m_menuMusic.openFromFile("res/music/menu.ogg");
        m_menuMusic.play();

        m_banner.setSize({
                         app.getWindow().getSize().x,
                         200});
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

    }

    void MainMenu::fixedUpdate(float dt)
    {

    }

    void MainMenu::draw(sf::RenderWindow& window)
    {
        window.draw(m_banner);
    }

}
