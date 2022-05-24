#include "Level.h"

Map Map::readFromTextFile(const std::string &filename) {
    static std::map<char, mapObject> conformity = {
            {' ', mapObject::Empty},
            {'B', mapObject::Border},
    };

    auto size = getSizeOfFile(filename);
    Map result(size.first, size.second);

    std::ifstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < result.rows(); ++i) {
            std::string s;
            std::getline(file, s);
            for (size_t j = 0; j < s.size(); ++j) {
                result[i][j] = conformity[s[j]];
//                std::cout << s[j];
            }
//            std::cout << std::endl;
        }
        file.close();
    } else
        throw std::runtime_error("File " + filename + " is not found!");

    return result;
}

void Map::draw(sf::RenderWindow &window) const {
    sf::RectangleShape rectangle(sf::Vector2f(SETTINGS.TILE_SIZE, SETTINGS.TILE_SIZE));
    for (int i = 0; i < this->rows(); i++ ) {
        for (int j = 0; j < this->cols(); j++) {
            switch ((*this)[i][j]) {
                case mapObject::Empty:
                    continue;

                case mapObject::Border:
                    rectangle.setFillColor(sf::Color::Black);
                    break;
            }
            rectangle.setPosition(j * SETTINGS.TILE_SIZE, i * SETTINGS.TILE_SIZE);
            window.draw(rectangle);
        }
    }
}

std::pair<size_t, size_t> Map::getSizeOfFile(const std::string &filename) {
    std::ifstream file(filename);

    size_t m = 0, n = 0;
    if (file.is_open()) {
        std::string s;
        while (!file.eof()) {
            std::getline(file, s);
            m++;
        }
        n = s.size();
        file.close();
    } else
        throw std::runtime_error("File " + filename + " is not found!");

    return std::make_pair(m, n);
}
