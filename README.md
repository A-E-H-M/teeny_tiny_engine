<!-- ### Unit Test and Documentation Generation Workflow Status -->
![GH Actions Workflow Status](https://img.shields.io/github/last-commit/A-E-H-M/teeny_tiny_engine?style=for-the-badge)
![GH Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/A-E-H-M/teeny_tiny_engine/CI_build_TTE.yml?style=for-the-badge)
![GH Actions Workflow Status](https://img.shields.io/github/license/A-E-H-M/teeny_tiny_engine?style=for-the-badge)
<!-- ![GH Actions Workflow Status] -->
<!-- ![GH Tag] -->

## Teeny Tiny Engine (TTE)
Teeny Tiny Engine a simple, cross-platform 2D game engine written in C++ to simulate Game Boy Color (CGB) game development. It utilizes C++20 features to emulate CGB Dot Matrix Game (DMG) behavior, but is not a one-to-one build of the Game Boy Toolchain.

### State of Development
At this stage, TTE is a header only library. Since there are no source files (.cpp) to compile, CMake has been set to build an interface target. Templates are now being implemented. Tests are being written to accompany new features but full coverage is not yet guaranteed. The entity manager(EM) is the primary subsystem being written, along with facets of other features that will engage with the EM. Additional libraries are being considered for physics and audio.

#### Current Feature Development
- Entity Manager
- Init configuration with system IO
- Run-time input handling
- Troubleshooting CI build path issues specific to Windows OS
- More visual aids

### About the Teeny Tiny Engine Project
This is a natural evolution from my first 2D game Geowars. The goal of this project is to build a 2D game engine that focuses on implementing modern C++ features and best practices while providing unit testing coverage and thorough documentation. While I will end up using third party libraries to handle some of the heavy lifting, this is my opportunity to be an adventurer. I get to build on my understanding of what makes a game engine by programming a C++ library for other developers. Exciting! This also means a first release is not likely to happen soon, but that doesn't mean you can't build and test out what I do have. Rest assured if you have any questions, please feel free to reach out to me. Huzzah.

---

### Build From Source
##### Requirements: C++20 & CMake 3.25 (*Linux users see additional requirements below*)
Before you can build TTE or the unit tests you need to decide where you will clone the `teeny_tiny_engine` repository. Then create a directory named `TTE_Build` at the same file level as the `teeny_tiny_engine` repository.
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

#### Building TTE
To build TTE, navigate to your `TTE_Build` and use the CMake commands listed below.
```
cmake -D BUILD_TTE::BOOL=ON ../teeny_tiny_engine/
cmake --build .
```
Within your `TTE_Build` directory, navigate via your CLI or with a file explorer to the `build` directory to find and run TTE.

```bash
user/home/
├── teeny_tiny_engine/
│   ├── build/ <---Not this directory
│   ├── cmake/
│   ├── include/
│       └── ...
│   └── ...
└── TTE_Build/
│   ├── build/ <---This directory
│   └── ...
```

#### Building TTE Tests
To build and run the unit tests, navigate to your `TTE_Build` and use the CMake commands listed below.
```
cmake -D BUILD_TTE_TESTS::BOOL=ON ../teeny_tiny_engine/    // Only test builds generated
cmake --build .
```
Within your `TTE_Build` directory, navigate via your CLI or with a file explorer to the `tests` directory to find and run TTE tests.

```bash
user/home/
├── teeny_tiny_engine/
│   ├── build/
│   ├── cmake/
│   ├── include/
│       └── ...
│   └── ...
└── TTE_Build/
│   ├── build/
│   ├── ...
│   └── tests/  <---This directory
```
The tests have been set to run together, but you can execute them individually.

<!--
#### Building with Compiler Flags
To build with additional warning compiler flags add the following `-D COMPILER_FLAGS::BOOL=ON` to the your first command.
> [!TIP]
> Flags can be applied to a regular build and a build with unit tests.
```
cmake -D BUILD_TTE_TESTS::BOOL=ON -D COMPILER_FLAGS::BOOL=ON ../teeny_tiny_engine/     // Test builds generated with compiler flags
cmake --build .
```
-->
---

### Continuous Integration
**Supported Environments & Compilers**
\
 CI workflows will build and unit test on g++ (through Ubuntu), MSVC (through Windows), and Clang (through macOS).

 ---

### Requirements
Your machine should have each of these already installed before you can proceed with building from source. Unlike the library dependencies listed in the next section which are handled by the dependency manager, these might take some extra leg work if they are not already installed. Always check to see if you have them before trying to install them.

> [!IMPORTANT]
>**C++ Standard**:
>The minimum required standard is C++20.
>
>**CMake**:
>CMake is TTE's build system. You will need CMake 3.25 or later installed on your machine to build TTE from source. Directions on how to install CMake can be found [here](https://cmake.org/download).
>
>**Additional Linux System Libraries**: 
>For Linux users, you will need to use your package manager to install additional system libraries. The example below is an example of commands intended for Debian & Ubuntu distributions. These are not included in the CMake build provided and will have to be installed prior to building TTE.
>```
>sudo apt update
>sudo apt install       
>   libxrandr-dev \
>   libxcursor-dev \
>   libxi-dev \
>   libudev-dev \
>   libfreetype-dev \
>   libflac-dev \
>   libvorbis-dev \
>   libgl1-mesa-dev \
>   libegl1-mesa-dev \
>   libfreetype-dev
>```
### List of Dependencies
These are only listed for your reference. You will not need to manually install them yourself, rather the CPM.cmake (see below) takes care of downloading the library dependencies with the correct version for you.
> [!NOTE]
>[SFML](https://github.com/SFML/SFML) is a multi-media library used for window, system, and graphics handling.
>
>[CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) is used for dependency management. The CMake build has been configured to download CPM from its GitHub repository if it is not already installed, along with all other dependencies such as SFML. CPM will extract the correct version for each dependency, unlike the requirements needed for the build.
>
>[Catch2](https://github.com/catchorg/Catch2) is the framework for writing unit tests.
---


