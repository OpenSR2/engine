//
// Created by Mola Mola on 06.06.2023.
//

#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow()
= default;

GameWindow::~GameWindow()
= default;

void GameWindow::init()
{
    std::cout << "GameWindow initialization" << std::endl;
}

void GameWindow::update()
{
    std::cout << "GameWindow update" << std::endl;
}