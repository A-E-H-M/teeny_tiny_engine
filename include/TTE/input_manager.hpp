/*  This header file is the first round of ideation for developing the input manager.   */

#pragma once

#include <memory>
#include <map>
#include <queue>

#include <TTE/vec2.hpp>
#include <TTE/common.hpp>
#include <TTE/button.hpp>


namespace TTE
{
    using Navigation_Buttons = Manager<Navigation_button>;
    using Select_Buttons = Manager<Select_button>;
    using System_Buttons= Manager<System_button>;

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