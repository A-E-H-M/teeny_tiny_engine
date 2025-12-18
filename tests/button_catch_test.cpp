#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/button.hpp"
#include "TTE/vec2.hpp"


using namespace TTE;

TEST_CASE( "Button constructors", "[navigation_button]" )
{
    SECTION( "Default constructors" )
    {
        Navigation_button nav;

        auto x = nav.button_properties->pos.x;
        auto y = nav.button_properties->pos.y;

        REQUIRE( x == 0 );
        REQUIRE( y == 0 );
    }

    SECTION( "Default constructors", "[select_button]" )
    {
        Select_button select;

        auto x = select.button_properties->pos.x;
        auto y = select.button_properties->pos.y;

        REQUIRE( x == 0 );
        REQUIRE( y == 0 );
    }

    SECTION( "Default constructors", "[system_button]" )
    {
        Navigation_button system;

        auto x = system.button_properties->pos.x;
        auto y = system.button_properties->pos.y;

        REQUIRE( x == 0 );
        REQUIRE( y == 0 );
    }
}

TEST_CASE( "Test template for setting button position", "[template]" )
{
    SECTION( "Changes default navigation button position", "[navigation_button]" )
    {    
        Navigation_button nav;

        Vec2<int> new_vec { 20, 34 };
        set_position(nav, new_vec);

        auto x = nav.button_properties->pos.x;
        auto y = nav.button_properties->pos.y;

        REQUIRE( x == 20 );
        REQUIRE( y == 34 );
    }

    SECTION( "Changes default select button position", "[select_button]" )
    {
        Select_button select;

        Vec2<int> new_vec { 17, 68 };
        set_position(select, new_vec);

        auto x = select.button_properties->pos.x;
        auto y = select.button_properties->pos.y;

        REQUIRE( x == 17 );
        REQUIRE( y == 68 );        
    }

    SECTION( "Changes default select button position", "[select_button]" )
    {
        System_button system;

        Vec2<int> new_vec { 5, 423 };
        set_position(system, new_vec);

        auto x = system.button_properties->pos.x;
        auto y = system.button_properties->pos.y;

        REQUIRE( x == 5 );
        REQUIRE( y == 423 );        
    }

}