#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <array>

#include "SBase.h"

#include "GUIMeni/BasicButton.h"
#include "GUIMeni/ColumnMenu.h"

#include "../Effect/Bubbles.h"

class Application;

namespace State
{
    class MainMenu : public StateBase
    {
        public:
            MainMenu(Application& app);
            ~MainMenu();

            void handleInput    () override;;
            void handleEvent    (sf::Event e) override;;
            void update         (float dt) override;;
            void fixedUpdate    (float dt) override;;
            void draw           (sf::RenderWindow& window) override;

        private:
            sf::Music m_menuMusic;
            sf::RectangleShape m_banner;

            std::array<Bubble, 16> m_bubbles;

            GUI::ColumnMenu m_frontMenu;
    };
}

#endif // MAINMENU_H
