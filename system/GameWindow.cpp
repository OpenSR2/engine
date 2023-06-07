//
// Created by Mola Mola on 06.06.2023.
//

#include "GameWindow.h"
#include <iostream>
#include <boost/filesystem.hpp>

GameWindow::GameWindow()
= default;

GameWindow::~GameWindow()
= default;

void GameWindow::init()
{
    std::cout << "GameWindow initialization" << std::endl;

    boost::filesystem::path path("/etc/hosts");
    if (boost::filesystem::exists(path)) {
        std::cout << "File exists!" << std::endl;
    } else {
        std::cout << "File does not exist!" << std::endl;
    }
}

void GameWindow::update()
{
    std::cout << "GameWindow update" << std::endl;
}