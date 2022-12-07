#include <iostream>
#include <string>
#include <map>


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

void test_std_map() {
    std::map<char, int> std_default;
    std_default['a'] = 10;
    std_default['c'] = 30;
    std_default['e'] = 50;
    std_default['g'] = 70;
    std::map<char, int> std_range(std_default.begin(), std_default.end());
    std::map<char, int> std_copy(std_range);
    std::map<char, int> std_assign;
    // operator=
    std_assign = std_default;
    std_default = std::map<char, int>();
    std::map<char, int>::iterator it;

    // begin, end
    for (std::map<char, int>::iterator it = std_assign.begin(); it != std_assign.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") | ";
    }
    std::cout << std::endl;
    // rbegin, rend
    for (std::map<char, int>::reverse_iterator rit = std_range.rbegin(); rit != std_range.rend(); ++rit) {
        std::cout << "(" << rit->first << ", " << rit->second << ") | ";
    }
    std::cout << std::endl;
    // empty, size, max_size
    if (std_default.empty())
        std::cout << "default is empty" << std::endl;
    std::cout << "range.size() is " << std_range.size() << std::endl;
    std::cout << "range.max_size() is " << std_range.max_size() << std::endl;
    // operator[]
    std::cout << "range['a'] is " << std_range['a'] << std::endl;
    std::cout << "range['c'] is " << std_range['c'] << std::endl;
    std_range['c'] = 3;
    std::cout << "range['c'] is " << std_range['c'] << std::endl;
    std::cout << "range['e'] is " << std_range['e'] << std::endl;
    std::cout << "range['g'] is " << std_range['g'] << std::endl;

    // map은 키 값을 기준으로 정렬되어서 삽입된다.
    // insert (1)
    std_range.insert(std::pair<char,int>('h', 100));
    std_range.insert(std::pair<char,int>('j', 200));

    std::pair<std::map<char, int>::iterator, bool> ret;
    ret = std_range.insert(std::pair<char, int>('h', 300));
    if (ret.second == false) {
        std::cout << "element 'h' already existed with a value of " << ret.first->second << std::endl;
    }
    ret = std_range.insert(std::pair<char, int>('l', 300));
    if (ret.second == false) {
        std::cout << "element 'l' already existed with a value of " << ret.first->second << std::endl;
    } else {
        std::cout << "element 'l' inserted with a value of " << ret.first->second << std::endl;
    }
    print_map(std_range);
    // insert(2)
    std_range.insert(std_range.begin(), std::pair<char, int>('b', 1000));
    std_range.insert(std_range.end(), std::pair<char, int>('d', 2000));
    print_map(std_range);
    // insert (3)
    std::map<char, int> anothermap;
    anothermap.insert(std_range.begin(), std_range.end());
    print_map(std_range);

    // erase(1)

    it = std_range.find('g');
    std_range.erase(it);
    print_map(std_range);

    // erase(2)
    std_range.erase('h');
    print_map(std_range);

    // erase(3)
    it = std_range.find('c');
    std_range.erase(it, std_range.end());
    print_map(std_range);

    // swap
    print_map(std_default);
    std_default.swap(std_range);
    print_map(std_default);
    print_map(std_range);

    // clear
    print_map(std_copy);
    std_copy.clear();
    print_map(std_copy);

    // key_comp
    print_map(std_assign);
    std::map<char, int>::key_compare comp = std_assign.key_comp();
    char highest = std_assign.rbegin()->first;
    it = std_assign.begin();
    do {
        std::cout << "(" << it->first << ", " << it->second << ") | ";
    } while (comp((*it++).first, highest));
    std::cout << std::endl;
    // value_comp - iterator로 키값을 비교..
    std_assign.insert(std::pair<char, int>('d',100));
    print_map(std_assign);
    it = std_assign.begin();
    std::pair<char, int> highest_iter = *std_assign.rbegin();
    do {
        std::cout << "(" << it->first << ", " << it->second << ") | ";
    } while (std_assign.value_comp()(*it++, highest_iter));
    std::cout << std::endl;

    // find
    it = std_assign.find('a');

    // count - key의 개수를 확인
    print_map(std_assign);
    char c;
    for (c = 'a'; c < 'h'; c++) {
        std::cout << c;
        if (std_assign.count(c) > 0)
            std::cout << " is an element of assign." << std::endl;
        else
            std::cout << " is not an element of assign." << std::endl;
    }

    // lower_bound, upper_bound
    std::map<char, int>::iterator itlow, itup;
    itlow = std_assign.lower_bound('c');
    itup = std_assign.upper_bound('e');
    std_assign.erase(itlow, itup);
    print_map(std_assign);

    // equal_range
    std::map<char, int> std_mymap;

    std_mymap['a'] = 10;
    std_mymap['b'] = 20;
    std_mymap['c'] = 30;

    std::pair<std::map<char,int>::iterator, std::map<char,int>::iterator> result;
    result = std_mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << result.first->first << " => " << result.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << result.second->first << " => " << result.second->second << std::endl;
}

int main(void) {
    test_std_map();
    return 0;
}