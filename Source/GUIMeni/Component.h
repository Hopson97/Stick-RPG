#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace GUI
{
    class Component
    {
        public:
            void update();
            void draw  (sf::RenderWindow& window);

            virtual void setPosition(const sf::Vector2f& position) = 0;

        private:
            virtual void onUpdate(){}
            virtual void onDraw  (){}
    };
}

#endif // COMPONENT_H_INCLUDED
