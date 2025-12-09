# Copyright (c) 2025 Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0
# (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

# Add dependencies
include( ../cmake/download_cpm.cmake )

CPMAddPackage( "gh:SFML/SFML#2.6.x" )
CPMAddPackage( "gh:nlohmann/json@3.11.3" )

# End of file
