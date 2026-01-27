#pragma once

#include <string>
#include <memory>
#include <vector>

namespace circular_buffer
{
    class Buffer
    {
        private:
            int size;
            std::shared_ptr<std::vector<std::string>> Darray;
            std::string temp_string;

            int counter{0};
            int last_pos{0};

            bool write(std::string_view string_temp);
            void clear_multiple(int num);
            bool buffer_slot_empty(const int& temp_index);
            int find_empty(int temp_pos);
        
        public:
            std::string read(int index);
            bool add(std::string_view temp_str);
            void remove(int num_elements);
            void over_ride_response(std::string_view temp_str);

            Buffer(int num) : size(num) 
            {
                Darray = std::make_shared<std::vector<std::string>>(size);
            }

    };
} // end of namespace

