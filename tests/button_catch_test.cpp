#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/button.hpp"
#include "TTE/vec2.hpp"

using namespace TTE;

TEST_CASE( "Button constructors", "[button]" )
{
    SECTION( "Default constructor creates button at origin" )
    {
        Button button;
        auto pos = button.get_position();
        REQUIRE( pos.x == 0 );
        REQUIRE( pos.y == 0 );
    }

    SECTION( "Constructor with x and y coordinates" )
    {
        Button button(100, 200);
        auto pos = button.get_position();
        REQUIRE( pos.x == 100 );
        REQUIRE( pos.y == 200 );
    }

    SECTION( "Constructor with Vec2 position" )
    {
        Vec2<int> button_pos(50, 75);
        Button button(button_pos);
        auto pos = button.get_position();
        REQUIRE( pos.x == 50 );
        REQUIRE( pos.y == 75 );
    }

    SECTION( "Constructor with x, y coordinates and command" )
    {
        auto command = std::make_shared<Command>();
        Button button(150, 250, command);
        auto pos = button.get_position();
        REQUIRE( pos.x == 150 );
        REQUIRE( pos.y == 250 );
    }

    SECTION( "Constructor with Vec2 position and command" )
    {
        Vec2<int> button_pos(300, 400);
        auto command = std::make_shared<Command>();
        Button button(button_pos, command);
        auto pos = button.get_position();
        REQUIRE( pos.x == 300 );
        REQUIRE( pos.y == 400 );
    }
}

TEST_CASE( "Button position management", "[button]" )
{
    SECTION( "Get position returns correct coordinates" )
    {
        Button button(10, 20);
        Vec2<int> pos = button.get_position();
        REQUIRE( pos.x == 10 );
        REQUIRE( pos.y == 20 );
    }

    SECTION( "Set position with Vec2" )
    {
        Button button;
        Vec2<int> new_pos(100, 150);
        button.set_position(new_pos);
        auto pos = button.get_position();
        REQUIRE( pos.x == 100 );
        REQUIRE( pos.y == 150 );
    }

    SECTION( "Set position with x and y coordinates" )
    {
        Button button;
        button.set_position(200, 300);
        auto pos = button.get_position();
        REQUIRE( pos.x == 200 );
        REQUIRE( pos.y == 300 );
    }

    SECTION( "Update position multiple times" )
    {
        Button button(10, 20);

        button.set_position(30, 40);
        auto pos1 = button.get_position();
        REQUIRE( pos1.x == 30 );
        REQUIRE( pos1.y == 40 );

        button.set_position(50, 60);
        auto pos2 = button.get_position();
        REQUIRE( pos2.x == 50 );
        REQUIRE( pos2.y == 60 );
    }

    SECTION( "Set position with negative coordinates" )
    {
        Button button;
        button.set_position(-10, -20);
        auto pos = button.get_position();
        REQUIRE( pos.x == -10 );
        REQUIRE( pos.y == -20 );
    }
}

TEST_CASE( "Button command management", "[button]" )
{
    SECTION( "Set command after button creation" )
    {
        Button button;
        auto command = std::make_shared<Command>();
        REQUIRE_NOTHROW( button.set_command(command) );
    }

    SECTION( "Replace existing command" )
    {
        auto command1 = std::make_shared<Command>();
        Button button(0, 0, command1);

        auto command2 = std::make_shared<Command>();
        REQUIRE_NOTHROW( button.set_command(command2) );
    }
}

TEST_CASE( "Button with custom command", "[button][command]" )
{
    class TestCommand : public Command
    {
    public:
        int execute_count = 0;
        void execute() override { execute_count++; }
    };

    SECTION( "Button can hold and execute custom command" )
    {
        auto test_command = std::make_shared<TestCommand>();
        Button button(0, 0, test_command);

        REQUIRE( test_command->execute_count == 0 );
        test_command->execute();
        REQUIRE( test_command->execute_count == 1 );
    }
}

TEST_CASE( "Button edge cases", "[button]" )
{
    SECTION( "Button with very large coordinates" )
    {
        Button button(999999, 888888);
        auto pos = button.get_position();
        REQUIRE( pos.x == 999999 );
        REQUIRE( pos.y == 888888 );
    }

    SECTION( "Button position at INT_MAX boundaries" )
    {
        Button button(2147483647, 2147483647);
        auto pos = button.get_position();
        REQUIRE( pos.x == 2147483647 );
        REQUIRE( pos.y == 2147483647 );
    }

    SECTION( "Button with zero coordinates after non-zero initialization" )
    {
        Button button(100, 200);
        button.set_position(0, 0);
        auto pos = button.get_position();
        REQUIRE( pos.x == 0 );
        REQUIRE( pos.y == 0 );
    }
}
