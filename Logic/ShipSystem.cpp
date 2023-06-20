//
// Created by Mola Mola on 21.06.2023.
//

#include "ShipSystem.h"


void ShipSystem::update(Entity &entity) {
    ShipComponent* shipComponent = entity.getComponent<ShipComponent>();
    if (shipComponent) {
        // Handle ship behavior
        // ...
    }
}
