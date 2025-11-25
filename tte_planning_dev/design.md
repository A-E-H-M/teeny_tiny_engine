<!-- ### Documentation Generation Workflow Status -->
![GH Actions Workflow Status](https://img.shields.io/github/last-commit/A-E-H-M/teeny_tiny_engine?style=for-the-badge)

### Design
After many hours of discussion, playing with my hair, and pages of hand written ideas I've come even closer to narrowing down the scope of this project. It dawned on me that I am not building just one C++ library but two(!) and an application. I want to create two different libraries (engine core & editor core) so, theoretically, a developer could use the engine core library for the structures and logic of the game without the editor engine or application. This approach provides encapsulation, greater separation of concerns, and the ability to write simplified unit tests.

In my mind there are two separate states, if you will, that will be maintained and referred to: the game state and editor state. The editor core library will call upon the game core library to update the game state, and it will also update the editor state. Since the final product will be a cross-platform executable game and not the editor, the separation of states is needed.

This project does not focus on building an emulator/engine/library/application that can create executable binaries for the physical GameBoy. A developer will not be able to use a GameBoy debugger for any game developed with these libraries or the editor application.

1) Engine Core
The engine core will provide the most basic level structures and logic of a GB game. It will simulate attributes like tiles and tilemaps in GB development but will not replicate the original GB developers implementation of them. Instead, this library, along with the editor core library, looks to harness the strengths of C++.
2) Editor Core
The purpose of the editor engine is to encapsulate the engine core while creating and maintaining its own structures and logic. It will focus on providing developer tools and higher level abstractions for a simplified game development API.
3) Editor Application
The editor application will be a GUI that utilizes the editor engine and implements the SFML library for graphics. As an example, developers will be able to create and edit tilemaps using drop down menus and color palettes in the editor application. They will not need to directly interact with the engine core or editor core library.