#ifndef SET_HPP
# define SET_HPP

# include "reverse_iterator.hpp"
# include "rbtree.hpp"

namespace ft {

template < class T,                             // set::key_type/value_type
           class Compare = std::less<T>,        // set::key_compare/value_compare
           class Alloc = std::allocator<T> >    // set::allocator_type
class set {
public:
    typedef T                                                               key_type;
    typedef T                                                               value_type;
    typedef Compare                                                         compare_type;
    typedef Compare                                                         key_compare;
    typedef Compare                                                         value_compare;

    typedef Alloc                                                           allocator_type;
    typedef typename allocator_type::template rebind<key_type>::other       alloc_type;
    typedef std::allocator_traits<alloc_type>                               type_traits;
    typedef typename type_traits::pointer                                   pointer;
    typedef typename type_traits::const_pointer                             const_pointer;
    typedef value_type&                                                     reference;
    typedef const value_type&                                               const_reference;

    typedef ft::rbtree<const value_type, key_type, value_compare, allocator_type> rb_tree;
    typedef typename rb_tree::iterator                                      iterator;
    typedef typename rb_tree::const_iterator                                const_iterator;
    typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;

    typedef std::ptrdiff_t                                                  difference_type;
    typedef std::size_t                                                     size_type;

private:
    compare_type    _comp;
    allocator_type  _alloc;
    rb_tree         _tree;

public:
    /* construct & destruct & assignment */
    explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _comp(comp), _alloc(alloc), _tree(comp, alloc) {}
    template <class InputIterator>
    set (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
        : _comp(comp), _alloc(alloc), _tree(comp, alloc) {
        insert(first, last);
    }
    set (const set& s) : _comp(s._comp), _alloc(s._alloc), _tree(s._tree) {}
    ~set() {}
    set& operator= (const set& s) {
        if (this != &s) {
            _comp = s._comp;
            _alloc = s._alloc;
            _tree = s._tree;
        }
        return *this;
    }

    /* member function */
    iterator begin() { return _tree.begin(); }
    const_iterator begin() const { return _tree.begin(); }
    iterator end() { return _tree.end(); }
    const_iterator end() const { return _tree.end(); }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const { return reverser_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { return reverse_iterator(begin()); }

    bool empty() const { return _tree.empty(); }
    size_type size() const { return _tree.size(); }
    size_type max_size() const { return _tree.max_size(); }

    /* insert (single element, with hint, range) */
    ft::pair<iterator,bool> insert(const value_type& val) { return _tree.insert(val); }
    iterator insert(iterator position, const value_type& val) { return _tree.insert(position, val); }
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) { _tree.insert(first, last); }
    void erase(iterator position) { _tree.erase(position); }
    size_type erase(const value_type& val) { return _tree.erase(val); }
    void erase(iterator first, iterator last) { _tree.erase(first, last); }
    void swap(set& s) { _tree.swap(s._tree); }
    void clear() { _tree.clear(); }

    key_compare key_comp() const { return _comp; }
    value_compare value_comp() const { return _comp; }
    iterator find(const value_type& val) const { return _tree.find(val); }
    size_type count(const value_type& val) const { return !(find(val) == end()); }
    iterator lower_bound(const value_type& val) const { return _tree.lower_bound(val); }
    iterator upper_bound(const value_type& val) const { return _tree.upper_bound(val); }
    ft::pair<iterator,iterator> equal_range(const value_type& val) const { return _tree.equal_range(val); }

    allocator_type get_allocator() const { return _tree.get_allocator(); }
};

template <class Key, class Compare, class Alloc>
bool operator==(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

template <class Key, class Compare, class Alloc>
bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{ return !(lhs == rhs); }

template <class Key, class Compare, class Alloc>
bool operator<(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

template <class Key, class Compare, class Alloc>
bool operator<=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{ return !(lhs > rhs); }

template <class Key, class Compare, class Alloc>
bool operator>(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{ return lhs > rhs; }

template <class Key, class Compare, class Alloc>
bool operator>=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{ return !(lhs < rhs); }

template <class Key, class Compare, class Alloc>
void swap(ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs)
{ lhs.swap(rhs); }

}   // namespace ft

#endif  // SET_HPP