//
// Created by Mola Mola on 19.06.2023.
//

#ifndef SFML_TEST_GALAXY_H
#define SFML_TEST_GALAXY_H


#include <vector>
#include "GameObject.h"
#include "Entity.h"
#include "RenderSystem.h"
#include "PlanetSystem.h"
#include "ShipSystem.h"

class Galaxy {
public:
    void addStar(Entity& star) {
        // Add the star entity to the galaxy
        // ...
    }

    void update() ;

private:
    std::vector<Entity> stars;
    RenderSystem renderSystem;
    PlanetSystem planetSystem;
    ShipSystem shipSystem;
};


#endif //SFML_TEST_GALAXY_H
