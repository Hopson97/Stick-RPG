#include "SMainMenu.h"

#include <iostream>

#include "Application.h"

#include "../ResourceManager/ResourceHolder.h"

namespace State
{
    //bubble :o
    Bubble::Bubble()
    {

    }

    void Bubble::update()
    {

    }

    void Bubble::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
    }

    void Bubble::reset()
    {

    }



    MainMenu::MainMenu(Application& app)
    :   StateBase   (app)
    {
        m_menuMusic.openFromFile("res/music/menu.ogg");
        m_menuMusic.play();

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

    }

    void MainMenu::fixedUpdate(float dt)
    {

    }

    void MainMenu::draw(sf::RenderWindow& window)
    {
        window.draw(m_banner);
    }

}
