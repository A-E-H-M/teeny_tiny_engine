#pragma once

#include <string>
#include <vector>
#include <memory>

enum class Colors
{
    WHITE,
    LIGHT_GREY,
    DARK_GREY,
    BLACK
};

struct Tiny_box
{
    // set default value for color
    long long hex_color;
    int ID;
};

class Tile
{
    std::vector<std::unique_ptr<Tiny_box>> tile;

    int Tile_ID;

};

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