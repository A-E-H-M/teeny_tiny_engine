/*  This header file is the first round of ideation for developing the input manager.   */

#pragma once

#include <memory>

#include "vec2.hpp"

namespace TTE
{
    enum class BUTTONS
    {
        A_KEY,
        B_KEY,
        UP_KEY,
        DOWN_KEY,
        LEFT_KEY,
        RIGHT_KEY,
        START_KEY,
        SELECT_KEY
    };
    
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
    
    class Console_Buttons
    {
        public:
            const std::map<BUTTONS, std::unique_ptr<Button>>& get_console_button_map() const { return button_map; }
            void add_console_button(const BUTTONS& button) { button_map[button] = std::make_unique<Button>(); } // error handling for already used buttons
    };

    class GBC_console_buttons : public Console_Buttons
    {
        private:
            std::map<BUTTONS, std::unique_ptr<Button>> button_map;

        public:
            GBC_console_buttons() {
                add_console_button(A_KEY);
                add_console_button(B_KEY);
                add_console_button(UP_KEY);
                add_console_button(DOWN_KEY);
                add_console_button(LEFT_KEY);
                add_console_button(RIGHT_KEY);
                add_console_button(START_KEY);
                add_console_button(SELECT_KEY);
            }
    };

    class Input_handler
    {
        private:
            Buttons buttons;
            std::unique_ptr<Command> a_key;
            std::unique_ptr<Command> b_key;
            std::unique_ptr<Command> up_key;
            std::unique_ptr<Command> down_key;
            std::unique_ptr<Command> left_key;
            std::unique_ptr<Command> right_key;
            std::unique_ptr<Command> start_key;
            std::unique_ptr<Command> select_key;

        public:
            void handle_input(const std::unique_ptr<std::queue<BUTTONS>>& input_queue) {}
    };

}