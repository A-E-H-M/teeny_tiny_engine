#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <memory>

#include "TTE/physics.hpp"
#include "TTE/vec2.hpp"
#include "TTE/common.hpp"
#include "TTE/button.hpp"

using namespace TTE;

// TODO: Templatize testing

TEST_CASE( "Testing physics templates", "[physics]" )
{
    SECTION("Instantiation, ownership, and initialization")
    {
        // Instantiate with explicit type
        std::unique_ptr<Navigation_button> button_unique_ptr = std::make_unique<Navigation_button>();
        REQUIRE( button_unique_ptr != nullptr );

        // Instantiation with type deduction
        auto button_unique_ptr_2 = std::make_unique<Navigation_button>();
        REQUIRE( button_unique_ptr_2 != nullptr );

        // TODO: Add checks for initialization defaults
    }

    SECTION("Member Functions")
    {
        auto button_unique_ptr = std::make_unique<Navigation_button>();

        auto button_1 = get_position(button_unique_ptr);
        REQUIRE( button_1 == 0 );

        auto button_2 = set_position(button_unique_ptr, Vec2<int>(45, 9));
        REQUIRE( button_2 == 45 );

    }

}