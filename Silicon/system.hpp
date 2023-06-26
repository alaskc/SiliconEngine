#include <SFML/Graphics.hpp>

#include "graphics.hpp"
#include "input.hpp"
#include "level.hpp"
#include "collision.hpp"

#define Grid_size 40

namespace Silicon {
    using std::string;

    const std::string LEVELS_PATH = "res/level/";
    const std::string TEXTURES_PATH = "res/textures/";

    sf::Vector2f fixCoords(sf::Vector2f vec) {
        sf::Vector2f a;
        a.x = vec.x / 2;
        a.y = vec.y / 2;

        return a;
    }

    class ListObjects {
        public:

        std::vector<Sprite>objects;
        std::vector<std::string>object_ids;
        std::vector<sf::Vector2i>grid_indexes;
    };

    class World : public ListObjects {
        int m_grid_size_x = Grid_size;
        int m_grid_size_y = Grid_size;

        public:

        const sf::Vector2i getGridMaxiumSize() {
            sf::Vector2i g;
            g.x = m_grid_size_x;
            g.y = m_grid_size_y;

            return g;
        }

        float x_camera_shift;
        float y_camera_shift;

        void loadObject(Sprite Object,int x,int y,string id="OBJ-") {
            if (id == "OBJ-") {
                id += std::to_string(objects.size());
            }

            objects.push_back(Object);
            object_ids.push_back(id);

            sf::Vector2i v; v.x = x; v.y = y;

            grid_indexes.push_back(v);
        }

        void removeObject(string id) {
            for (const auto& i : object_ids) {
                int index = 0;
                if (i == id) {
                    objects.erase(objects.begin() + index);
                    object_ids.erase(object_ids.begin() + index);
                    grid_indexes.erase(grid_indexes.begin() + index);

                    return;
                }
                index++;
            }
        }

        void loadlevel(std::string name) {
            name = LEVELS_PATH + name;

            for (const auto& i : getLevel(name)) {
                
            }
        }
    };

    class SC_Instance : public World {
        public:

        Sprite player;
        bool player_load;

        void render(sf::RenderWindow* w, bool applyCameraShift = false) {
            int index = 0;

            for (auto& i : objects) {
                if (applyCameraShift) {
                    Sprite j = i;
                    int x = 0, y = 0;
                    x = getGridMaxiumSize().x * grid_indexes.at(index).x + x_camera_shift;
                    y = getGridMaxiumSize().y * grid_indexes.at(index).y + y_camera_shift;
                    
                    j.setPosition(x,y);

                    w->draw(j);
                } else {
                    float x = getGridMaxiumSize().x * grid_indexes.at(index).x;
                    float y = getGridMaxiumSize().y * grid_indexes.at(index).y;

                    i.setPosition(x, y);

                    w->draw(i);
                }

                index++;
            }
        }

    };
};