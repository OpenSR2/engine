//
// Created by Mola Mola on 21.06.2023.
//

#ifndef OPENSR_RENDERSYSTEM_H
#define OPENSR_RENDERSYSTEM_H


#include "Entity.h"
#include "RenderComponent.h"

class RenderSystem {
public:
    void update(Entity& entity);
};


#endif //OPENSR_RENDERSYSTEM_H
