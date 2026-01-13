#pragma once

#include <string>
#include <vector>
#include <memory>

//#include <SFML/Graphics/RectangleShape.hpp>

#include <TTE/vec2.hpp>
#include <TTE/common.hpp>

namespace TTE 
{
    typedef Manager<Create_Policy> Tile_Manager;

    /*enum class Colors
    {
        WHITE,
        LIGHT_GREY,
        DARK_GREY,
        BLACK
    };

    // Represents a pixel, color as RGB
    struct Tiny_box
    {
        sf::RectangleShape tiny_box;

        Tiny_box(std::uint8_t red = 100, std::uint8_t green = 90, std::uint8_t blue = 280, std::uint8_t alpha = 255) :
        {
            tiny_box.setSize(Vec2(100, 50));
            tiny_box.setFillColor(sf::Color(red, blue, green, alpha));
        };
    };

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

    class Tile_manager
    {
        std::vector<std::unique_ptr<Tile>> Tile_map_grid;
        
        std::unique_ptr<Tile_map> create_tile_map();
        std::unique_ptr<Tile> create_tile();

        void update_tile_map(const Tile_map* title_map_ptr);
        void update_tile(const Tile* tile_ptr);
    };
    */
} // End namespace