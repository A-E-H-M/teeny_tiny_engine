
#include <memory>
#include <vector>
#include <array>

#include <TTE/tile.hpp>
#include <TTE/vec2.hpp>
#include <TTE/common.hpp>

using namespace TTE;

int main ()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");


    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        
        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            switch (event.type){
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

        // Tiny box matrix
        auto tb_matrix_square = create_matrix_square<Tiny_box, 8>();
        tb_matrix_square[0]->at(0).tiny_box.setFillColor(sf::Color(100, 250, 50));
        tb_matrix_square[0]->at(0).tiny_box.setSize({100.f, 100.f});

        tb_matrix_square[0]->at(1).tiny_box.setFillColor(sf::Color(120, 100, 50));
        tb_matrix_square[0]->at(1).tiny_box.setSize({100.f, 100.f});
        tb_matrix_square[0]->at(1).tiny_box.setPosition({100.f, 0.f});

        tb_matrix_square[0]->at(2).tiny_box.setFillColor(sf::Color(20, 200, 125));
        tb_matrix_square[0]->at(2).tiny_box.setSize({100.f, 100.f});
        tb_matrix_square[0]->at(2).tiny_box.setPosition({200.f, 0.f});

        tb_matrix_square[1]->at(0).tiny_box.setFillColor(sf::Color(70, 159, 50));
        tb_matrix_square[1]->at(0).tiny_box.setSize({100.f, 100.f});
        tb_matrix_square[1]->at(0).tiny_box.setPosition({0.f, 100.f});

        tb_matrix_square[1]->at(1).tiny_box.setFillColor(sf::Color(200, 20, 10));
        tb_matrix_square[1]->at(1).tiny_box.setSize({100.f, 100.f});
        tb_matrix_square[1]->at(1).tiny_box.setPosition({100.f, 100.f});

        tb_matrix_square[1]->at(2).tiny_box.setFillColor(sf::Color(170, 75, 200));
        tb_matrix_square[1]->at(2).tiny_box.setSize({100.f, 100.f});
        tb_matrix_square[1]->at(2).tiny_box.setPosition({200.f, 100.f});

        // Render window
        window.clear(sf::Color(255, 255, 255));
        window.draw(tb_matrix_square[0]->at(0).tiny_box);
        window.draw(tb_matrix_square[0]->at(1).tiny_box);
        window.draw(tb_matrix_square[0]->at(2).tiny_box);
        window.draw(tb_matrix_square[1]->at(0).tiny_box);
        window.draw(tb_matrix_square[1]->at(1).tiny_box);
        window.draw(tb_matrix_square[1]->at(2).tiny_box);
        window.display();
    }

    return 0;
}