#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>

#define LevelPath std::string("res/levels/")
#define LevelExtension std::string(".world")

namespace Silicon {

    namespace tools {
        std::vector<std::string>seperate(std::string str,char c) {
            std::vector<std::string>data;
            std::string d;

            while(str.back() == c) {
                str.pop_back();
            }

            str += c;
            int size = str.size();

            for (int i = 0;i < size;i++) {
                if (str.at(i) == c) {
                    if (i < size) {
                        i++;
                    }
                    data.push_back(d);
                    d.clear();

                    if (i >= size) {
                        break;
                    }
                }
                d += str.at(i);
            }

            return data;
        }
    }

    // Return value meanings:
    // True = Syntax is fine.
    // False = Syntax is invalid.
    bool syntax_levelcheck(int textures,std::string line) {
        using std::string,std::vector;

        bool error = true;
        int spaces;

        for (char i : line) {
            if (i == ' ') {
                spaces++;
            }
        }

        if (spaces != 3) {
            return false;
        } else if (spaces < 3 || spaces > 3) {
            return false;
        }

        vector<string>tester = tools::seperate(line,' ');
    }

    // This will return all listed textures inside the level file.
    //   ERRORS:
    //               NOTE: Errors are returned only in the first index. The data is after the first index.
    //   "NULL" Means syntax error.
    std::vector<std::string> syntax_listTextures(std::string line) {
        bool error = true;
        std::vector<std::string>data;
        data.push_back("STARTLIST");

        if (line.at(0) == 0x4A) {
            std::string string;
            int pointer = 0; 

            bool encap = false;

            for (char i : line) {
                if (pointer == line.size()) {
                    if (line.at(pointer) == ';') {
                        error = false;
                        break;
                    }
                
                    if (line.at(pointer) == '\"') {
                        break;
                    }

                    if (line.at(pointer) == ',') {
                        break;
                    }
                } 

                if (i == '\"') {
                    if (encap) {
                        data.push_back(string);
                        string.clear();
                        encap = false;
                    }
                }

                if (i == '\"') {
                    encap = true;
                }

                if (encap) {
                    string += i;
                }
            }

            if (error) {
                data.clear();
                data.push_back("NULL");
                return data;
            }

            data.push_back("LISTSTOP");

            return data;
        }
    }

    // This function will return a vector that contains simplified level data.
    //  ERRORS:
    //               NOTE: Errors are returned only in the first index. The data is after the first index.
    //   "No bytes" mean the file is empty.
    //   "NULL" Means syntax error.
    //   "ERROR" File does not exist!
    std::vector<std::string> getLevelContents(std::string filename) {
        std::string path = LevelPath + filename + LevelExtension;

        std::ifstream file; file.open(path);
        std::vector<std::string>data;
        using namespace std::filesystem;

        if (!exists(path)) {
            data.push_back("ERROR");
        }

        if (file.eof()) {
            data.push_back("No bytes");
            return data;
        }
        
        data.push_back("NoErr");
        std::string l; file >> l;
        int ep = 0;

        for (std::string i : syntax_listTextures(l)){
            if (i == "NULL" && ep == 0) {
                data.push_back("NULL");
                return data;
            }
            data.push_back(i);
        }



    }
}