<!-- ### Unit Test and Documentation Generation Workflow Status -->
![GH Actions Workflow Status](https://img.shields.io/github/last-commit/A-E-H-M/teeny_tiny_engine?style=for-the-badge)
![GH Actions Workflow Status](https://img.shields.io/github/license/A-E-H-M/teeny_tiny_engine?style=for-the-badge)
<!-- ![GH Actions Workflow Status] -->
<!-- ![GH Tag] -->

## Teeny Tiny Engine (TTE)
Teeny Tiny Engine a simple, cross-platform 2D game engine written in C++ to simulate Game Boy Color (CGB) game development. It utlizes C++20 features to emulate CGB Dot Matrix Game (DMG) behavior, but is not a one-to-one build of the Game Boy Toolchain.

## State of Development
Development is in its primary planning phase: conceptualizing API framework, deciding on design standards, and prioritizing feature development. The following sections highlight what you can expect in the days to come.

#### Current Feature Development
- Input Manager

#### Build From Source
##### Requirements: C++20 & CMake 3.25


### Continuous Integration
#### Supported Environments & Compilers
CI workflows will build and unit test on g++ (through Ubuntu), MSVC (through Windows), and Clang (through macOS).


### Requirements
Your machine should have each of these already installed before you can proceed with building from source. Unlike the library dependencies listed in the next section which are handled by the dependency manager, these might take some extra leg work if they are not already installed. Always check to see if you have them before trying to install them.
##### C++ Standard
The minimum required standard is C++20.
##### CMake
CMake is TTE's build system. You will need CMake 3.25 or later installed on your machine to build TTE from source. Directions on how to install CMake can be found [here](https://cmake.org/download).
### List of Dependencies
These are only listed for your reference. You will not need to manually install them yourself, rather the CPM.cmake (see below) takes care of downloading the library dependencies with the correct version for you.
##### SFML
[SFML](https://github.com/SFML/SFML) is a multi-media library used for window, system, and graphics handling.
##### CPM.cmake
[CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) is used for dependency management. The CMake build has been configured to download CPM from its GitHub repository if it is not already installed, along with all other dependencies such as SFML. CPM will extract the correct version for each dependency, unlike the requirements needed for the build.


## About Teeny Tiny Engine
This is a natural evolution from my first 2D game Geowars. The goal of this project is to build a 2D game engine that focuses on implementing modern C++ features and best practices while providing unit testing coverage and thorough documentation.