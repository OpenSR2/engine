//
// Created by Mola Mola  on 21.06.2023.
//


#include "Entity.h"

template<typename ComponentType>
void Entity::addComponent(ComponentType &&component) {
    // Deduce the type of the component
    using ComponentT = std::remove_reference_t<ComponentType>;

    // Get the type index of the component
    std::type_index componentTypeIndex(typeid(ComponentT));

    // Store the component in the unordered map
    components[componentTypeIndex] = std::forward<ComponentType>(component);
}
template <typename ComponentType>
ComponentType* Entity::getComponent() {
    // Deduce the type of the component
    using ComponentT = std::remove_pointer_t<ComponentType>;

    // Get the type index of the component
    std::type_index componentTypeIndex(typeid(ComponentT));

    // Find the component in the unordered map
    auto it = components.find(componentTypeIndex);

    if (it != components.end()) {
        // Return a pointer to the component
        return &std::any_cast<ComponentT&>(it->second);
    }

    // Component not found
    return nullptr;
}