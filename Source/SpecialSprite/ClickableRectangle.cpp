#include "ClickableRectangle.h"



ClickableRectangle::ClickableRectangle(std::function<void(void)>onClick,
                                       std::function<void(void)>onRollover,
                                       std::function<void(void)>onNoTouch)
:   m_onClick       (onClick)
,   m_onRollover    (onRollover)
,   m_onNoTouch     (onNoTouch)

{

}

void ClickableRectangle::testForInteration(const sf::RenderWindow& window)
{
    sf::Vector2f pos((float)sf::Mouse::getPosition(window).x,
                     (float)sf::Mouse::getPosition(window).y);

    if (getGlobalBounds().contains(pos))
    {
        m_onRollover();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_onClick();
        }
    }
    else
    {
        m_onNoTouch();
    }
}
