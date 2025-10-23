#include <iostream>

#include "../include/element.hpp"
#include "../include/vec2.hpp"

using namespace TTE;

int main ()
{
    Vec2 vec(12, 67);
    Vec2 vec1(45, 90);
    Element element(9, 5);

    //Button button(8, 7);
    Button button(vec);

    button.set_position(34, 76);
    button.set_position(vec1);

    Vec2 vec3 = button.get_position();

    std::cout << "Yes" << " drtjd" << std::endl;
    std::cout << vec3.y << std::flush;
    return 0;
}