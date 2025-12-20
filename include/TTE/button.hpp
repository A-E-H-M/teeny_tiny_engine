#pragma once

#include <memory>
#include <iostream>

#include "vec2.hpp"

namespace TTE
{

    class Button_properties // Could use Button_properties class for other elements that require an oritentation and pointer to access it
    {
        private:
        
        public:
            Vec2<int> pos { 0, 0 }; // X & Y are relative to the top-left position of the graphic
            Button_properties(const int X = 0, const int Y = 0) : pos(X, Y) {}
            Vec2<int> get_position() const { return pos; }

            //void set_position(const Vec2<int>& new_pos) { pos.x = new_pos.x; pos.y = new_pos.y; }
            //void set_position(const int new_pos_x, const int new_pos_y) { pos.x = new_pos_x; pos.y = new_pos_y; }
    };

    class Navigation_button
    {
        private:
        public:
        // Change to unique pointer
            std::shared_ptr<Button_properties> button_properties = std::make_shared<Button_properties>();
            bool execute_command() { std::cout << "Nav" << std::endl; return true; };
    };

    class Select_button
    {
        private:
        public:
            std::shared_ptr<Button_properties> button_properties = std::make_shared<Button_properties>();
            bool execute_command() { std::cout << "Select" << std::endl; return true; };
    };

    class System_button
    {
        private:
        public:
            std::shared_ptr<Button_properties> button_properties = std::make_shared<Button_properties>();
            bool execute_command() { std::cout << "System" << std::endl; return true; };
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

    }
}; // End namespace