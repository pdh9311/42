#include <iostream>
#include <string>
#include "set.hpp"

/** set
 ********************************************************************************
 *  (construct)             * begin                   * empty                   *
 *  (destruct)              * end                     * size                    *
 *  opeartor=               * rbegin                  * max_size                *
 *                          * rend                    *                         *
 ********************************************************************************
 *  insret                  * find                    * relational operators    *
 *  erase                   * count                   * swap                    *
 *  swap                    **lower_bound             ***************************
 *  clear                   * uppder_bound            *                         *
 **************************** equal_range             *                         *
 *  key_comop               ***************************                         *
 *  value_comp              * get_allocator           *                         *
 ********************************************************************************
 */

template <typename T>
void print_set(T t) {
    for (typename T::iterator it = t.begin(); it != t.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test_ft_set() {
    // construct (1)
    ft::set<int> ft_default;
    ft_default.insert(10);
    ft_default.insert(50);
    ft_default.insert(70);
    ft_default.insert(90);
    // construct (2)
    ft::set<int> ft_range(ft_default.begin(), ft_default.end());
    // construct (3)
    ft::set<int> ft_copy(ft_default);

    // assignment
    ft::set<int> ft_assign;
    ft_assign = ft_default;
    ft_default = ft::set<int>();

    ft::set<int>::iterator it;
    for (it = ft_range.begin(); it != ft_range.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    ft::set<int>::reverse_iterator rit;
    for (rit = ft_range.rbegin(); rit != ft_range.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    if (ft_default.empty()) {
        std::cout << "default is empty!" << std::endl;
    }

    std::cout << "default:\t" << ft_default.size() << " | " << ft_default.max_size() << std::endl;
    std::cout << "range:\t" << ft_range.size() << " | " << ft_range.max_size() << std::endl;
    std::cout << "copy:\t" << ft_copy.size() << " | " << ft_copy.max_size() << std::endl;
    std::cout << "assign:\t" << ft_assign.size() << " | " << ft_assign.max_size() << std::endl;

    // insert(1)
    ft::pair<ft::set<int>::iterator, bool> ret;
    ret = ft_range.insert(20);
    if (ret.second == false) std::cout << "20 is already exist" << std::endl;
    else std::cout << "20 inserted" << std::endl;

    ret = ft_range.insert(50);
    if (ret.second == false) std::cout << "50 is already exist" << std::endl;
    else std::cout << "50 inserted" << std::endl;

    // insert(2)
    it = ft_range.begin();
    ft_range.insert(it, 30);
    ft_range.insert(it, 32);
    ft_range.insert(it, 1);
    print_set(ft_range);

    // insert(3)
    ft_default.insert(ft_range.begin(), ft_range.end());
    print_set(ft_default);

    // erase(1), find
    it = ft_range.find(32);
    ft_range.erase(it);
    print_set(ft_range);

    // erase(2)
    ft_range.erase(30);
    print_set(ft_range);

    // erase(3), find
    ft_range.erase(ft_range.find(20), ft_range.find(70));
    print_set(ft_range);

    std::cout << "default: ";
    print_set(ft_default);
    std::cout << "range: ";
    print_set(ft_range);
    ft_default.swap(ft_range);
    std::cout << "default: ";
    print_set(ft_default);
    std::cout << "range: ";
    print_set(ft_range);

    // clear
    ft_default.clear();
    std::cout << "default size: " << ft_default.size() << std::endl;

    // key_comp ,value_comp
    print_set(ft_range);
    int highest;
    ft::set<int>::key_compare mycomp = ft_range.key_comp();
    highest = *ft_range.rbegin();
    it = ft_range.begin();
    do {
        std::cout << *it << ' ';
    } while ( mycomp(*(it++), highest) );

    std::cout << std::endl;

    // count
    ft::set<int> myset;

    // set some initial values:
    for (int i = 1; i < 5; ++i) myset.insert(i*3);    // set: 3 6 9 12

    for (int i = 0; i < 10; ++i) {
        std::cout << i;
        if (myset.count(i) != 0)
            std::cout << " is an element of myset.\n";
        else
            std::cout << " is not an element of myset.\n";
    }

    // lower_bound, upper_bound
    ft::set<int>::iterator itlow, itup;
    itlow = ft_range.lower_bound(20);
    itup = ft_range.upper_bound(70);
    ft_range.erase(itlow, itup);
    print_set(ft_range);

    // equal_range
    print_set(ft_assign);
    ft::pair<ft::set<int>::const_iterator, ft::set<int>::const_iterator> result;
    result = ft_assign.equal_range(50);
    std::cout << "the lower bound points to: " << *result.first << std::endl;
    std::cout << "the upper bound points to: " << *result.second << std::endl;

    // get_allocator
    std::allocator<int> alloc;
    int *p;

    alloc = ft_assign.get_allocator();
    p = alloc.allocate(5);
    alloc.deallocate(p, 5);
}

int main(void) {
    test_ft_set();
    return 0;
}