#pragma once

#include <memory>
#include <iostream>

#include <TTE/vec2.hpp>
#include <TTE/common.hpp>

namespace TTE
{

    struct Button_properties // Could use Button_properties class for other elements that require an oritentation and pointer to access it
    {
            Vec2<int> pos { 0, 0 }; // X & Y are relative to the top-left position of the graphic
            Button_properties(const int X = 0, const int Y = 0) : pos(X, Y) {}
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
    
}; // End namespace