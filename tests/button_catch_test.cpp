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

        auto nav_x = nav.button_properties->pos.x;
        auto nav_y = nav.button_properties->pos.y;

        REQUIRE( nav_x == 0 );
        REQUIRE( nav_y == 0 );
    }

    SECTION( "Default constructors", "[select_button]" )
    {
        Select_button select;

        auto select_x = select.button_properties->pos.x;
        auto select_y = select.button_properties->pos.y;

        REQUIRE( select_x == 0 );
        REQUIRE( select_y == 0 );
    }

    SECTION( "Default constructors", "[system_button]" )
    {
        Navigation_button system;

        auto system_x = system.button_properties->pos.x;
        auto system_y = system.button_properties->pos.y;

        REQUIRE( system_x== 0 );
        REQUIRE( system_y == 0 );
    }

}


TEST_CASE( "Test template for setting button position", "[template]" )
{
    SECTION( "Changes default navigation button position", "[navigation_button]" )
    {    
        Navigation_button nav;

        Vec2<int> new_vec_1 { 20, 34 };
        set_position(nav, new_vec_1);

        auto a = nav.button_properties->pos.x;
        auto b = nav.button_properties->pos.y;

        REQUIRE( a == 20 );
        REQUIRE( b == 34 );
    }

    SECTION( "Changes default select button position", "[select_button]" )
    {
        Select_button select;

        Vec2<int> new_vec_2 { 17, 68 };
        set_position(select, new_vec_2);

        auto c = select.button_properties->pos.x;
        auto d = select.button_properties->pos.y;

        REQUIRE( c == 17 );
        REQUIRE( d == 68 );        
    }

    SECTION( "Changes default select button position", "[select_button]" )
    {
        System_button system;

        Vec2<int> new_vec_3 { 5, 423 };
        set_position(system, new_vec_3);

        auto e = system.button_properties->pos.x;
        auto f = system.button_properties->pos.y;

        REQUIRE( e == 5 );
        REQUIRE( f == 423 );        
    }

}