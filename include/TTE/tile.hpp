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

    // Each time a tile is created the Tile_ID is incremented by 1
    static std::size_t Tile_ID;

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

    // Represents an 8 x 8 block of pixels
    struct Tile
    {
        std::vector<std::unique_ptr<std::vector<Tiny_box>>> tile;
        Vec2<float> pos{0, 0};
        std::size_t tile_id = Tile_ID;

        Tile()
        {
            tile = create_matrix<Tiny_box, std::size_t>(8, 8);
            ++Tile_ID;
        }
    };

    
    // Represents a map of multiple tiles
    struct Tile_map
    {
        std::map<int, std::unique_ptr<Tile>> tile_map;
    };
    
} // End namespace