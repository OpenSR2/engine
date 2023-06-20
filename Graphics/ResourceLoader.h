//
// Created by Mola Mola on 18.06.2023.
//

#ifndef SFML_TEST_RESOURCELOADER_H
#define SFML_TEST_RESOURCELOADER_H


#include <SFML/Graphics/Texture.hpp>

class ResourceLoader {
public:
    static std::vector<sf::Texture> loadTextures(const std::string& asset_path, std::string prefix = "");
    static sf::Texture loadTexture(const std::string& asset_path);
    static std::string formatNumber(int number, int formatLength);

    static int countTexturesInPath(const std::string& asset_path);
};


#endif //SFML_TEST_RESOURCELOADER_H
