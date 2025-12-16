# Copyright (c) 2025 by Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

# Create project
project ( build_tte_tests
	LANGUAGES CXX
	DESCRIPTION "Build test suite for teeny tiny engine using Catch2 framework" )

# Add executable
add_executable ( teeny_tiny_engine_tests
	button_catch_test.cpp
	vec2_catch_test.cpp
	#button_test.cpp
	#event_loop_test.cpp
	)
target_compile_features ( teeny_tiny_engine_tests PRIVATE cxx_std_20 )

# Add dependencies
include ( ../cmake/download_cpm.cmake )

CPMAddPackage ( "gh:catchorg/Catch2@3.6.0" )

# Link dependencies
target_link_libraries ( teeny_tiny_engine_tests PRIVATE teeny_tiny_engine Catch2::Catch2WithMain )

enable_testing ()

add_test ( NAME run_teeny_tiny_engine_tests COMMAND teeny_tiny_engine_tests )
set_tests_properties ( run_teeny_tiny_engine_tests PROPERTIES PASS_REGULAR_EXPRESSION "All tests passed" )
