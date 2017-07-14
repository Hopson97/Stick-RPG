#ifndef COLUMNMENU_H_INCLUDED
#define COLUMNMENU_H_INCLUDED

#include <vector>
#include <memory>

#include "Component.h"
#include "../Application.h"

namespace GUI
{
    constexpr static int    BASE_WIDTH  = WINDOW_WIDTH / 2,
                            BASE_HEIGHT = 50;

    class ColumnMenu
    {
        public:
            ColumnMenu();

            void update();
            void draw  (sf::RenderWindow& window);

            template<typename T, typename... Args>
            void addComponent(Args&&... args)
            {
                m_components.push_back(std::make_unique<T>(std::forward<Args>(args)...));
            }

        private:
            std::vector<std::unique_ptr<GUI::Component>> m_components;
    };
}

#endif // COLUMNMENU_H_INCLUDED
