#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <memory>
# include <cstddef>     // std::size_t
# include <algorithm>
# include <limits>
# include "iterator_traits.hpp"
# include "type_traits.hpp"
# include "utils.hpp"
# include "algorithm.hpp"

namespace ft {

/* tree node */
template <typename T>
struct tree_node {
    typedef T value_type;
    typedef bool binary_type;

    tree_node*  _parent;
    tree_node*  _left;
    tree_node*  _right;
    value_type  _value;
    binary_type _is_black;

    tree_node() : _parent(ft::nil), _left(ft::nil), _right(ft::nil), _value(ft::nil), _is_black(binary_type()) {}
    tree_node(const value_type& val) : _parent(ft::nil), _left(ft::nil), _right(ft::nil), _value(val), _is_black(binary_type()) {}
    tree_node(const tree_node& n) : _parent(n._parent), _left(n._left), _right(n._right), _value(n._value), _is_black(n._is_black) {}
    ~tree_node() {}
    tree_node& operator=(const tree_node& n) {
        if (this != &n) {
            _parent = n._parent;
            _left = n._left;
            _right = n._right;
            _value = n._value;
            _is_black = n._is_black;
        }
        return *this;
    }
};
template <class NodePtr>
bool is_left_child(const NodePtr& ptr) { return ptr == ptr->_parent->_left; }

template <class NodePtr>
bool is_right_child(const NodePtr& ptr) { return ptr == ptr->_parent->_right; }

template <class NodePtr>
bool is_black_color(const NodePtr& ptr) { return ptr->_is_black; }

template <class NodePtr>
bool is_red_color(const NodePtr& ptr) { return !ptr->_is_black; }

template <class NodePtr>
NodePtr get_min_node(NodePtr ptr, NodePtr nil) {
    while (ptr->_left != nil) {
        ptr = ptr->_left;
    }
    return ptr;
}

template <class NodePtr>
NodePtr get_max_node(NodePtr ptr, NodePtr nil) {
    while (ptr->_right != nil) {
        ptr = ptr->_right;
    }
    return ptr;
}

// 만약 ptr이 tree의 max_node인 경우 prev node를 반환 한다.
template <class NodePtr>
NodePtr get_next_node(NodePtr ptr, NodePtr nil) {
    if (ptr->_right != nil) {
        return get_min_node(ptr->_right, nil);
    }
    while (!is_left_child(ptr)) {
        ptr = ptr->_parent;
    }
    return ptr->_parent;
}

// 만약 ptr이 tree의 min node인 경우 next node를 반환 한다.
template <class NodePtr>
NodePtr get_prev_node(NodePtr ptr, NodePtr nil) {
    if (ptr->_left != nil) {
        return get_max_node(ptr->_left, nil);
    }
    while (!is_right_child(ptr)) {
        ptr = ptr->_parent;
    }
    return ptr->_parent;
}

template <typename U, typename V, class Comp>
bool _is_equal(const U& u, const V& v, Comp _comp) {
    return !_comp(u, v) && !_comp(v, u);
}

/* tree_iterator */
template <typename U, typename V>
class tree_iterator {
public:
    typedef U                                                               value_type;
    typedef value_type*                                                     pointer;
    typedef value_type&                                                     reference;
    typedef V*                                                              iterator_type;
    typedef typename ft::iterator_traits<iterator_type>::difference_type    difference_type;
    typedef typename ft::iterator_traits<iterator_type>::value_type         node_type;
    typedef typename ft::iterator_traits<iterator_type>::pointer            node_pointer;
    typedef typename ft::iterator_traits<iterator_type>::reference          node_reference;
    typedef typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;

private:
    node_pointer _cur;
    node_pointer _nil;

public:
    /* constructor & destructor & assignment */
    tree_iterator() : _cur(ft::nil), _nil(ft::nil) {}
    tree_iterator(node_pointer cur, node_pointer nil) : _cur(cur), _nil(nil) {}
    tree_iterator(const tree_iterator& i) : _cur(i._cur), _nil(i._nil) {}
    ~tree_iterator() {}
    tree_iterator& operator=(const tree_iterator& i) {
        if (this != &i) {
            _cur = i._cur;
            _nil = i._nil;
        }
        return *this;
    }

    /* member function */
    node_pointer base() const { return _cur; }
    pointer operator->() const { return &(_cur->_value); }
    reference operator*() const { return _cur->_value; }

    tree_iterator& operator++() {
        _cur = ft::get_next_node(_cur, _nil);
        return *this;
    }
    tree_iterator& operator--() {
        _cur = ft::get_prev_node(_cur, _nil);
        return *this;
    }
    tree_iterator operator++(int) {
        tree_iterator tmp(*this);
        ++(*this);
        return tmp;
    }
    tree_iterator operator--(int) {
        tree_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    /* relational operators */
    template <typename T>
    bool operator==(const tree_iterator<T, node_type>& i) const {
        return _cur == i.base();
    }
    template <typename T>
    bool operator!=(const tree_iterator<T, node_type>& i) const {
        return !(*this == i);
    }
};

template <typename T, class Key, class Comp = std::less<Key>, class Alloc = std::allocator<T> >
class rbtree {
public:
    typedef T                                                           value_type;
    typedef Key                                                         key_type;
    typedef Comp                                                        compare_type;

    typedef tree_node<value_type>                                       node_type;
    typedef tree_node<value_type>*                                      node_pointer;
    typedef tree_iterator<value_type, node_type>                        iterator;
    typedef tree_iterator<const value_type, node_type>                  const_iterator;

    typedef Alloc                                                       allocator_type;
    typedef typename allocator_type::template rebind<node_type>::other  node_allocator;
    typedef std::allocator_traits<node_allocator>                       node_traits;

    typedef std::size_t                                                 size_type;
    typedef std::ptrdiff_t                                              difference_type;

private:
    node_pointer    _nil;      // tree_node
    node_pointer    _begin;    // tree_node
    node_pointer    _end;      // tree_node
    compare_type    _comp;
    node_allocator  _alloc;
    size_type       _size;

public:
    /* construct & destruct & assignment */
    rbtree(const compare_type& _comp = std::less<Key>(), const allocator_type& alloc = std::allocator<T>())
        : _comp(_comp), _alloc(alloc), _size(size_type()) {
        _construct_nil_node();
        _end = _construct_node(value_type());
        _end->_is_black = true;
        _begin = _end;
    }
    rbtree(const rbtree& t) : _comp(t._comp), _alloc(t._alloc), _size(size_type()) {
        _construct_nil_node();
        _end = _construct_node(value_type());
        _end->_is_black = true;
        _begin = _end;
        insert(t.begin(), t.end());
    }
    ~rbtree() {
        _destruct_node_recursive(_end);
        _destruct_node(_nil);
    }
    rbtree& operator=(const rbtree& t) {
        if (this != &t) {
            rbtree tmp(t);
            swap(tmp);
        }
        return *this;
    }

    /* member function */
    iterator begin() { return iterator(_begin, _nil); }
    const_iterator begin() const { return const_iterator(_begin, _nil); }
    iterator end() { return iterator(_end, _nil); }
    const_iterator end() const { return const_iterator(_end, _nil); }

    size_type size() const { return _size; }
    size_type max_size() const {
        return std::min<size_type>(std::numeric_limits<size_type>::max(), node_traits::max_size(node_allocator()));
    }
    bool empty() const { return _size == 0; }

    ft::pair<iterator, bool> insert(const value_type& val) {
        node_pointer ptr = _search_parent(val);                     // 값이 들어가 부모노드를 찾고
        if (ptr != _end && _is_equal(ptr->_value, val, _comp)) {    // 만약 값이 들어갈 노드의 부모를 찾았고, 부모노드의 값과 같다면
            return ft::make_pair(iterator(ptr, _nil), false);       // 이미 존재하는 값이므로 추가하지 않는다.
        }
        return ft::make_pair(iterator(_insert_internal(val, ptr), _nil), true); //
    }

    iterator insert(iterator position, const value_type& val) {
        node_pointer ptr = _search_parent(val, position.base());
        if (ptr != _end && _is_equal(ptr->_value, val, _comp)) {
            return iterator(ptr, _nil);
        }
        return iterator(_insert_internal(val, ptr), _nil);
    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        while (first != last) {
            insert(*(first++));
        }
    }

    iterator erase(iterator position) {
        if (_size == 0) {
            return iterator(_nil, _nil);
        }
        iterator tmp(position);
        ++tmp;
        if (position == begin()) {
            _begin = tmp.base();
        }
        --_size;
        _remove_internal(position.base());
        _destruct_node(position.base());
        return tmp;
    }

    template <typename U>
    size_type erase(const U& val) {
        iterator i(_find_internal(val), _nil);
        if (i == end()) {
            return 0;
        }
        if (i == begin()) {
            iterator tmp(i);
            ++tmp;
            _begin = tmp.base();
        }
        --_size;
        _remove_internal(i.base());
        _destruct_node(i.base());
        return 1;
    }

    void erase(iterator first, iterator last) {
        while (first != last) {
            first = erase(first);
        }
    }

    void swap(rbtree& t) {
        std::swap(_nil, t._nil);
        std::swap(_begin, t._begin);
        std::swap(_end, t._end);
        std::swap(_comp, t._comp);
        std::swap(_alloc, t._alloc);
        std::swap(_size, t._size);
    }

    void clear() {
        rbtree tmp(_comp, _alloc);
        swap(tmp);
    }

    iterator find(const key_type& key) {
        return iterator(_find_internal(key), _nil);
    }
    const_iterator find(const key_type& key) const {
        return const_iterator(_find_internal(key), _nil);
    }
    iterator lower_bound(const key_type& key) {
        return iterator(_lower_bound_internal(key), _nil);
    }
    const_iterator lower_bound(const key_type& key) const {
        return const_iterator(_lower_bound_internal(key), _nil);
    }
    iterator upper_bound(const key_type& key) {
        return iterator(_upper_bound_internal(key), _nil);
    }
    const_iterator upper_bound(const key_type& key) const {
        return const_iterator(_upper_bound_internal(key), _nil);
    }
    ft::pair<iterator, iterator> equal_range(const key_type& key) {
        return _equal_range_internal(key);
    }
    ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
        return _equal_range_internal(key);
    }

    allocator_type get_allocator() const {
        return _alloc;
    }

private:
    /* root */
    node_pointer _get_root() const {
        return _end->_left;
    }
    // ptr와 _end를 연결시키주는 함수
    void _set_root(const node_pointer ptr) {
        ptr->_parent = _end;
        _end->_left = ptr;
    }

    /* modifiers */
    void _construct_nil_node(void) {
        _nil = _alloc.allocate(1);
        _alloc.construct(_nil, value_type());
        _nil->_is_black = true;
        _nil->_parent = _nil;
        _nil->_left = _nil;
        _nil->_right = _nil;
    }

    node_pointer _construct_node(const value_type& val) {
        node_pointer ptr = _alloc.allocate(1);
        _alloc.construct(ptr, val);
        ptr->_parent = _nil;
        ptr->_left = _nil;
        ptr->_right = _nil;
        ptr->_is_black = false;
        return ptr;
    }

    void _destruct_node(node_pointer ptr) {
        _alloc.destroy(ptr);
        _alloc.deallocate(ptr, 1);
    }

    /**
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
    void _destruct_node_recursive(node_pointer ptr) {
        if (ptr == _nil) {
            return ;
        }
        _destruct_node_recursive(ptr->_left);
        _destruct_node_recursive(ptr->_right);
        _destruct_node(ptr);
    }

    /**
     *        11
     *      /    \
     *     3     15
     *    / \   /  \
     *   2   7     19
     *      / \    / \
     *     5          21
     *
     *  val이 1일때 position이 2 였던 경우 이거나, val이 17일때 position이 19 이었다면
     *  val이 9일때 position이 7 이었던 경우
     */
    // val이 들어갈 위치의 부모를 찾는 함수
    node_pointer _search_parent(const value_type& val, node_pointer position = ft::nil) {
        if (position && position != _end) {         // 현재 position이 있고, 끝이 아니라면
            if (_comp(val, position->_value) && position->_left == _nil) {  // val값이 position의 값보다 작고, position의 왼쪽이 nil노드일때
                iterator prev = iterator(position, _nil);
                if (prev == begin() || _comp(*(--prev), val)) {             // position이 시작과 같거나,
                    return position;                                        // position의 이전 노드의 값이 val값보다 작으면 position의 이전값과 position의 사이의 값이라는 의미가 된다.
                }
            } else if (position->_right == _nil) {              // position의 오른쪽이 nil노드 일때
                iterator next = iterator(position, _nil);
                if (next == end() || _comp(val, *(++next))) {   // position이 끝과 같거나, position의 다음 값보다 val이 작은 경우
                    return position;
                }
            }
        }
        node_pointer cur = _get_root();
        node_pointer tmp = _end;
        while (cur != _nil) {
            tmp = cur;
            if (_comp(val, cur->_value)) {          // val값이 현재노드의 값보다 작다는건 현재노드의 왼쪽과 비교해야한다.
                cur = cur->_left;
            } else if (_comp(cur->_value, val)) {   // 현재노드의 값이 val값보다 작다는건 현재노드의 오른쪽과 비교해야한다.
                cur = cur->_right;
            } else {                                // 둘다 아니라면 val과 현재노드의 값이 같다는 것이므로 현재노드를 리턴한다.
                return cur;
            }
        }
        return tmp;
    }

    // val 값을 가진 노드를 parent의 자식으로 insert 한다.
    node_pointer _insert_internal(const value_type& val, node_pointer parent) {
        node_pointer ptr = _construct_node(val);
        if (parent == _end) {
            _set_root(ptr);
        } else if (_comp(val, parent->_value)) {    // 추가하려는 값이 부모의 값 보다 작으면 부모의 왼쪽에 추가
            parent->_left = ptr;
        } else {                                    // 추가하려는 값이 부모의 값 보다 크면 부모의 오른쪽에 추가
            parent->_right = ptr;
        }
        ptr->_parent = parent;
        _insert_fixup(ptr);
        _insert_update(ptr);
        return ptr;
    }

    void _insert_fixup(node_pointer ptr) {
        while (is_red_color(ptr->_parent)) {    // 부모가 레드였다면
            if (is_left_child(ptr->_parent)) {  // 부모가 왼쪽 자식이라면
                _insert_fixup_left(ptr);        //
            } else {                            // 부모가 오른쪽 자식이라면
                _insert_fixup_right(ptr);       //
            }
        }
        _get_root()->_is_black = true;          // root 노드는 블랙이라는 속성을 만족.
    }

    void _insert_fixup_left(node_pointer& ptr) {
        node_pointer uncle = ptr->_parent->_parent->_right; // 부모의 삼촌
        if (is_red_color(uncle)) {  // 부모의 삼촌이 red라면 할아버지와 할아버지의 자식 색깔을 바꾼다.  insert.case.1
            ptr->_parent->_is_black = true;
            uncle->_is_black = true;
            uncle->_parent->_is_black = false;
            ptr = uncle->_parent;   // 할아버지에서 다시 rbtree의 조건이 맞는지 확인해야하기 때문에 ptr을 할아버지로 바꿔준다.
        } else {                    // 부모의 삼촌이 black이라면    insert.case.3
            if (is_right_child(ptr)) {  // insert.case.2로 insert.case.3형태로 바꾸어 해결한다.
                ptr = ptr->_parent;
                _rotate_left(ptr);
            }
            ptr->_parent->_is_black = true;
            ptr->_parent->_parent->_is_black = false;
            _rotate_right(ptr->_parent->_parent);
        }
    }

    void _insert_fixup_right(node_pointer& ptr) {
        node_pointer uncle = ptr->_parent->_parent->_left;
        if (is_red_color(uncle)){           // insert.case.1
            ptr->_parent->_is_black = true;
            uncle->_is_black = true;
            uncle->_parent->_is_black = false;
            ptr = uncle->_parent;
        } else {                            // insert.case.3
            if (is_left_child(ptr)) {       // insert.case.2인경우 insert.case3형태로 바꾼다.
                ptr = ptr->_parent;
                _rotate_right(ptr);
            }
            ptr->_parent->_is_black = true;
            ptr->_parent->_parent->_is_black = false;
            _rotate_left(ptr->_parent->_parent);
        }
    }

    void _insert_update(const node_pointer ptr) {
        if (_begin == _end || _comp(ptr->_value, _begin->_value)) {
            _begin = ptr;
        }
        _size++;
    }

    // 삭제하려는 노드의 *자녀가 없거나 하나라면 삭제되는 색은 삭제되는 노드의 색 이고,
    // 삭제하려는 노드의 *자녀가 둘이라면 삭제되는 색은 삭제되는 노드의 *successor의 색 입니다.
    /**
     *        7
     *      /   \
     *     3     13
     *    / \   /  \
     *   1   5  9   15
     *           \
     *            11
     *  ptr: 7, fixup: 9, recolor: 11
     *        9
     *      /   \
     *     3     13
     *    / \   /  \
     *   1   5 11   15
     * (ptr: 11)
     **********************************
     *        7
     *      /   \
     *     3     11
     *    / \   /  \
     *   1   5  9   13
     *  ptr: 11, fixup: 13, recolor: nil
     *        7
     *      /   \
     *     3     13
     *    / \   /  \
     *   1   5  9
     * (ptr: nil)
     */
    void _remove_internal(node_pointer ptr) {
        node_pointer recolor_node;
        node_pointer fixup_node = ptr;
        bool original_color = is_black_color(ptr);
        if (ptr->_left == _nil) {
            recolor_node = ptr->_right;
            _transplant(ptr, ptr->_right);
        } else if (ptr->_right == _nil) {
            recolor_node = ptr->_left;
            _transplant(ptr, ptr->_left);
        } else {
            fixup_node = get_min_node(ptr->_right, _nil);       // 현재 노드의 오른쪽 자식에서 가장 작은 값을 가진 successor를 찾습니다.
            original_color = is_black_color(fixup_node);        // 자녀가 둘이라면 삭제되는 색은 successor의 색입니다.
            recolor_node = fixup_node->_right;
            if (fixup_node->_parent == ptr) {
                recolor_node->_parent = fixup_node;
            } else {
                _transplant(fixup_node, fixup_node->_right);
                fixup_node->_right = ptr->_right;
                fixup_node->_right->_parent = fixup_node;
            }
            _transplant(ptr, fixup_node);
            fixup_node->_left = ptr->_left;
            fixup_node->_left->_parent = fixup_node;
            fixup_node->_is_black = is_black_color(ptr);
        }
        if (original_color) {
            _remove_fixup(recolor_node);
        }
    }

    void _remove_fixup(node_pointer ptr) {
        while (ptr != _get_root() && is_black_color(ptr)) {
            if (is_left_child(ptr)) {
                _remove_fixup_left(ptr);
            } else {
                _remove_fixup_right(ptr);
            }
        }
        ptr->_is_black = true;
    }
    /**
     *        7
     *      /   \
     *     3     13
     *    / \   /  \
     *   1   5  9   15
     *           \
     *            11
     *  ptr: 7, fixup: 9, recolor: 11
     *        9
     *      /   \
     *     3     13
     *    / \   /  \
     *   1   5 11   15
     * (ptr: 11)
     */
    void _remove_fixup_left(node_pointer& ptr) {
        node_pointer sibling = ptr->_parent->_right;
        if (is_red_color(sibling)) {            // case.1  -> 변환 뒤 case.2,3,4의 경우로 해결
            sibling->_is_black = true;
            ptr->_parent->_is_black = false;
            _rotate_left(ptr->_parent);
            sibling = ptr->_parent->_right;
        }
        if (is_black_color(sibling->_left) && is_black_color(sibling->_right)) {    // case.2 -> 부모가 extra black을 해결하도록 위임.
            sibling->_is_black = false;
            ptr = ptr->_parent;
        } else if (is_black_color(sibling->_right)) {       // case.3 -> case.4의 형태로 만들어서 해결
            sibling->_left->_is_black = true;
            sibling->_is_black = false;
            _rotate_right(sibling);
            sibling = ptr->_parent->_right;
        }
        if (is_red_color(sibling->_right)) {    // case.4
            sibling->_is_black = is_black_color(ptr->_parent);
            ptr->_parent->_is_black = true;
            sibling->_right->_is_black = true;
            _rotate_left(ptr->_parent);
            ptr = _get_root();
        }
    }

    void _remove_fixup_right(node_pointer& ptr) {
        node_pointer sibling = ptr->_parent->_left;
        if (is_red_color(sibling)) {            // case.1
            sibling->_is_black = true;
            ptr->_parent->_is_black = false;
            _rotate_right(ptr->_parent);
            sibling = ptr->_parent->_left;
        }
        if (is_black_color(sibling->_right) && is_black_color(sibling->_left)) {    // case.2
            sibling->_is_black = false;
            ptr = ptr->_parent;
        } else if (is_black_color(sibling->_left)) {    // case.3
            sibling->_right->_is_black = true;
            sibling->_is_black = false;
            _rotate_left(sibling);
            sibling = ptr->_parent->_left;
        }
        if (is_red_color(sibling->_left)) {     // case.4
            sibling->_is_black = is_black_color(ptr->_parent);
            ptr->_parent->_is_black = true;
            sibling->_left->_is_black = true;
            _rotate_right(ptr->_parent);
            ptr = _get_root();
        }
    }

    /**
     *        11
     *      /    \
     *     3     15
     *    / \   /  \
     *   2   7     21
     *      / \    /
     *     5      19
     *           /
     *          17
     *
     *  curr이 17인 경우(즉, 17를 제거할 경우)
     */
    // curr의 부모노드에 next를 연결시키주는 함수
    void _transplant(node_pointer curr, node_pointer next) {
        if (curr->_parent == _end) {
            _set_root(next);
        } else if (is_left_child(curr)) {   // 현재노드가 왼쪽 자식이면 부모노드의 왼쪽을 next노드로 바꾸어 준다.
            curr->_parent->_left = next;
        } else {                            // 현재노드가 오른쪽 자식이면 부모노드의 오른쪽을 next노드로 바꾸어 준다.
            curr->_parent->_right = next;
        }
        next->_parent = curr->_parent;
    }

    void _rotate_left(node_pointer ptr) {
        node_pointer child = ptr->_right;
        ptr->_right = child->_left;
        if (ptr->_right != _nil) {
            ptr->_right->_parent = ptr;
        }
        node_pointer parent = ptr->_parent;
        child->_parent = parent;
        if (parent == _end) {
            _set_root(child);
        } else if (is_left_child(ptr)) {
            parent->_left = child;
        } else {
            parent->_right = child;
        }
        child->_left = ptr;
        ptr->_parent = child;
    }

    void _rotate_right(node_pointer ptr) {
        node_pointer child = ptr->_left;
        ptr->_left = child->_right;
        if (ptr->_left != _nil) {
            ptr->_left->_parent = ptr;
        }
        node_pointer parent = ptr->_parent;
        child->_parent = parent;
        if (parent == _end) {
            _set_root(child);
        } else if (is_left_child(ptr)) {
            parent->_left = child;
        } else {
            parent->_right = child;
        }
        child->_right = ptr;
        ptr->_parent = child;
    }

    /* lookup operations */
    template <typename U>
    node_pointer _find_internal(const U& val) const {
        node_pointer ptr = _get_root();
        while (ptr != _nil) {
            if (_comp(val, ptr->_value)) {
                ptr = ptr->_left;
            } else if (_comp(ptr->_value, val)) {
                ptr = ptr->_right;
            } else {
                return ptr;
            }
        }
        return _end;
    }

    // 찾으려는 key 값보다 같거나 큰 숫자
    node_pointer _lower_bound_internal(const key_type& key) const {
        node_pointer ptr = _get_root();
        node_pointer tmp = _end;
        while (ptr != _nil) {
            if (!_comp(ptr->_value, key)) {
                tmp = ptr;
                ptr = ptr->_left;
            } else {
                ptr = ptr->_right;
            }
        }
        return tmp;
    }

    // 찾으려는 key 값을 초과하는 숫자
    node_pointer _upper_bound_internal(const key_type& key) const {
        node_pointer ptr = _get_root();
        node_pointer tmp = _end;
        while (ptr != _nil) {
            if (_comp(key, ptr->_value)) {
                tmp = ptr;
                ptr = ptr->_left;
            } else {
                ptr = ptr->_right;
            }
        }
        return tmp;
    }

    template <typename U>
    ft::pair<iterator, iterator> _equal_range_internal(const U& val) {
        node_pointer ptr = _get_root();
        node_pointer tmp = _end;
        while (ptr != _nil) {
              if (_comp(val, ptr->_value)) {
                  tmp = ptr;
                  ptr = ptr->_left;
              } else if (_comp(ptr->_value, val)) {
                  ptr = ptr->_right;
              } else {
                  if (ptr->_right != _nil) {
                      tmp = get_min_node(ptr->_right, _nil);
                  }
                  return ft::make_pair(iterator(ptr, _nil), iterator(tmp, _nil));
              }
        }
        return ft::make_pair(iterator(tmp, _nil), iterator(tmp, _nil));
    }

    template <typename U>
    ft::pair<const_iterator, const_iterator> _equal_range_internal(const U& val) const {
        node_pointer ptr = _get_root();
        node_pointer tmp = _end;
        while (ptr != _nil) {
            if (_comp(val, ptr->_value)) {
                tmp = ptr;
                ptr = ptr->_left;
            } else if (_comp(ptr->_value, val)) {
                ptr = ptr->_right;
            } else {
                if (ptr->_right != _nil) {
                    tmp = get_min_node(ptr->_right, _nil);
                }
                return ft::make_pair(const_iterator(ptr, _nil), const_iterator(tmp, _nil));
            }
        }
        return ft::make_pair(const_iterator(tmp, _nil), const_iterator(tmp, _nil));
    }

};

}   // namespace ft

#endif  // RBTREE_HPP