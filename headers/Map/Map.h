#ifndef OOP_RGZ_MAP_H
#define OOP_RGZ_MAP_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "matrix/matrix.h"

enum class mapObject {
    Empty, Border, HealthBooster, Clone
};

class Map : public matrix::Matrix<mapObject> {
public:
    Map() = default;

    Map(size_t m, size_t n);

    static Map readFromTextFile(const std::string &filename);

    void draw (sf::RenderWindow& window) const;

    static bool isEntity(mapObject object);

private:
    static std::pair<size_t, size_t> getSizeOfFile(const std::string& filename);
};


#endif //OOP_RGZ_MAP_H
