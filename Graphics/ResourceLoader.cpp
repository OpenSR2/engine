//
// Created by Mola Mola on 18.06.2023.
//

#include <stdexcept>
#include "ResourceLoader.h"
#include <filesystem>
#include <string>


std::vector<sf::Texture> ResourceLoader::loadTextures(const std::string &asset_path, const std::string prefix) {

    std::vector<sf::Texture> frames;
    for (int i = 0; i <= countTexturesInPath(asset_path)-1; i++) {

        sf::Texture texture;
        std::string filename = asset_path + "/" + prefix + formatNumber(i, 3) + ".png";
        if (!texture.loadFromFile(filename)) {
            // Handle error if unable to load the frame
            throw std::runtime_error("An error while loading texture " + filename);
        }
        frames.push_back(texture);
    }

    return frames;
}


sf::Texture ResourceLoader::loadTexture(const std::string &asset_path) {
    sf::Texture texture;
    if (texture.loadFromFile(asset_path)) {
        return texture;
    } else {
        throw std::runtime_error("An error while loading texture " + asset_path);
    }
}

std::string ResourceLoader::formatNumber(int number, int formatLength) {
    std::string formattedNumber = std::to_string(number);
    return std::string(formatLength - formattedNumber.length(), '0') + formattedNumber;
}

int ResourceLoader::countTexturesInPath(const std::string &asset_path) {
    int count = 0;

    for (const auto& entry : std::filesystem::directory_iterator(asset_path)) {
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            ++count;
        }
    }

    return count;
}
