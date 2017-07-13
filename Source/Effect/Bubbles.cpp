#include "Bubbles.h"

#include "../Util/Random.h"

#include "../ResourceManager/ResourceHolder.h"

constexpr static int    SIZE            = 25,
                        MIN_LIFE_SECS   = 4,
                        MAX_LIFE_SECS   = 8;

//bubble :o
Bubble::Bubble()
{
    m_sprite.setOutlineThickness(1);
    m_sprite.setOutlineColor(sf::Color::Black);
    reset();
}

void Bubble::update(float dt)
{
    constexpr auto p = 3.14159f / 2.0f;

    m_sprite.move(sin(m_lifeTime.getElapsedTime().asSeconds()) * dt, -ySpeed * dt);
    m_sprite.setTexture(&ResourceHolder::getTexure("bubble"));

    if (m_lifeTime.getElapsedTime() > m_deathTime)
    {
        reset();
    }

    auto time       = m_lifeTime.getElapsedTime().asSeconds();
    auto deathTime  = m_deathTime.asSeconds();
    auto fade  = (std::sin((time * (p / deathTime)) * 2 ));
    auto alpha = fade * 255;
    auto c = sf::Color::White;
    auto o = sf::Color::Black;
    c.a = alpha;
    o.a = alpha;
    m_sprite.setFillColor   (c);
    m_sprite.setOutlineColor(o);
}

void Bubble::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

void Bubble::reset()
{
    m_sprite.setRadius(Random::get().floatInRange(SIZE/ 4, SIZE));
    m_deathTime     =   sf::seconds(Random::get().intInRange(MIN_LIFE_SECS, MAX_LIFE_SECS));
    ySpeed          =   Random::get().intInRange(  m_sprite.getRadius() - 5,
                                                    m_sprite.getRadius() + 5);

    auto x = Random::get().floatInRange(0, 1280 - SIZE);
    auto y = Random::get().floatInRange(SIZE, 350);

    m_sprite.setPosition({x, y});

    m_lifeTime.restart();
}
