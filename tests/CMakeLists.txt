# Copyright (c) 2025 by Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

# Create project
project ( build_teeny_tiny_engine_tests
	LANGUAGES CXX
	DESCRIPTION "Build unit tests for teeny tiny engine using Catch2 framework" )

# Add dependencies
include ( ../cmake/download_cpm.cmake )

CPMAddPackage ( "gh:catchorg/Catch2@3.6.0" )
CPMAddPackage( "gh:SFML/SFML#2.6.x" )

# Test files names
set ( test_TTE_names
	#button_catch_test
	common_catch_test
	entity_manager_catch_test
	input_manager_catch_test
	#physics_catch_test
	r_buffer_catch_test
	#tile_catch_test
	vec2_catch_test )

# Add individual executables
foreach ( test_TTE_name IN LISTS test_TTE_names )
	message ( "Creating test executable: ${test_TTE_name}" )
	add_executable ( ${test_TTE_name} ${test_TTE_name}.cpp )
	target_compile_features ( ${test_TTE_name} PRIVATE cxx_std_20 )
	target_link_libraries ( ${test_TTE_name} PRIVATE teeny_tiny_engine Catch2::Catch2WithMain )
endforeach()

enable_testing ()

# Registering test
foreach ( test_TTE_name IN LISTS test_TTE_names )
	message ( "Creating test: run_${test_TTE_name}" )
	add_test ( NAME run_${test_TTE_name} COMMAND ${test_TTE_name} )
	if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU|AppleClang" )
		set_tests_properties ( run_${test_TTE_name} PROPERTIES PASS_REGULAR_EXPRESSION "All tests passed" )
	endif ()
	if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
		# Environment modification required in test properties for ctest to run tests, otherwise it can not find the tests
		set_tests_properties ( run_${test_TTE_name} PROPERTIES PASS_REGULAR_EXPRESSION "All tests passed" ENVIRONMENT_MODIFICATION PATH=path_list_append:$<TARGET_RUNTIME_DLL_DIRS:${test_TTE_name}> )
	endif ()
endforeach()
