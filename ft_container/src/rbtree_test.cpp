#include <iostream>
#include <string>
#include "rbtree.hpp"

template<typename T>
void print_rbtree(T t) {
    typename T::iterator it;
    for(it = t.begin(); it != t.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

/**
 *  _destruct_node에서 소멸되는 순서도 확인하면 좋을 듯
 *        13
 *      /    \
 *     8     17
 *    / \    /  \
 *   1  11  15  25
 *    \         / \
 *     6       22  27
 *
 * 6 → 1 → 11 → 8 → 15 → 22 → 27 → 25 → 17 → 13
 */
void test_rbtree_insert() {
    std::cout << "================== test_rbtree_insert ==================" << std::endl;
    ft::rbtree<int, int> rbtree;
    rbtree.insert(13);
    rbtree.insert(8);
    rbtree.insert(17);
    rbtree.insert(1);
    rbtree.insert(11);
    rbtree.insert(15);
    rbtree.insert(25);
    rbtree.insert(6);
    rbtree.insert(22);
    rbtree.insert(27);

    print_rbtree(rbtree);
}

/**
 *        7
 *      /    \
 *     3     13
 *    / \   /  \
 *   1   5  9  15
 *          \
 *          11
 *********************
 *        9
 *      /    \
 *     3     13
 *    / \   /  \
 *   1   5 11  15
 *********************
 *        9
 *      /    \
 *     3     13
 *    / \   /  \
 *   1   5 nil   15
 *
 */
void test_rbtree_erase() {
    std::cout << "================== test_rbtree_erase ==================" << std::endl;
    ft::rbtree<int, int> rbtree;
    ft::rbtree<int, int>::iterator itr;

    rbtree.insert(7);    rbtree.insert(3);    rbtree.insert(13);    rbtree.insert(1);
    rbtree.insert(5);    rbtree.insert(9);    rbtree.insert(15);    rbtree.insert(11);
    print_rbtree(rbtree);

    rbtree.erase(7);
    rbtree.erase(11);

    itr = rbtree.begin();
    rbtree.erase(itr);
    print_rbtree(rbtree);
}

void test_remain() {
    std::cout << "================== test_remain ==================" << std::endl;
    ft::rbtree<int, int> rbtree;

    rbtree.insert(13);
    rbtree.insert(8);
    rbtree.insert(17);
    rbtree.insert(1);
    rbtree.insert(11);
    rbtree.insert(15);
    rbtree.insert(25);
    rbtree.insert(6);
    rbtree.insert(22);
    rbtree.insert(27);
    print_rbtree(rbtree);

    std::cout << *rbtree.lower_bound(7) << std::endl;
    std::cout << *rbtree.upper_bound(14) << std::endl;


    ft::pair<ft::rbtree<int,int>::iterator, ft::rbtree<int,int>::iterator> result;
    result = rbtree.equal_range(11);

    std::cout << "lower bound points to upper bound points : ";
    std::cout << *(result.first) << " => " << *(result.second) << std::endl;

    result = rbtree.equal_range(9);
    std::cout << "lower bound points to upper bound points : ";
    std::cout << *(result.first) << " => " << *(result.second) << std::endl;
}

int main(void) {
    test_rbtree_insert();
    test_rbtree_erase();
    test_remain();
    return 0;
}
