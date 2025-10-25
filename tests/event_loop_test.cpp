#include <thread>
#include <memory>
#include <iostream>
#include <optional>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

void t_event_handler(std::unique_ptr<sf::RenderWindow>& main_window)
{

    sf::Event event;
    while (main_window != nullptr)
    {
        while (main_window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    main_window = nullptr;
                    //main_window->close();
                    break;
                case sf::Event::KeyPressed:
                    std::cout << "Key Pressed\n";
                        if (event.key.code == sf::Keyboard::Escape)
                        {
                            std::cout << "Key ESC\n";
                            main_window = nullptr;
                            //main_window->close();
                        }
                    break;
                case sf::Event::KeyReleased:
                    std::cout << "Key Released\n";
                    break;
                case sf::Event::MouseButtonPressed:
                    std::cout << "Mouse Clicked\n";
                    break;
                default:
                    break;
            }
        }
    }
}


int main()
{
    std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>();
    window->create(sf::VideoMode({800, 600}), "SFML window");
    std::thread t_Window(t_event_handler, std::ref(window));

    while (window != nullptr)
    {
        window->clear();
        window->display();
    }
    
    window->close();

    if (t_Window.joinable())
    {
        t_Window.join();
        std::cout << "It works" << std::endl << std::flush;
    }
    else
    {
        std::cout << "it didn't work" << std::endl << std::flush;
    }

    return 0;
}