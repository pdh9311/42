#include <iostream>
#include <string>
#include <set>

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

void test_std_set() {
    // construct (1)
    std::set<int> std_default;
    std_default.insert(10);
    std_default.insert(50);
    std_default.insert(70);
    std_default.insert(90);
    // construct (2)
    std::set<int> std_range(std_default.begin(), std_default.end());
    // construct (3)
    std::set<int> std_copy(std_default);

    // assignment
    std::set<int> std_assign;
    std_assign = std_default;
    std_default = std::set<int>();

    std::set<int>::iterator it;
    for (it = std_range.begin(); it != std_range.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::set<int>::reverse_iterator rit;
    for (rit = std_range.rbegin(); rit != std_range.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    if (std_default.empty())
        std::cout << "default is empty!" << std::endl;

    std::cout << "default:\t" << std_default.size() << " | " << std_default.max_size() << std::endl;
    std::cout << "range:\t" << std_range.size() << " | " << std_range.max_size() << std::endl;
    std::cout << "copy:\t" << std_copy.size() << " | " << std_copy.max_size() << std::endl;
    std::cout << "assign:\t" << std_assign.size() << " | " << std_assign.max_size() << std::endl;

    // insert(1)
    std::pair<std::set<int>::iterator, bool> ret;
    ret = std_range.insert(20);
    if (ret.second == false) std::cout << "20 is already exist" << std::endl;
    else std::cout << "20 inserted" << std::endl;

    ret = std_range.insert(50);
    if (ret.second == false) std::cout << "50 is already exist" << std::endl;
    else std::cout << "50 inserted" << std::endl;

    // insert(2)
    it = std_range.begin();
    std_range.insert(it, 30);
    std_range.insert(it, 32);
    std_range.insert(it, 1);
    print_set(std_range);

    // insert(3)
    std_default.insert(std_range.begin(), std_range.end());
    print_set(std_default);

    // erase(1), find
    it = std_range.find(32);
    std_range.erase(it);
    print_set(std_range);

    // erase(2)
    std_range.erase(30);
    print_set(std_range);

    // erase(3), find
    std_range.erase(std_range.find(20), std_range.find(70));
    print_set(std_range);

    std::cout << "default: ";
    print_set(std_default);
    std::cout << "range: ";
    print_set(std_range);
    std_default.swap(std_range);
    std::cout << "default: ";
    print_set(std_default);
    std::cout << "range: ";
    print_set(std_range);

    // clear
    std_default.clear();
    std::cout << "default size: " << std_default.size() << std::endl;

    // key_comp ,value_comp
    print_set(std_range);
    int highest;
    std::set<int>::key_compare mycomp = std_range.key_comp();
    highest = *std_range.rbegin();
    it = std_range.begin();
    do {
        std::cout << *it << ' ';
    } while ( mycomp(*(it++), highest) );

    std::cout << std::endl;

    // count
    std::set<int> myset;

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
    std::set<int>::iterator itlow, itup;
    itlow = std_range.lower_bound(20);
    itup = std_range.upper_bound(70);
    std_range.erase(itlow, itup);
    print_set(std_range);

    // equal_range
    print_set(std_assign);
    std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> result;
    result = std_assign.equal_range(50);
    std::cout << "the lower bound points to: " << *result.first << std::endl;
    std::cout << "the upper bound points to: " << *result.second << std::endl;

    // get_allocator
    std::allocator<int> alloc;
    int *p;

    alloc = std_assign.get_allocator();
    p = alloc.allocate(5);
    alloc.deallocate(p, 5);
}

int main(void) {
    test_std_set();
    return 0;
}