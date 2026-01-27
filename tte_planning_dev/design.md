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

#### Paradigms in Mind
Two paradigms that support my design architecture are object-oriented & functional programming. Test-driven development(TDD) and generic programming (templates) also are used in my approach. Using these as guides I push my ability to see code from a higher view point. My design is not purely built on paradigm or approach because I want to explore them.

#### Entity Manager (EM)
##### Why start with EM?
Even though some highly proformant entity management libraries already exist, I want to make this a large part of my project. It's what first drew me to the idea of my own engine. The current challenge for me is to over engineer and scope creep. I am constantly thinking "What should a game developer need to do?" and "Where is the line between my library's responsibility and the developers?" As an example:
- How should the developer be able to engage with their own configuration files? 
- How will they modify/update their configuration files?
- How does the engine handle configuration data to make it accessible?
- What does the engine's core layer abstract for the developer?

As you noticed, I started out writing about the EM and ended up with configuration and related I/O, but all those questions stemmed from thinking about designing the EM. I've had similar thoughts related to other systems, so it only makes sense to focus on what connects smaller facets to the larger game engine. If I was into audio then I'd imagine that's where I would start. For me, its the EM.

##### EM Design Thoughts (my brain in engineering mode)
![brainstorming_EM](/tte_planning_dev/photos_images/EM_Brain_Dump.jpg)
##### Key points for those who prefer lists
- A developer should be able to have multiple configuration files (we will start with two files of the same file format (<JSON>))
   - Components configuration file: Keys->Categories, Values->Data member arrays
   - Entity configuration file: (Keys->Entities, Value->Component types), (Key->Components, Value->Data values)
       - This files an ECS framework
- Require a hierarchy that defines how the configuration data needs to be structured
   - Removing the need specific file formats (JSON, YAML)
- Develop templates that to handle container and data mapping
- The engine will have templates for common I/O configuration tasks
   - Parsing JSON with third-party library
- A developer should be able to modify/update their configuration data by modifying their files or within their game source files
   - If they add a component in their game source files, it should be updated in their components configuration file
   - If they add a component in their components configuration file, it should be added to the EM and mapped
   - This will help to maintain continuity, but it will need to happen before they start their build process
   - I see this similar to being as a 'save' in a document editor