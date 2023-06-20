//
// Created by Mola Mola on 21.06.2023.
//

#include "RenderSystem.h"

void RenderSystem::update(Entity &entity)  {
    RenderComponent* renderComponent = entity.getComponent<RenderComponent>();
    if (renderComponent) {
        // Render the entity
        // ...
    }
}