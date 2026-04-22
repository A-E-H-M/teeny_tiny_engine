#pragma once

//#include <cassert>
#include <array>

/*
* It is a buffer that automatically wraps to the beginning of the buffer once the buffer has reached its end.
*/

namespace R_BUFFER
{
    template <typename T, std::size_t SZ>
    class Ring_buffer
    {
        private:
            //const std::size_t size;
            std::array<T, SZ> Darray;

            //std::size_t counter{0};
            std::size_t last_pos{0};
        
        public:
            /*
            // element access function, returns the oldest element appended to the buffer, read only
            const T end()
            {
                auto temp_end = (last_pos + Darray.size()) % Darray.size();
                return Darray[temp_end];
            }
            */

            // element access function, returns the latest element appended to the buffer, read only
            const T last()
            {
                auto temp_last = (last_pos + Darray.size() - 1) % Darray.size();
                return Darray[temp_last];
            }

            // element access function, read only
            const T at(std::size_t index)
            {
                //assert (index <= Darray.size());
                //assert (index >= 0);

                return Darray[index];
            }

            // capacity assessment
            const std::size_t size_of() 
            {   
                return Darray.size();
            };

            /*
            // modifier function, clears the contents of the buffer
            void clear()
            {
                Darray.clear();
            }
            */

            // modifier function, adds element to the next index space
            void add(const T& element)
            {
                Darray[last_pos % Darray.size()] = element;
                ++last_pos;
            }

            // modifier function
            void assign(std::size_t index, const T& element)
            {
                //assert (index <= Darray.size() && "Index outside of bounds");
                //assert (index >= 0 && "Index must be positive value");
                Darray[index] = element;
            }

    };

} // end of namespace