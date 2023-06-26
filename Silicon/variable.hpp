#include <iostream>
#include <vector>

namespace tools {
        bool is_int(std::string string) {
            char allowed[] = {'-','1','2','3','4','5','6','7','8','9','0'};

            for (char i : string) {
                bool invalid_character = true;

                for (int j = 0;j < 11;j++) {
                    if (i == allowed[j]) {
                        invalid_character = false;
                        break;
                    }
                }

                if (invalid_character) {
                    return false;
                }
            }

            return true;
        }

        int contains_s(std::string text,char c) {
            int instances = 0;
            for (char i : text) { 
                if (i == c) {
                    instances++;
                }
            }
            return instances;
        }

        bool contains(std::string text,char c) {
            bool yes = false;
            for (char i : text) { 
                if (i == c) {
                    yes = true;
                }
            }
            return yes;
        }

        void strip(std::string &text,char c) {
            std::string final;
            
            for (char i : text) {
                if (i != c) {
                    final += i;
                }
            }

            text = final;
        }

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