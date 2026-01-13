#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/tile.hpp"

using namespace TTE;

TEST_CASE( "Test template for test template", "[template]" )
{
    Tile_Manager My_Tile_Manager;


    auto tile = My_Tile_Manager.create();

    My_Tile_Manager.vec.push_back(tile);
    My_Tile_Manager.vec.push_back(tile);
    My_Tile_Manager.vec.push_back(tile);

    auto entity = My_Tile_Manager.create_entity();

    REQUIRE( My_Tile_Manager.vec.size() == 3 );


}