#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <array>

#include "SBase.h"
#include "GUIMeni/ColumnMenu.h"

#include "../Effect/Bubbles.h"

#include "../Player/Stats.h"

class Application;

namespace State
{
    class MainMenu : public StateBase
    {
        enum class Menu_State
        {
            Front,
            Attribute
        };

        public:
            MainMenu(Application& app);
            ~MainMenu();

            void handleInput    () override;
            void handleEvent    (sf::Event e) override;
            void update         (float dt) override;
            void fixedUpdate    (float dt) override;
            void draw           (sf::RenderWindow& window) override;

        private:
            void initMenu();

            sf::Music m_menuMusic;
            sf::RectangleShape m_banner;

            std::array<Bubble, 16> m_bubbles;


            GUI::ColumnMenu m_frontMenu;
            GUI::ColumnMenu m_statSelectionMenu;

            sf::Text m_skillPointsDisplay;
            int m_skillPoints = 10;
            Stats m_stats;

            GUI::ColumnMenu* m_activeMenu = &m_frontMenu;

            Menu_State m_menuState = Menu_State::Front;
    };
}

#endif // MAINMENU_H
