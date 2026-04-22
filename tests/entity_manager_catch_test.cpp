#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/entity_manager.hpp"

using namespace TTE;

TEST_CASE( "Test template for test template", "[template]" )
{
    Tile_Manager My_Tile_Manager;

    auto tile = My_Tile_Manager.create();
    auto tile_2 = My_Tile_Manager.create();

    My_Tile_Manager.vec.push_back(std::move(tile));
    My_Tile_Manager.vec.push_back(std::move(tile_2));

    REQUIRE( My_Tile_Manager.vec.size() == 2 );
    REQUIRE( My_Tile_Manager.vec[0]->x == 9 );
    REQUIRE( My_Tile_Manager.vec[0] != My_Tile_Manager.vec[1] );

}