#include <iostream>
#include <iomanip>
#include <string>
#include "vector.hpp"

/** vector
 ********************************************************************************
 *  (construct)             * begin                   * size                    *
 *  (destruct)              * end                     * max_size                *
 *  opeartor=               * rbegin                  * resize                  *
 *                          * rend                    * capacity                *
 *                          *                         * empty                   *
 *                          *                         * reserve                 *
 ********************************************************************************
 *  operator[]              * assign                  * get_allocator           *
 *  at                      * push_back               ***************************
 *  front                   * pop_back                * relational operators    *
 *  back                    * insert                  * swap                    *
 *                          * erase                   ***************************
 *                          * swap                    *                         *
 *                          * clear                   *                         *
 ********************************************************************************
 */

template <typename T>
void print_vector(T& t, std::string str) {
    std::cout << "(size: "  << std::setw(2) << t.size() << ", capacity: " << std::setw(2)  << t.capacity() << ") | ";
    for(size_t i = 0; i < t.size(); ++i) {
        std::cout << std::setw(2) << t.at(i) << " | ";
    }
    std::cout << "\t <- " << str << std::endl;
}

void test_ft_vector(void) {
    ft::vector<int> ft_default;
    ft::vector<int> ft_fill(3, 1);  // 1, 1, 1
    ft::vector<int> ft_range(ft_fill.begin(), ft_fill.end());  // 1, 1, 1
    ft::vector<int> ft_copy(ft_range);  // 1, 1, 1
    ft::vector<int> ft_assign;
    ft_assign = ft_default;

    ft_fill.begin();
    ft_fill.end();
    ft_fill.rbegin();
    ft_fill.rend();
    ft_fill.size();
    print_vector(ft_fill, "size");
    ft_fill.max_size();
    ft_fill.resize(10);
    print_vector(ft_fill, "resize");
    ft_fill.capacity();
    ft_fill.empty();
    ft_fill.reserve(20);
    print_vector(ft_fill, "reserve");

    ft_fill[3];
    ft_fill.at(3);
    ft_fill.front();
    ft_fill.back();

    ft_fill.assign(ft_copy.begin(), ft_copy.end());  // range
    print_vector(ft_fill, "assign range");
    ft_fill.assign(5, 10);  // fill
    print_vector(ft_fill, "assign fill");
    ft_fill.push_back(77);
    print_vector(ft_fill, "push_back");
    ft_fill.pop_back();
    print_vector(ft_fill, "pop_back");

    ft_fill.insert(ft_fill.begin(), 20);  // single element
    print_vector(ft_fill, "insert single element");
    ft_fill.insert(ft_fill.begin() + 5, 4, 80);  // fill
    print_vector(ft_fill, "insert fill 4");
    ft_fill.insert(ft_fill.begin() + 5, 15, 22);  // fill
    print_vector(ft_fill, "insert fill 22");
    ft_fill.insert(ft_fill.begin() + 10, ft_copy.begin(), ft_copy.begin() + 3);  // range
    print_vector(ft_fill, "insert range");

    ft_fill.erase(ft_fill.begin() + 2);
    print_vector(ft_fill, "erase1");
    ft_fill.erase(ft_fill.begin() + 1, ft_fill.begin() + 4);
    print_vector(ft_fill, "erase2");

    ft_fill.swap(ft_range);
    print_vector(ft_fill, "swap");
    ft_fill.clear();
    print_vector(ft_fill, "clear");

    ft_fill.get_allocator();

}

int main(void) {
    test_ft_vector();
    return 0;
}