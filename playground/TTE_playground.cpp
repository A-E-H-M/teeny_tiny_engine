#include <memory>
#include <vector>
#include <array>
#include <iostream>

#include <TTE/tile.hpp>
#include <TTE/vec2.hpp>
#include <TTE/common.hpp>

using namespace TTE;

int main ()
{
    //std::map<int, std::unique_ptr<Tile>> tile_map_1.tile_map;

    Tile_map tile_map_1;

    // Grid of Vec2 based on 800 X 720 screen size with 40 unit spatial difference
    auto viewport = create_matrix<Vec2<std::size_t>>(20, 18);
    int map_count = 0;

    std::size_t spatial_diff_x = 40;
    std::size_t spatial_diff_y = 40;

    std::size_t temp_spatial_diff_x = 0;
    std::size_t temp_spatial_diff_y = 0;

    for (std::size_t i = 0; i < 20; ++i)
    {
        temp_spatial_diff_y += spatial_diff_y;

        for (std::size_t a = 0; a < 18; ++a)
        {
            temp_spatial_diff_x += spatial_diff_x;
            
            viewport[i]->at(a).x = temp_spatial_diff_x;
            viewport[i]->at(a).y = temp_spatial_diff_y;
            
            auto temp_tile = std::make_unique<Tile>();
            temp_tile->pos.x = temp_spatial_diff_x;
            temp_tile->pos.y = temp_spatial_diff_y;
            int temp_ID = temp_tile->tile_id;
            tile_map_1.tile_map[temp_tile->tile_id] = std::move(temp_tile);

            tile_map_1.tile_map[temp_ID]->tile[0]->at(0).tiny_box.setPosition(temp_spatial_diff_x, temp_spatial_diff_y);
            tile_map_1.tile_map[temp_ID]->tile[0]->at(0).tiny_box.setSize({5.f, 5.f});
            tile_map_1.tile_map[temp_ID]->tile[0]->at(0).tiny_box.setFillColor(sf::Color(70, 159, 50));

            tile_map_1.tile_map[temp_ID]->tile[0]->at(1).tiny_box.setPosition(temp_spatial_diff_x+5, temp_spatial_diff_y);
            tile_map_1.tile_map[temp_ID]->tile[0]->at(1).tiny_box.setSize({5.f, 5.f});
            tile_map_1.tile_map[temp_ID]->tile[0]->at(1).tiny_box.setFillColor(sf::Color(200, 75, 130));

            tile_map_1.tile_map[temp_ID]->tile[1]->at(1).tiny_box.setPosition(temp_spatial_diff_x, temp_spatial_diff_y+5);
            tile_map_1.tile_map[temp_ID]->tile[1]->at(1).tiny_box.setSize({5.f, 5.f});
            tile_map_1.tile_map[temp_ID]->tile[1]->at(1).tiny_box.setFillColor(sf::Color(20, 10, 180));
        }
        temp_spatial_diff_x = 0;
    }

    sf::RenderWindow window(sf::VideoMode({720, 800}), "My window");

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        
        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
				// Close window using the button on the top left of window
				case sf::Event::Closed:
					window.close();
					break;
				// Check for keyboard input
				case sf::Event::KeyPressed:
					// Close window if 'x' is pressed
					if (event.key.code == sf::Keyboard::X)
                    {
					    window.close();
					}
					break;
				default:
					break;
            }
        }

        // Render window
        window.clear(sf::Color(255, 255, 255));
        for (int i = 0; i < Tile_ID; ++i)
        {
            window.draw(tile_map_1.tile_map[i]->tile[0]->at(0).tiny_box);
            window.draw(tile_map_1.tile_map[i]->tile[0]->at(1).tiny_box);
            window.draw(tile_map_1.tile_map[i]->tile[1]->at(1).tiny_box);
        }
        window.display();
    }

    return 0;
}