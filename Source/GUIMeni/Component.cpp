#include "Component.h"

namespace GUI
{
    void Component::update(const sf::RenderWindow& window)
    {
        onUpdate(window);
    }

    void Component::draw(sf::RenderWindow& window)
    {
        onDraw(window);
    }

}
