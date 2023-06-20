//
// Created by Mola Mola on 19.06.2023.
//

#ifndef SFML_TEST_GAMEOBJECT_H
#define SFML_TEST_GAMEOBJECT_H


class GameObject {
private:
    bool started = false;
public:
    void Start();
    void Update();
    bool isStarted();
};


#endif //SFML_TEST_GAMEOBJECT_H
