/*  This header file is the first round of ideation for developing the input manager.   */

#pragma once

#include <memory>
#include <map>
#include <queue>

#include "vec2.hpp"


namespace TTE
{

    template <typename T>
    void input(T button)
    {
        button.execute_command();
    };

} // End namespace