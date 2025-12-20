/*  This header file is the first round of ideation for developing the input manager.   */

#pragma once

#include <memory>
#include <map>
#include <queue>

#include "vec2.hpp"


namespace TTE
{

    template <typename T>
    bool input(T button)
    {
        auto button_return = button.execute_command();
        if(button_return == true)
        {
            return true;
        }
        return false;
    };

} // End namespace