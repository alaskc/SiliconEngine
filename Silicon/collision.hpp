#include <SFML/Graphics.hpp>

namespace Silicon {
    // Checks if object1 is colliding with object 2.
    bool isColliding(sf::Sprite object1,sf::Sprite object2) {
        if (object1.getGlobalBounds().intersects(object2.getGlobalBounds())) {
            return true;
        }
        return false;
    }
}