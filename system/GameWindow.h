//
// Created by Mola Mola on 06.06.2023.
//

#ifndef OPENSR2_GAMEWINDOW_H
#define OPENSR2_GAMEWINDOW_H


class GameWindow
{
public:
    GameWindow();
    virtual ~GameWindow();

    virtual void init();
    virtual void update();
    // Другие виртуальные функции, которые можно переопределить в игре
};


#endif //OPENSR2_GAMEWINDOW_H
