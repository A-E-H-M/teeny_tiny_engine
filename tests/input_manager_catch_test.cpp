#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/input_manager.hpp"
#include "TTE/button.hpp"

using namespace TTE;

// Rewrite as template test case

TEST_CASE( "Template test for creating navigation buttons", "[template]" )
{
    Navigation_Buttons nav_buttons;
    
    auto button = nav_buttons.create();
    nav_buttons.vec.push_back(std::move(button));
    REQUIRE( nav_buttons.vec.size() == 1 );

    auto button_2 = create_new<Navigation_button>();
    nav_buttons.vec.push_back(std::move(button_2));
    REQUIRE( nav_buttons.vec.size() == 2 );
    REQUIRE( nav_buttons.vec[0]->button_properties->pos.x == 0 );

    nav_buttons.vec[0]->button_properties->pos.x = 125;
    REQUIRE( nav_buttons.vec[0]->button_properties->pos.x == 125 );

    auto nav_execute = input(*nav_buttons.vec[1]);
    REQUIRE ( nav_execute == true );
}