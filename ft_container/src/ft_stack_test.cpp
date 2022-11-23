#include <iostream>
#include "stack.hpp"

/** stack
 ****************************
 *  (construct)             *
 *  empty                   *
 *  size                    *
 *  top                     *
 *  push                    *
 *  pop                     *
 *  relational operators    *
 ****************************
 */

void test_ft_stack(void) {
    ft::stack<int> ft_stack;

    for (int i = 0; i < 5; i++) {
        ft_stack.push(i);
    }
    int n = ft_stack.size();
    while (n--) {
        std::cout << ft_stack.top() << " | ";
        ft_stack.pop();
    }
    std::cout << std::endl;
}

int main() {
    test_ft_stack();
    return 0;
}