#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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

void test_std_vector(void) {
    std::vector<int> std_default;
    std::vector<int> std_fill(3, 1);  // 1, 1, 1
    std::vector<int> std_range(std_fill.begin(), std_fill.end());  // 1, 1, 1
    std::vector<int> std_copy(std_range);  // 1, 1, 1
    std::vector<int> std_assign;
    std_assign = std_default;

    std_fill.begin();
    std_fill.end();
    std_fill.rbegin();
    std_fill.rend();
    std_fill.size();
    print_vector(std_fill, "size");
    std_fill.max_size();
    std_fill.resize(10);
    print_vector(std_fill, "resize");
    std_fill.capacity();
    std_fill.empty();
    std_fill.reserve(20);
    print_vector(std_fill, "reserve");

    std_fill[3];
    std_fill.at(3);
    std_fill.front();
    std_fill.back();

    std_fill.assign(std_copy.begin(), std_copy.end());  // range
    print_vector(std_fill, "assign range");
    std_fill.assign(5, 10);  // fill
    print_vector(std_fill, "assign fill");
    std_fill.push_back(77);
    print_vector(std_fill, "push_back");
    std_fill.pop_back();
    print_vector(std_fill, "pop_back");

    std_fill.insert(std_fill.begin(), 20);  // single element
    print_vector(std_fill, "insert single element");
    std_fill.insert(std_fill.begin() + 5, 4, 80);  // fill
    print_vector(std_fill, "insert fill 4");
    std_fill.insert(std_fill.begin() + 5, 15, 22);  // fill
    print_vector(std_fill, "insert fill 22");
    std_fill.insert(std_fill.begin() + 10, std_copy.begin(), std_copy.begin() + 3);  // range
    print_vector(std_fill, "insert range");

    std_fill.erase(std_fill.begin() + 2);
    print_vector(std_fill, "erase1");
    std_fill.erase(std_fill.begin() + 1, std_fill.begin() + 4);
    print_vector(std_fill, "erase2");

    std_fill.swap(std_range);
    print_vector(std_fill, "swap");
    std_fill.clear();
    print_vector(std_fill, "clear");

    std_fill.get_allocator();
}

int main(void) {
    test_std_vector();
    return 0;
}