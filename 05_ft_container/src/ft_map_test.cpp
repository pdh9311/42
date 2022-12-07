#include <iostream>
#include <string>
#include "map.hpp"

/** map
 ********************************************************************************
 *  (construct)             * begin                   * empty                   *
 *  (destruct)              * end                     * size                    *
 *  opeartor=               * rbegin                  * max_size                *
 *                          * rend                    *                         *
 ********************************************************************************
 *  operator[]              * key_comop               * get_allocator           *
 *                          * value_comp              *                         *
 ********************************************************************************
 *  insret                  * find                    * relational operators    *
 *  erase                   * count                   * swap                    *
 *  swap                    * lower_bound             *                         *
 *  clear                   * uppder_bound            *                         *
 *                          * equal_range             *                         *
 ********************************************************************************
 */

template <typename T>
void print_map(T t) {
    for (typename T::iterator it = t.begin(); it != t.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") | ";
    }
    std::cout << std::endl;
}

void test_ft_map() {
    ft::map<char, int> ft_default;
    ft_default['a'] = 10;
    ft_default['c'] = 30;
    ft_default['e'] = 50;
    ft_default['g'] = 70;
    ft::map<char, int> ft_range(ft_default.begin(), ft_default.end());
    ft::map<char, int> ft_copy(ft_range);
    ft::map<char, int> ft_assign;
    // operator=
    ft_assign = ft_default;
    ft_default = ft::map<char, int>();
    ft::map<char, int>::iterator it;

    // // begin, end
    for (ft::map<char, int>::iterator it = ft_assign.begin(); it != ft_assign.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") | ";
    }
    std::cout << std::endl;
    // rbegin, rend
    for (ft::map<char, int>::reverse_iterator rit = ft_range.rbegin(); rit != ft_range.rend(); ++rit) {
        std::cout << "(" << rit->first << ", " << rit->second << ") | ";
    }
    std::cout << std::endl;
    // empty, size, max_size
    if (ft_default.empty())
        std::cout << "default is empty" << std::endl;
    std::cout << "range.size() is " << ft_range.size() << std::endl;
    std::cout << "range.max_size() is " << ft_range.max_size() << std::endl;
    // operator[]
    std::cout << "range['a'] is " << ft_range['a'] << std::endl;
    std::cout << "range['c'] is " << ft_range['c'] << std::endl;
    ft_range['c'] = 3;
    std::cout << "range['c'] is " << ft_range['c'] << std::endl;
    std::cout << "range['e'] is " << ft_range['e'] << std::endl;
    std::cout << "range['g'] is " << ft_range['g'] << std::endl;

    // map은 키 값을 기준으로 정렬되어서 삽입된다.
    // insert (1)
    ft_range.insert(ft::pair<char,int>('h', 100));
    ft_range.insert(ft::pair<char,int>('j', 200));

    ft::pair<ft::map<char, int>::iterator, bool> ret;
    ret = ft_range.insert(ft::pair<char, int>('h', 300));
    if (ret.second == false) {
        std::cout << "element 'h' already existed with a value of " << ret.first->second << std::endl;
    }
    ret = ft_range.insert(ft::pair<char, int>('l', 300));
    if (ret.second == false) {
        std::cout << "element 'l' already existed with a value of " << ret.first->second << std::endl;
    } else {
        std::cout << "element 'l' inserted with a value of " << ret.first->second << std::endl;
    }
    print_map(ft_range);

    // insert(2)
    ft_range.insert(ft_range.begin(), ft::pair<char, int>('b', 1000));
    ft_range.insert(ft_range.end(), ft::pair<char, int>('d', 2000));
    print_map(ft_range);

    // insert (3)
    ft::map<char, int> anothermap;
    anothermap.insert(ft_range.begin(), ft_range.end());
    print_map(ft_range);

    // erase(1) + find
    it = ft_range.find('g');
    ft_range.erase(it);
    print_map(ft_range);

    // erase(2)
    ft_range.erase('h');
    print_map(ft_range);

    // erase(3) + find
    it = ft_range.find('c');
    ft_range.erase(it, ft_range.end());
    print_map(ft_range);

    // swap
    print_map(ft_default);
    ft_default.swap(ft_range);
    print_map(ft_default);
    print_map(ft_range);

    // clear
    print_map(ft_copy);
    ft_copy.clear();
    print_map(ft_copy);

    // key_comp
    print_map(ft_assign);
    ft::map<char, int>::key_compare comp = ft_assign.key_comp();
    char highest = ft_assign.rbegin()->first;
    it = ft_assign.begin();
    do {
        std::cout << "(" << it->first << ", " << it->second << ") | ";
    } while (comp((*it++).first, highest));
    std::cout << std::endl;
    // value_comp - iterator로 키값을 비교..
    ft_assign.insert(ft::pair<char, int>('d',100));
    print_map(ft_assign);
    it = ft_assign.begin();
    ft::pair<char, int> highest_iter = *ft_assign.rbegin();
    do {
        std::cout << "(" << it->first << ", " << it->second << ") | ";
    } while (ft_assign.value_comp()(*it++, highest_iter));
    std::cout << std::endl;

    // count - key의 개수를 확인
    print_map(ft_assign);
    char c;
    for (c = 'a'; c < 'h'; c++) {
        std::cout << c;
        if (ft_assign.count(c) > 0)
            std::cout << " is an element of assign." << std::endl;
        else
            std::cout << " is not an element of assign." << std::endl;
    }

    // lower_bound, upper_bound
    ft::map<char, int>::iterator itlow, itup;
    itlow = ft_assign.lower_bound('c');
    itup = ft_assign.upper_bound('e');
    ft_assign.erase(itlow, itup);
    print_map(ft_assign);

    // equal_range
    ft::map<char, int> ft_mymap;

    ft_mymap['a'] = 10;
    ft_mymap['b'] = 20;
    ft_mymap['c'] = 30;

    ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> result;
    result = ft_mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << result.first->first << " => " << result.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << result.second->first << " => " << result.second->second << std::endl;
}

int main(void) {
    test_ft_map();
    return 0;
}