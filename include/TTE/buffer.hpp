#pragma once

#include <string>
#include <memory>
#include <vector>

namespace r_buffer
{
    class Ring_buffer
    {
        private:
            int size;
            std::shared_ptr<std::vector<std::string>> Darray;
            std::string temp_string;

            int counter{0};
            int last_pos{0};
        
        public:

            // element access function
            int find_empty(int temp_pos);
            // element access function
            std::string at(int index);

            // modifier function
            void pop_range(int num);
            // modifier function
            bool erase(int temp_index);
            // modifier function
            bool append(std::string_view temp_str);
            // modifier function
            void pop_back(int num_elements);
            // modifier function
            void assign(std::string_view temp_str);

            Ring_buffer(int num) : size(num), Darray(std::make_shared<std::vector<std::string>>(size)) {};

    };
} // end of namespace

