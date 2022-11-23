#include <iostream>
#include <stack>

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

void test_std_stack(void) {
    std::stack<int> std_stack;

    for (int i = 0; i < 5; i++) {
        std_stack.push(i);
    }
    int n = std_stack.size();
    while (n--) {
        std::cout << std_stack.top() << " | ";
        std_stack.pop();
    }
    std::cout << std::endl;
}

int main() {
    test_std_stack();
    return 0;
}