#include "Component.h"

namespace GUI
{
    void Component::update()
    {
        onUpdate();
    }

    void Component::draw(sf::RenderWindow& window)
    {
        onDraw();
    }

}
