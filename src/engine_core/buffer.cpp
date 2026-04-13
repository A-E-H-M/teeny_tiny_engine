#include <iostream>
#include <string>
#include "buffer.hpp"

namespace r_buffer
{

    void Ring_buffer::pop_range(int num)
    {
        if (num > size)
        {
            for (auto& element : *Darray)
                element = "";
        }

        while (num > 0)
        {
            last_pos--;
            auto temp = last_pos % size;
            (*Darray)[temp] = "";
            num--;
        }
        
        counter = last_pos;
    }

    std::string Ring_buffer::at(int index)
    {
        return (*Darray)[index];
    }

    void Ring_buffer::pop_back(int num_elements)
    {
        pop_range(num_elements); 
    }

    bool Ring_buffer::append(std::string_view string_temp) 
    {
        auto temp = counter % size;
        int temp_empty{0};

        if (erase(temp))
        {
            (*Darray)[temp] = string_temp;
            last_pos = counter;
            counter++;
            return true;
        }
        else
        {
            //temp = counter % size;
            temp_empty = find_empty(temp);
            if (temp_empty > 0)
            {
                (*Darray)[temp_empty] = string_temp;
                last_pos = counter;
                //counter++;
                counter = temp_empty;
                return true;
            }
            return false;
        }

    }

    int Ring_buffer::find_empty(int temp_pos)
    {
        std::string temp_string;
        for (auto i = 0; i > size; ++i)
        {
            //(*Darray)[temp_pos] = temp_string;
            if (erase(temp_pos))
                return temp_pos;
            else
            {
                temp_pos++;
                temp_pos = (temp_pos) % size;
            }
        }

        return -1;
    }

    bool Ring_buffer::erase(int temp_index)
    {
        auto temp_value = (*Darray)[temp_index];
        if (temp_value == "")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Ring_buffer::assign(std::string_view temp_str_view)
    {
        auto over_ride_pos = counter % size;
        (*Darray)[over_ride_pos] = "";
        append(temp_str_view);
    }
} // end of namespace