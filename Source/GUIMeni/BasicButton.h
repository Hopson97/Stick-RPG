#ifndef BASICBUTTON_INCLUDED
#define BASICBUTTON_INCLUDED

#include "Component.h"

namespace GUI
{
    class BasicButton : public GUI::Component
    {
        public:
            BasicButton();

            void setPosition(const sf::Vector2f& position) override;

            void onUpdate   () override;
            void onDraw     (sf::RenderWindow& window);

        private:
            sf::RectangleShape m_button;

    };
}

#endif // BASICBUTTON_INCLUDED
