#include "ColumnMenu.h"

namespace GUI
{
    ColumnMenu::ColumnMenu()
    {

    }

    void ColumnMenu::update()
    {
        for (auto& comp : m_components)
        {
            comp->update();
        }
    }

    void ColumnMenu::draw(sf::RenderWindow& window)
    {
        for (auto& comp : m_components)
        {
            comp->draw(window);
        }
    }
}
