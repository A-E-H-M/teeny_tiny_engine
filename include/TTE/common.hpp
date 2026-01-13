#pragma once

#include <memory>
#include <iostream>
#include <vector>

#include "vec2.hpp"

namespace TTE
{

    template <class T, typename V>
    void set_position(T& element, V new_pos)
    {
        element.element_properties->pos.x = new_pos.x; 
        element.element_properties->pos.y = new_pos.y;
    }

    template <class T>
    struct Create_Policy
    {
        T* create()
        {
            return new T;
        }
    };

    template <template <class> class Creation_Policy>
    struct Manager : public Creation_Policy<int>
    {
            std::vector<int*> vec;
            std::vector<char*> vec_2;

            char* create_entity()
            {
                auto entity = Creation_Policy<char>().create();
                return entity;
            }
    };

} // End namespace