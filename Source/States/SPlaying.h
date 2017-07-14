#ifndef SPLAYING_INCLUDED
#define SPLAYING_INCLUDED

#include "../Application.h"

#include "SBase.h"

class Levels;

namespace State
{
    class StatePlaying : public StateBase
    {
        public:
            StatePlaying(Application& application, Levels& stats);

            void handleInput    ();
            void handleEvent    (sf::Event e);
            void update         (float dt);
            void fixedUpdate    (float dt);
            void draw           (sf::RenderWindow& window);

        private:

    };
}

#endif // SPLAYING_INCLUDED
