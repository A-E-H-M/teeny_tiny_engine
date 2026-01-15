#pragma once

#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <TTE/vec2.hpp>
#include <TTE/common.hpp>

namespace TTE 
{


    /*enum class Colors
    {
        WHITE,
        LIGHT_GREY,
        DARK_GREY,
        BLACK
    };
*/

    // Represents a pixel, color as RGB
    struct Tiny_box
    {
        sf::RectangleShape tiny_box;

        int x {9};

        //Tiny_box(std::uint8_t red = 100, std::uint8_t green = 90, std::uint8_t blue = 280, std::uint8_t alpha = 255) :
        //{
            //tiny_box.setSize(Vec2(100, 50));
            //tiny_box.setFillColor(sf::Color(red, blue, green, alpha));
        //};
    };

    using Tile_Manager = Manager<Tiny_box>;
/*
    // Represents an 8 x 8 block of pixels
    class Tile
    {
        std::vector<Tiny_box> tile_row;

        int Tile_ID;
        Tile() :
        {
            for (int 0 = i; i < 8; i++)
            {
                tile_row.push(new Tiny_box);
            }
        }

    };

    // Represents a map of all tiles
    class Tile_map
    {
        std::vector<Tile> tile_map;
    };
    */
} // End namespace