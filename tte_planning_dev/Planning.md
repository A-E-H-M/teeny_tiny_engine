<!-- ### Documentation Generation Workflow Status -->
![GH Actions Workflow Status](https://img.shields.io/github/last-commit/A-E-H-M/teeny_tiny_engine?style=for-the-badge)

## Planning Phase
The purpose of the planning phase is to identify which engine components will be defined and features that need development, all in tandem with the ability to provide long-term support through testing and CI/CD. Below is the list of steps to be taken.
1) Create a specifications sheet to outline what defining features make the Game Boy unique
2) Define the high-level components that TTE will support
3) Identify potential features and map relationships
4) Determine any syntactical rules or standards that should be implemented/documented for users to understand the header files (Ex. Naming conventions)


### Game Boy Color Specifications
#### Physical properties
- 160 pixels x 144 pixels screen resolution
- 8 buttons (inclusive of 1 directional pad)
- 8-bit audio

#### Graphics
- Supports RGB color palettes
- Displays upto 56 colors simultaneously (out of 32,768 colors)
    - Can rapidly change out color palettes to create more colors AKA “high color mode”
- Supports 8 4-color background palettes
- Supports 8 3-color sprite palettes

#### Rendering
- 1228 bytes of CHR RAM for 786 tiles
    - 256 tiles for sprites
    - 256 tiles for sprites & background overlap
    - 256 tiles for background
- Cell tile maps are 32 pixels x 32 pixels
- Supports drawing two tile maps
- Upto 40 sprites can reside in memory (OAM) 
    - Either 8 pixels x 8 pixels, or 8 pixels x 16 pixels
- Upto 10 sprites can be drawn to the screen at once (about 50% of a 160-pixel-wide scanline)
- Each frame consists of 144 lines of picture and 10 lines of vertical blanking
- 516 tiles are drawn per frame
    - 360-399 visible, others offscreen as a scrolling buffer

### Clarifications
- A game engine contains a core loop responsible for updating states and providing those states in a cyclical manner. [Isetta Engine Team's interview with Casey Muratori](https://isetta.io/interviews/CaseyMuratori-interview/#problem-1-an-amorphous-system)
