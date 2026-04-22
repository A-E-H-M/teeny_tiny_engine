#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/tile.hpp"
#include "TTE/common.hpp"
#include <iostream>

using namespace TTE;

TEST_CASE( "Test template for common templates", "[template]" )
{
    auto test = create_matrix<Tiny_box>();
    REQUIRE ( test.size() == 8 );
}