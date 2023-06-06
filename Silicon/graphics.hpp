#include <SFML/Graphics.hpp>

namespace Silicon {
    // sf::Sprite and sf::Texture bundled are together because sf::Sprite only holds a pointer to sf::Texture
    // and this can break or complicate things.
    class Sprite : public sf::Sprite {
        sf::Texture texture;

        public:

        // Unrestricted access to the texture.
        sf::Texture* modifyTexture() {
            return &texture;
        }

        bool loadTexture(std::string path) {
            if (!texture.loadFromFile(path)) {
                return false;
            }

            setTexture(texture);

            return true;
        }
    };

    // Standalone Animation class.
    class animator {
        std::vector<sf::Texture>cycle;
        std::vector<std::string>ids;

        bool running = true;

        public:

        bool loadAnimationSprite(std::string path) {
            sf::Texture t;

            if (!t.loadFromFile(path)) {
                return false;
            }

            cycle.push_back(t);

            return true;
        }

        void stop() {
            running = false;
        }

        void run(float delayMiliseconds,Sprite *sp) {
            while(running) {
                for (auto& i : cycle) {
                    sp->setTexture(i);

                    sf::sleep(sf::milliseconds(delayMiliseconds));
                }
            }

            running = true;
        }
    };
};