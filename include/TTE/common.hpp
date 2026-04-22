#pragma once

#include <memory>
#include <vector>
#include <array>

#include "vec2.hpp"

namespace TTE
{

    template <typename T>
    std::unique_ptr<T> create_new()
    {
        return std::make_unique<T>();
    }

    /*
    template <typename T>
    void move_to_vec(std::vector<T> t, std::unique_ptr<T> ptr)
    {
        t.push_back(std::move(ptr));
    }
    */

    template <typename T>
    std::vector<std::unique_ptr<std::vector<T>>> create_matrix()
    {
        std::vector<std::unique_ptr<std::vector<T>>> matrix;

        for (int i = 0; i < 8; ++i)
        {
            matrix.push_back(std::make_unique<std::vector<T>>());
        }

        return matrix;
    }

    template <typename T>
    struct Manager
    {
        std::unique_ptr<T> (*create)() = &create_new<T>;
        //void (*add_to_manager)(std::vector<T>, std::unique_ptr<T>) = &move_to_vec<T>;

        std::vector<std::unique_ptr<T>> vec;
    };

} // End namespace