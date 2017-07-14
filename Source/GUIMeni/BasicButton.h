#ifndef BASICBUTTON_INCLUDED
#define BASICBUTTON_INCLUDED

#include "Component.h"
#include "../SpecialSprite/ClickableRectangle.h"

namespace GUI
{
    class BasicButton : public GUI::Component
    {
        public:
            BasicButton(std::string&& label, std::function<void(void)> onClick);

            void setPosition(const sf::Vector2f& position) override;

            void onUpdate   (const sf::RenderWindow& window) override;
            void onDraw     (sf::RenderWindow& window) override;

        private:
            void onTouch();
            void onNoTouch();


            ClickableRectangle m_button;
            sf::Text m_label;

    };
}

#endif // BASICBUTTON_INCLUDED
