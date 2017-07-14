#ifndef CLICKABLERECTANGLE_H_INCLUDED
#define CLICKABLERECTANGLE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <functional>

class ClickableRectangle : public sf::RectangleShape
{
    public:
        ClickableRectangle(std::function<void(void)> onClick,
                           std::function<void(void)> onRollover);

        void testForInteration(sf::RenderWindow& window);

    private:

};

#endif // CLICKABLERECTANGLE_H_INCLUDED
