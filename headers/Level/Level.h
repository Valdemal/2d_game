#ifndef OOP_RGZ_LEVEL_H
#define OOP_RGZ_LEVEL_H

#include <fstream>
#include <map>
#include <SFML/Graphics.hpp>
#include "matrix/matrix.h"
#include "../Settings.h"

enum class mapObject {
    Empty, Border
};

class Map : public matrix::Matrix<mapObject> {
public:
    Map() = default;

    Map(size_t m, size_t n) : matrix::Matrix<mapObject>(m, n) {};

    static Map readFromTextFile(const std::string &filename);

    void draw (sf::RenderWindow& window) const;

private:
    static std::pair<size_t, size_t> getSizeOfFile(const std::string& filename);
};
//
//class Level {
//private:
//    Map map;
//public:
//    explicit Level(const std::string &mapFileName) {
//        map = Map::readFromTextFile(mapFileName);
//    }
//
//    Map &getMap() { return map; }
//};


#endif //OOP_RGZ_LEVEL_H
