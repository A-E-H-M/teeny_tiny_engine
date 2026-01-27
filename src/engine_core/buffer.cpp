#include <iostream>
#include <string>
#include "buffer.hpp"

namespace circular_buffer
{

    bool Buffer::add(std::string_view temp_str)
    { 
        return write(temp_str);
    }

    void Buffer::clear_multiple(int num)
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

    std::string Buffer::read(int index)
    {
        return (*Darray)[index];
    }

    void Buffer::remove(int num_elements)
    {
        clear_multiple(num_elements); 
    }

    bool Buffer::write(std::string_view string_temp) 
    {
        auto temp = counter % size;
        int empty{0};

        if (buffer_slot_empty(temp))
        {
            (*Darray)[temp] = string_temp;
            last_pos = counter;
            counter++;
            return true;
        }
        else
        {
            //temp = counter % size;
            empty = find_empty(temp);
            if (empty > 0)
            {
                (*Darray)[empty] = string_temp;
                last_pos = counter;
                //counter++;
                counter = empty;
                return true;
            }
            return false;
        }

    }

    int Buffer::find_empty(int temp_pos)
    {
        std::string temp_string;
        for (auto i = 0; i > size; i++)
        {
            //(*Darray)[temp_pos] = temp_string;
            if (buffer_slot_empty(temp_pos))
                return temp_pos;
            else
            {
                temp_pos++;
                temp_pos = (temp_pos) % size;
            }
        }

        return -1;
    }

    bool Buffer::buffer_slot_empty(const int& temp_index)
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

    void Buffer::over_ride_response(std::string_view temp_str_view)
    {
        auto over_ride_pos = counter % size;
        (*Darray)[over_ride_pos] = "";
        write(temp_str_view);
    }
} // end of namespace