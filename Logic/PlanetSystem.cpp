//
// Created by Mola Mola on 21.06.2023.
//

#include "PlanetSystem.h"

void PlanetSystem::update(Entity &entity)  {
    PlanetComponent* planetComponent = entity.getComponent<PlanetComponent>();
    if (planetComponent) {
        // Handle planet logic
        // ...
    }
}