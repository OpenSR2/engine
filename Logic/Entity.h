//
// Created by Mola Mola on 21.06.2023.
//

#ifndef OPENSR_ENTITY_H
#define OPENSR_ENTITY_H


#include <unordered_map>
#include <any>
#include <type_traits>
#include <typeindex>

// Entity class
class Entity {
public:
    // Add component to the entity
    template <typename ComponentType>
    void addComponent(ComponentType&& component);

    // Get component of the given type
    template <typename ComponentType>
    ComponentType* getComponent();

private:
    std::unordered_map<std::type_index, std::any> components;
};


#endif //OPENSR_ENTITY_H
