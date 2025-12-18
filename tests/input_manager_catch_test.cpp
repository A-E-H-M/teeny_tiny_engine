#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/input_manager.hpp"
#include "TTE/button.hpp"

using namespace TTE;

// Re-write as template test case
TEST_CASE( "Test template for setting button position", "[template]" )
{
    Navigation_button nav;

    input(nav);
}