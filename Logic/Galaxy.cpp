//
// Created by Mola Mola on 19.06.2023.
//

#include "Galaxy.h"


void Galaxy::update(){
    // Loop over the stars and update systems
    for (Entity& star : stars) {
        renderSystem.update(star);
        planetSystem.update(star);
        shipSystem.update(star);
    }
}

