#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/tile.hpp"
#include "TTE/common.hpp"
#include <iostream>

using namespace TTE;

TEST_CASE( "Tests common templates", "[template]" )
{
    auto test_matrix_square = create_matrix_square<Tiny_box, 8>();
    REQUIRE ( test_matrix_square.size() == 8 );
    REQUIRE ( test_matrix_square[0]->at(0).x == 9 );
}