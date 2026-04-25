#pragma once

#include <memory>
#include <vector>
#include <array>

#include <TTE/vec2.hpp>

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

    /* Generates a grid of type T using a map with both length and width as paramaters.
    * The map starts at the top left, continues right, then goes down, then proceeds left again.
    */
   /*
    template <typename T, typename SZ>
    std::map<std::unique_ptr<T>> create_spatial_grid(SZ length, SZ width, SZ spatial_dif_x, SZ spatial_dif_y)
    {
        std::map<std::unique_ptr<T>> temp_map;

        for (int i = 0; i < length; ++i)
        {
            std::vector<T> temp(width);
            matrix.push_back(std::make_unique<std::vector<T>>(temp));
        }

        return matrix;
    }
    */

    // Concept to be enforce is the type has to have a default constructor with no parameters
    // template parameter T is for the type you would like to create a matrix of
    // template parameter SZ is for the size of a 2D matrix (8 x 8)
    template <typename T, typename SZ>
    std::vector<std::unique_ptr<std::vector<T>>> create_matrix(SZ length, SZ width)
    {
        std::vector<std::unique_ptr<std::vector<T>>> matrix;

        for (int i = 0; i < length; ++i)
        {
            std::vector<T> temp_matrix(width);
            matrix.push_back(std::make_unique<std::vector<T>>(temp_matrix));
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