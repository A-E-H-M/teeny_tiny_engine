# Copyright (c) 2025 Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0
# (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

project( Teeny Tiny Engine
	VERSION 1.0.0
	LANGUAGES CXX
	DESCRIPTION "A 2D Gameboy engine written in C++" )

# Optional flags
option( BUILD_TTE "Build engine executable" OFF )
option( BUILD_TTE_TESTS "Build unit tests" OFF )
option( COMPILER_FLAGS "Build with compiler flags" OFF )

# Add dependencies
include( cmake/download_cpm.cmake )

CPMAddPackage( "gh:SFML/SFML#2.6.x" )
CPMAddPackage( "gh:nlohmann/json@3.11.3" )

# Add library targets
add_library( TTE
	src/input_manager.cpp )
target_include_directories( TTE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
target_link_libraries( TTE PUBLIC sfml-graphics sfml-window sfml-system nlohmann_json::nlohmann_json )

# Compile features
target_compile_features( TTE PRIVATE cxx_std_20 )

# Build with compiler flags and warnings as errors
if ( ${COMPILER_FLAGS} )
	set_target_properties( TTE PROPERTIES COMPILE_WARNING_AS_ERROR ON )
	if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU|AppleClang" )
			target_compile_options( TTE PRIVATE -Wall -Werror -Wextra -pedantic-errors )
			# TODO: Add -Wconversion -Wsign-conversion
	endif ()
	if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
			target_compile_options( TTE PRIVATE /Wall /WL /WX /W4 /wd"4100" )
	endif ()
endif ()

# Build game
if ( ${BUILD_TTE} )
	add_subdirectory ( build )
endif ()

# Check to build unit tests
if ( ${BUILD_TTE_TESTS} )
	enable_testing ()
	add_subdirectory ( tests )
endif ()

# End of file
