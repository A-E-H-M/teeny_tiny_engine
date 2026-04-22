#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "TTE/r_buffer.hpp"

using namespace R_BUFFER;

TEST_CASE( "Test template for ring buffer", "[ring_buffer template]" )
{
    Ring_buffer<int, 3> int_buffer;

    REQUIRE (int_buffer.size_of() == 3);

    SECTION ("Modification using adding")
    {
        // adding to the limit of the buffer without wrapping
        int_buffer.add(5);
        int_buffer.add(23);
        int_buffer.add(17);

        REQUIRE( int_buffer.at(0) == 5 );
        REQUIRE( int_buffer.at(1) == 23 );
        REQUIRE( int_buffer.at(2) == 17 );

        // adding with wrapping
        int_buffer.add(10);
        int_buffer.add(63);
        int_buffer.add(5623);

        REQUIRE ( int_buffer.at(0) == 10 );
        REQUIRE ( int_buffer.at(1) == 63 );
        REQUIRE ( int_buffer.at(2) == 5623 );

    }

    SECTION ("Modification at specific index")
    {

        int_buffer.assign(1, 8);
        int_buffer.assign(0, 489);

        REQUIRE ( int_buffer.at(1) == 8 );
        REQUIRE ( int_buffer.at(0) == 489 );
        
    }

	/*
    SECTION ("Modification by clearing buffer")
    {
        int_buffer.clear();

        REQUIRE( int_buffer.at(0) == 5 );
        REQUIRE( int_buffer.at(1) == 23 );
        REQUIRE( int_buffer.at(2) == 17 );
    }
    */
    

    SECTION ("Accessing last-in element added to buffer")
    {
        // Using add to modify buffer before accessing last-in element
        int_buffer.add(70);
        REQUIRE ( int_buffer.last() == 70 );

        int_buffer.add(4953);
        REQUIRE ( int_buffer.last() == 4953 );

        int_buffer.add(456);
        REQUIRE ( int_buffer.last() == 456 );
        
        // adding all buffer elements with value 0
        int_buffer.add(0);
        REQUIRE ( int_buffer.last() == 0 );

        int_buffer.add(0);
        REQUIRE ( int_buffer.last() == 0 );

        int_buffer.add(0);
        REQUIRE ( int_buffer.last() == 0 );

    }

    /*
    SECTION ("Accessing first-in element added to buffer")
    {
        // Using add to modify buffer before accessing first-in element
        REQUIRE ( int_buffer.end() == 0 );
        int_buffer.add(70);
        
        REQUIRE ( int_buffer.end() == 0 );
        int_buffer.add(4953);

        REQUIRE ( int_buffer.end() == 0 );
        int_buffer.add(37);

        REQUIRE ( int_buffer.end() == 70 );
        int_buffer.add(0);

        REQUIRE ( int_buffer.end() == 4953 );
        int_buffer.add(0);

        REQUIRE ( int_buffer.end() == 37 );
        int_buffer.add(0);
    }
    */

}