# Copyright (c) 2026 by Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

# Create project
project ( build_teeny_tiny_engine_playground
	LANGUAGES CXX
	DESCRIPTION "Build playground for teeny tiny engine" )

# Add dependencies
#include ( ../cmake/download_cpm.cmake )

# Add executable
add_executable( TTE_playground TTE_playground.cpp )
target_link_libraries( TTE_playground PUBLIC teeny_tiny_engine )
target_compile_features( TTE_playground PRIVATE cxx_std_20 )

# End of file