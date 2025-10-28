#pragma once

#include <memory>
#include <mutex>

#include "vec2.hpp"

namespace TTE
{

    class Command
    {
        public:
            //virtual void execute(const game_actor& actor) {}
            virtual void execute() {}
            virtual ~Command() {}
    };

    class Element // Could use Element class for other elements that require an oritentation and pointer to access it
    {
        private:
            Vec2<int> pos; // X & Y are relative to the top-left position of the graphic

        public:
            Element(const int X = 0, const int Y = 0) : pos(X, Y) {}
            Vec2<int> get_position() const { return pos; }

            void set_position(const Vec2<int>& new_pos) { pos.x = new_pos.x; pos.y = new_pos.y; }
            void set_position(const int new_pos_x, const int new_pos_y) { pos.x = new_pos_x; pos.y = new_pos_y; }
    };

    class Button : public Element
    {
        private:
            std::shared_ptr<Command> button_command {}; // Default initializes to null unique_ptr

        public:
            void set_command(const std::shared_ptr<Command>& command) { button_command = command; }
            
            Button(const Vec2<int>& button_pos) : Element{ button_pos.x, button_pos.y } {}
            Button(const Vec2<int>& button_pos, const std::shared_ptr<Command>& command) : Element{ button_pos.x, button_pos.y }, button_command(command) {}

            Button(const int button_pos_x = 0, const int button_pos_y = 0) : Element{ button_pos_x, button_pos_y } {}
            Button(const int button_pos_x, const int button_pos_y, const std::shared_ptr<Command>& command) : Element{ button_pos_x, button_pos_y }, button_command(command) {}
    };

};