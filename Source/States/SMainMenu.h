#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <array>

#include "SBase.h"

class Application;

namespace State
{
        class Bubble
        {
            public:
                Bubble      ();
                void update (float dt);
                void draw   (sf::RenderWindow& window);

            private:
                void reset();

                sf::RectangleShape m_sprite;


                sf::Clock   m_lifeTime;
                sf::Time    m_deathTime;

                float ySpeed;

                float m_normalisedCycle;
        };

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

            std::array<Bubble, 18> m_bubbles;
    };
}

#endif // MAINMENU_H
