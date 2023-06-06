#include <SFML/Window/Keyboard.hpp>

namespace Silicon {
    bool checkKeyPress(sf::Keyboard::Key key) {
        using sf::Keyboard;

        return Keyboard::isKeyPressed(key);
    }
};