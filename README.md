<!-- ### Unit Test and Documentation Generation Workflow Status -->
![GH Actions Workflow Status](https://img.shields.io/github/last-commit/A-E-H-M/teeny_tiny_engine?style=for-the-badge)
![GH Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/A-E-H-M/teeny_tiny_engine/CI_build_TTE.yml?style=for-the-badge)
![GH Actions Workflow Status](https://img.shields.io/github/license/A-E-H-M/teeny_tiny_engine?style=for-the-badge)
<!-- ![GH Actions Workflow Status] -->
<!-- ![GH Tag] -->

## Teeny Tiny Engine (TTE)
Teeny Tiny Engine a simple, cross-platform 2D game engine written in C++ to simulate Game Boy Color (CGB) game development. It utilizes C++20 features to emulate CGB Dot Matrix Game (DMG) behavior, but is not a one-to-one build of the Game Boy Toolchain.

### State of Development
Development is in its primary planning phase: conceptualizing API framework, deciding on design standards, and prioritizing feature development. The following sections highlight what you can expect in the days to come.

#### Current Feature Development
- Button template design
- Input thread
- Python script to install system dependencies for linux, or create Flatpak/containerized environment

### Build From Source
##### Requirements: C++20 & CMake 3.25 (*Linux users see additional requirements below*)
> First, decide where you will clone the `teeny_tiny_engine` repository. Then create a directory named `TTE_Build` at the same file level as the `teeny_tiny_engine` repository.
```bash
user/home/
├── teeny_tiny_engine/
│   ├── build/
│   ├── cmake/
│   ├── include/
│       └── ...
│   └── ...
└── TTE_Build/
```
### Building Tests
> To build and run the unit tests, navigate to your `TTE_Build` and use the CMake commands listed below.
```
cmake -D BUILD_TTE_TESTS::BOOL=ON ../teeny_tiny_engine/    // Only test builds generated
cmake --build .                                            // Builds and runs tests created in prior command
```
#### Build with Compiler Flags
> To build Geowars tests with additional warning compiler flags add the following `-D COMPILER_FLAGS::BOOL=ON` to the your first command.
```
cmake -D BUILD_TTE_TESTS::BOOL=ON -D COMPILER_FLAGS::BOOL=ON ../teeny_tiny_engine/     // Test builds generated with compiler flags
cmake --build .                                                                        // Builds and runs tests with compiler flags created in the prior command
```
### Continuous Integration
&nbsp;&nbsp;&nbsp;&nbsp; **Supported Environments & Compilers**
\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; CI workflows will build and unit test on g++ (through Ubuntu), MSVC (through Windows), and Clang (through macOS).
### Requirements
Your machine should have each of these already installed before you can proceed with building from source. Unlike the library dependencies listed in the next section which are handled by the dependency manager, these might take some extra leg work if they are not already installed. Always check to see if you have them before trying to install them.
> &nbsp;&nbsp;&nbsp;&nbsp; **C++ Standard**
\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The minimum required standard is C++20.
\
&nbsp;&nbsp;&nbsp;&nbsp; **CMake**
\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; CMake is TTE's build system. You will need CMake 3.25 or later installed on your machine to build TTE from source. Directions on how to install CMake can be found [here](https://cmake.org/download).
\
&nbsp;&nbsp;&nbsp;&nbsp; **Additional Linux System Libraries**
\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; For Linux users, you will need to use your package manager to install additional system libraries. The example below is an example of commands intended for Debian & Ubuntu distributions. These are not included in the CMake build provided and will have to be installed prior to building TTE.
```
sudo apt update
sudo apt install       
   libxrandr-dev \
   libxcursor-dev \
   libxi-dev \
   libudev-dev \
   libfreetype-dev \
   libflac-dev \
   libvorbis-dev \
   libgl1-mesa-dev \
   libegl1-mesa-dev \
   libfreetype-dev
```
### List of Dependencies
These are only listed for your reference. You will not need to manually install them yourself, rather the CPM.cmake (see below) takes care of downloading the library dependencies with the correct version for you.
> &nbsp;&nbsp;&nbsp;&nbsp; **SFML**
\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  [SFML](https://github.com/SFML/SFML) is a multi-media library used for window, system, and graphics handling.
\
&nbsp;&nbsp;&nbsp;&nbsp; **CPM.cmake**
\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) is used for dependency management. The CMake build has been configured to download CPM from its GitHub repository if it is not already installed, along with all other dependencies such as SFML. CPM will extract the correct version for each dependency, unlike the requirements needed for the build.

## About Teeny Tiny Engine
&nbsp;&nbsp;&nbsp;&nbsp; This is a natural evolution from my first 2D game Geowars. The goal of this project is to build a 2D game engine that focuses on implementing modern C++ features and best practices while providing unit testing coverage and thorough documentation.
