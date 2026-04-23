#pragma once

#include <string>
#include <vector>
#include <memory>
#include <array>

#include <SFML/Graphics.hpp>

#include <TTE/vec2.hpp>
#include <TTE/common.hpp>

namespace TTE 
{

    // Represents a pixel, color as RGB
    struct Tiny_box
    {
        sf::RectangleShape tiny_box;
        sf::Color color;

        Tiny_box(){};
        
        Tiny_box(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) 
            : color(red, green, blue, alpha)
        {
            tiny_box.setFillColor(color);
        }
        
    };

    enum class Colors
    {
        WHITE,
        LIGHT_GREY,
        DARK_GREY,
        BLACK
    };

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

    template

    // Represents a map of all tiles
    class Tile_map
    {
        std::vector<Tile> tile_map;
    };
    */
} // End namespace