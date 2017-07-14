#include "ColumnMenu.h"

namespace GUI
{
    ColumnMenu::ColumnMenu(float startY)
    :   m_baseComponentX    (BASE_WIDTH / 2)
    ,   m_yPosition         (startY)
    {

    }

    void ColumnMenu::update(const sf::RenderWindow& window)
    {
        for (auto& comp : m_components)
        {
            comp->update(window);
        }
    }

    void ColumnMenu::draw(sf::RenderWindow& window)
    {
        for (auto& comp : m_components)
        {
            comp->draw(window);
        }
    }

    void ColumnMenu::initComponent(Component& comp)
    {
        comp.setPosition({m_baseComponentX,
                          m_yPosition});

        m_yPosition += BASE_HEIGHT * 1.5;
    }

}
