#pragma once

#include <memory>
#include <vector>

#include "vec2.hpp"

namespace TTE
{

    template <typename T, typename V>
    Vec2<V> get_position(std::unique_ptr<T>& element)
    {
        return element->pos;
    }

    template <typename T, typename V>
    void set_position(std::unique_ptr<T>& element_ptr , Vec2<V> new_pos)
    {
        element_ptr->pos += new_pos;
    }

    template <typename T, typename V>
    Vec2<V> get_updated_position(std::unique_ptr<T>& element, Vec2<V> new_pos)
    {
        new_pos += element->pos;
        return new_pos;
    }

} // End of namespace