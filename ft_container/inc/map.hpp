#ifndef MAP_HPP
# define MAP_HPP

# include "reverse_iterator.hpp"    // reverse_iterator
# include "rbtree.hpp"

namespace ft {

template < class Key,                                               // map::key_type
           class T,                                                 // map::mapped_type
           class Compare = std::less<Key>,                          // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key, T> > >   // map::allocator_type
class map {
public:
    typedef Key                                                             key_type;
    typedef T                                                               mapped_type;
    typedef ft::pair<const key_type, mapped_type>                           value_type;
    typedef Compare                                                         key_compare;

    // value_compare
    class value_compare : public std::binary_function<value_type,value_type, bool> {
    protected:
        Compare comp;

    public:
        value_compare (Compare c) : comp(c) {}
        ~value_compare() {}
        /* call operator */
        bool operator()(const value_type& x, const value_type& y) const {
            return comp(x.first, y.first);
        }
        bool operator()(const value_type& x, const key_type& y) const {
            return comp(x.first, y);
        }
        bool operator()(const key_type& x, const value_type& y) const {
            return comp(x, y.first);
        }
    };

    typedef Alloc                                                           allocator_type;
    typedef typename allocator_type::template rebind<value_type>::other     alloc_type;
    typedef std::allocator_traits<alloc_type>                               type_traits;
    typedef typename type_traits::pointer                                   pointer;
    typedef typename type_traits::const_pointer                             const_pointer;
    typedef value_type&                                                     reference;
    typedef const value_type&                                               const_reference;

    typedef ft::rbtree<value_type, key_type, value_compare, allocator_type> rb_tree;
    typedef typename rb_tree::iterator                                      iterator;
    typedef typename rb_tree::const_iterator                                const_iterator;
    typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
    typedef ft::reverse_iterator<iterator>                                  const_reverse_iterator;

    typedef std::ptrdiff_t                                                  difference_type;
    typedef std::size_t                                                     size_type;

private:
    key_compare     _key_comp;
    value_compare   _value_comp;
    rb_tree         _tree;

public:
    /* constrcut & destruct & assignment */
    explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _key_comp(comp), _value_comp(comp), _tree(_value_comp, alloc) {}

    template<class InputIterator>
    map(InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
        : _key_comp(comp), _value_comp(comp), _tree(_value_comp, alloc) {
        insert(first, last);
    }

    map(const map& m) : _key_comp(m._key_comp), _value_comp(m._value_comp), _tree(m._tree) {}

    ~map() {}

    map& operator=(const map& m) {
        if (this != &m) {
            _key_comp = m._key_comp;
            _value_comp = m._value_comp;
            _tree = m._tree;
        }
        return *this;
    }

    /* member function */
    iterator begin() { return _tree.begin(); }
    const_iterator begin() const { return _tree.begin(); }
    iterator end() { return _tree.end(); }
    const_iterator end() const { return _tree.end(); }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const { return reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { return reverse_iterator(begin()); }

    bool empty() const { return _tree.empty(); }
    size_type size() const { return _tree.size(); }
    size_type max_size() const { return _tree.max_size(); }
    mapped_type& operator[](const key_type& k) {
        ft::pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
        return p.first->second;
    }

    /* single element, with hint, range */
    ft::pair<iterator, bool> insert(const value_type& val) { return _tree.insert(val); }
    iterator insert(iterator position, const value_type& val) { return _tree.insert(position, val); }
    template<class InputIterator>
    void insert(InputIterator first, InputIterator last) { return _tree.insert(first, last); }

    void erase(iterator position) { _tree.erase(position); }
    size_type erase(const key_type& k) { return _tree.erase(k); }
    void erase(iterator first, iterator last) { _tree.erase(first, last); }

    void swap(map& m) { _tree.swap(m._tree); }
    void clear() { _tree.clear();
    }
    key_compare key_comp() const { return _key_comp; }
    value_compare value_comp() const { return _value_comp; }

    iterator find(const key_type& k) { return _tree.find(k); }
    const_iterator find(const key_type& k) const { return _tree.find(k); }

    size_type count(const key_type& k) const { return !(find(k) == end()); }

    iterator lower_bound(const key_type& k) { return _tree.lower_bound(k); }
    const_iterator lower_bound(const key_type& k) const { return _tree.lower_bound(k); }
    iterator upper_bound(const key_type& k) { return _tree.upper_bound(k); }
    const_iterator upper_bound(const key_type& k) const { return _tree.upper_bound(k); }

    ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return _tree.equal_range(k); }
    ft::pair<iterator, iterator> equal_range(const key_type& k) { return _tree.equal_range(k); }

    allocator_type get_allocator() const { return _tree.get_alllocator(); }

};

/* non-member function */
template<class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

template<class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ return !(lhs == rhs); }

template<class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.end(), rhs.end()); }

template<class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ return !(lhs > rhs); }

template<class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ return lhs > rhs; }

template<class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{ return !(lhs < rhs); }

template<class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
{ lhs.swap(rhs); }

}   // namespace ft
#endif  // MAP_HPP