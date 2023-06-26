#include <iostream>
#include <vector>
#include <fstream>

#include "variable.hpp"

namespace Silicon {

    // If a syntax error is encountered then it will return an empty vector.
    std::vector<std::string> getLevel(std::string line) {

        std::vector<std::string>params,leveld;
        bool image_found = false;
        bool x_found = false;
        bool y_found = false;
        std::string fileimage;

        // Fully syntax fixing level data interpreter.
        for (std::string i : tools::seperate(line,' ')) {
            if (tools::is_int(i)) {
                if (!x_found) {
                    params.push_back(i);
                    x_found = true;
                } else if (!y_found) {
                    params.push_back(i);
                    y_found = true;
                }
            } else {
                if (!image_found) {
                    tools::strip(i,'"');
                    fileimage = i;
                }
            }
        }

        if (!x_found , !y_found , !image_found) {
            leveld.clear();
            return leveld;
        }

        for (std::string i : params) {
            leveld.push_back(i);
        }
        return leveld;
        
    }

    std::vector<std::vector<std::string>>getLevelContents(std::string path) {
        
    }
}