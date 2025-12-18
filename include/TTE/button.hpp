#pragma once

#include <memory>
#include <iostream>

#include "vec2.hpp"

namespace TTE
{

    /*
     enum class BUTTONS
    {
        NAVIGATION,
        SELECT,
        SYSTEM
    };

    */

    class Button_properties // Could use Button_properties class for other elements that require an oritentation and pointer to access it
    {
        private:
        
        public:
            Vec2<int> pos { 0, 0 }; // X & Y are relative to the top-left position of the graphic
            Button_properties(const int X = 0, const int Y = 0) : pos(X, Y) {}
            Vec2<int> get_position() const { return pos; }

            //void set_position(const Vec2<int>& new_pos) { pos.x = new_pos.x; pos.y = new_pos.y; }
            //void set_position(const int new_pos_x, const int new_pos_y) { pos.x = new_pos_x; pos.y = new_pos_y; }

            //Button_properties(){};
    };

    /*
    class Button
    {
        private:
            // std::shared_ptr<Command> button_command {}; // Default initializes to null unique_ptr
            std::shared_ptr<Button_properties> button_properties {};
            std::string command_type;

        public:
            void set_command(const std::shared_ptr<Command>& command) { button_command = command; }
            
            Button(const Vec2<int>& button_pos, std::string command_type) : Button_properties{ button_pos.x, button_pos.y }, command_type(command_type) {}
            Button(const Vec2<int>& button_pos, std::string command_type) : Button_properties{ button_pos.x, button_pos.y }, button_command(command) {}

            Button(const int button_pos_x = 0, const int button_pos_y = 0) : Button_properties{ button_pos_x, button_pos_y } {}
            Button(const int button_pos_x, const int button_pos_y, const std::shared_ptr<Command>& command) : Button_properties{ button_pos_x, button_pos_y }, button_command(command) {}
    };
    */

    class Navigation_button
    {
        private:
        public:
            std::shared_ptr<Button_properties> button_properties = std::make_shared<Button_properties>();
            void execute_command() { std::cout << "Nav" << std::endl; };
    };

 class Select_button
    {
        private:
        public:
            std::shared_ptr<Button_properties> button_properties {};
            void execute_command() { std::cout << "Select" << std::endl; };
    };

 class System_button
    {
        private:
        public:
            std::shared_ptr<Button_properties> button_properties {};
            void execute_command() { std::cout << "System" << std::endl; };
    };
    
    template <typename T, typename V>
    void set_position(T& button, V new_pos)
    {
        button.button_properties->pos.x = new_pos.x; 
        button.button_properties->pos.y = new_pos.y;
      
        /*
        // Fix to accept int values, not just Vec2 instances
        button.button_properties->pos.x = 3;
        button.button_properties->pos.y = 2;
        */

    };
    /*
    template class Button_type(typename T, typename V)
    {
        public:
            std::shared_ptr<Button_properties> button_properties {};
            V command_type;
            Button_properties button_pos;

            Button_type(const Vec2<T> button_pos, const V command_type) : Button_properties{ button_pos.x, button_pos.y }, command_type(command_type) {}
    };

    Button_type navigation(button_pos, command_type);
    Key key_a(navigation);
    */
}; // End namespace