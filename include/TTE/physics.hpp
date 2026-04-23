#pragma once

#include <memory>
#include <vector>

#include <TTE/vec2.hpp>

namespace TTE
{

    template <typename T>
    const auto get_position(const T& element)
    {
        return element->pos;
    }

    template <typename T, typename V>
    const auto set_position(const T& element_ptr, const V new_pos)
    {
        return element_ptr->pos += new_pos;
    }

} // End of namespace