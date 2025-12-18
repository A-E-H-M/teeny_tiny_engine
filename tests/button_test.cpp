#include <iostream>
#include <thread>

#include "TTE/button.hpp"
#include "TTE/vec2.hpp"
#include "TTE/input_manager.hpp"

using namespace TTE;

/*void thread_test(const Vec2<int> vec2_, Button* button_)
{
    button_->set_position(34, 76);
    Vec2 vec3 = button_->get_position();
    std::cout << "Second time: " << vec3.x << std::endl;

    button_->set_position(vec2_);
    vec3 = button_->get_position();
    std::cout << "Third time: " << vec3.x << std::endl;
}
    */

int main ()
{
    
    TTE::Navigation_button nav;
    nav.execute_command();
    //std::cout << nav.button_properties->pos.x << " " <<  nav.button_properties->pos.y;

    Vec2 new_vec{ 1, 9 };
    //std::cout << new_vec.x << " " <<  new_vec.y;

    TTE::set_position(nav, new_vec);
    //std::cout << nav.button_properties->pos.x << " " <<  nav.button_properties->pos.y;

    /*
    Vec2 vec1(0,0);

    Button button(8, 7);
    Button* button_ptr = &button;
    vec1 = button_ptr->get_position();
    std::cout << "First time: " << vec1.x << std::endl;

    std::thread t1(thread_test, vec1, button_ptr);

    if (t1.joinable())
    {
        vec1 = button_ptr->get_position();
        std::cout << "Fourth time: " <<vec1.x << std::endl;
        t1.join();
    }

    if (!t1.joinable())
    {
        std::cout << "it did join" << std::endl << std::flush;
    }

    */

    return 0;
}
