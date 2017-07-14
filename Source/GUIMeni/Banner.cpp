
#include "Banner.h"

namespace GUI
{
    Banner::Banner(const sf::Texture& texture, const sf::Vector2f& size)
    {
        m_bannerSprite.setTexture(&texture);
        m_bannerSprite.setSize(size);
    }

    void Banner::setPosition(const sf::Vector2f& position)
    {
        m_bannerSprite.setPosition({0, position.y});
    }

    void Banner::onDraw(sf::RenderWindow& window)
    {

    }
}
