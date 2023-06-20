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
    void addComponent(ComponentType&& component){
        // Deduce the type of the component
        using ComponentT = std::remove_reference_t<ComponentType>;

        // Get the type index of the component
        std::type_index componentTypeIndex(typeid(ComponentT));

        // Store the component in the unordered map
        components[componentTypeIndex] = std::forward<ComponentType>(component);
    };

    // Get component of the given type
    template <typename ComponentType>
    ComponentType* getComponent(){
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
    };

private:
    std::unordered_map<std::type_index, std::any> components;
};


#endif //OPENSR_ENTITY_H
