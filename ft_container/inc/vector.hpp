#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>                      // std::allocator
# include <stdexcept>                   // std::out_of_range
# include <algorithm>                   // std::min, std::copy, std::copy_backward, std::fill_n
# include <limits>                      // numeric_limits
# include "random_access_iterator.hpp"  // random_access_iterator, reverse_iterator
# include "reverse_iterator.hpp"
# include "type_traits.hpp"             // enable_if, is_integral
# include "utils.hpp"                   // std, distance
# include "algorithm.hpp"               // equal, lexicographical_compare

/**
 * [ std::allocator ]
 *    typedef size_t            size_type;
 *    typedef ptrdiff_t         difference_type;
 *    typedef _Tp*              pointer;
 *    typedef const _Tp*        const_pointer;
 *    typedef _Tp&              reference;
 *    typedef const _Tp&        const_reference;
 *    typedef _Tp               value_type;
 */

namespace ft {

template< class T, class Alloc = std::allocator<T> >
class vector {
public :
    /* definition */
    typedef T                                               value_type;             // 요소의 타입
    typedef Alloc                                           allocator_type;         // 요소의 할당 타입

    typedef typename allocator_type::reference              reference;              // T&
    typedef typename allocator_type::const_reference        const_reference;        // const T&
    typedef typename allocator_type::pointer                pointer;                // T*
    typedef typename allocator_type::const_pointer          const_pointer;          // const T*

    typedef ft::random_access_iterator<value_type>          iterator;
    typedef ft::random_access_iterator<const value_type>    const_iterator;
    typedef ft::reverse_iterator<iterator>                  reverse_iterator;
    typedef ft::reverse_iterator<const iterator>            const_reverse_iterator;

    typedef typename allocator_type::difference_type        difference_type;        // 두 요소의 주소값의 차 : 두 포인터 사이의 차이 (부호 있는 정수값: long)
    typedef typename allocator_type::size_type              size_type;              // 요소를 할당할 size

    // typedef typename allocator_type::template rebind<value_type>::other type_allocator;
private:
    allocator_type  _alloc;
    pointer         _start;
    pointer         _finish;
    pointer         _end_of_storage;

    void _init(size_type n) {
        if (n > max_size())
            throw std::out_of_range("ft::vector error");
        _start = _alloc.allocate(n);
        _finish = _start;
        _end_of_storage = _start + n;
    }

    // 뒤에서 부터 n개 만큼 val값으로 construct
    void _construct(size_type n, T val) {
        while (n--)
            _alloc.construct(_finish++, val);
    }

    // 뒤에서 부터 n개 만큼 construct
    void _construct(size_type n) {
        while (n--)
            _alloc.construct(_finish++);
    }

    // 뒤에서 부터 n개 destroy
    void _destroy(size_type n) {
        while (n--)
            _alloc.destroy(--_finish);
    }

    // 뒤에서 부터 until까지 destroy
    void _destroy(pointer until) {
        while (_finish != until) {
            _alloc.destroy(--_finish);
        }
    }

public:
    /* [ constructor ] default, fill, range, copy constructor */
    explicit vector(const allocator_type& alloc = allocator_type())
    : _alloc(alloc), _start(ft::nil), _finish(ft::nil), _end_of_storage(ft::nil) {}

    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
    : _alloc(alloc) {
        _init(n);
        _construct(n, val);
    }

    // Check whether it's an integral type.  If so, it's not an iterator.
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft::nil)
    : _alloc(alloc) {
        size_type n =std::distance(first, last);
        _init(n);
        _construct(n);
        std::copy(first, last, _start);
    }

    vector(const vector& v)
    : _alloc(v._alloc) {
        _init(v.capacity());
        _construct(v.size());
        std::copy(v._start, v._finish, _start);
    }

    /* [ destructor ] */
    ~vector() {
        if (_start == ft::nil)
            return ;
        size_type prev_capacity = capacity();
        _destroy(_start);
        _alloc.deallocate(_start, prev_capacity);
    }

    /* [ Assignment operator ] */
    vector& operator=(const vector& v) {
        if (this != &v) {
            assign(v.begin(), v.end());
        }
        return *this;
    }

    /* [ Iterators ] begin, end, rbegin, rend */
    iterator begin() { return iterator(_start); }
    const_iterator begin() const { return const_iterator(_start); }
    iterator end() { return iterator(_finish); }
    const_iterator end() const { return const_iterator(_finish); }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    /* [ Capacity ] size, max_size, resize, capacity, empty, reserve */
    size_type size() const  { return static_cast<size_type>(_finish - _start); }

    size_type max_size() const {
         return std::min<size_type>(std::numeric_limits<size_type>::max(), _alloc.max_size());
    }

    void resize(size_type n, value_type val = value_type()) {
        if (n > size()) {
            if (n > capacity())
                reserve(n);
            _construct(n - size(), val);
        } else if (n < size()) {
            _destroy(size() - n);
        }
    }

    size_type capacity() const { return static_cast<size_type>(_end_of_storage - _start); }

    bool empty() const { return _start == _finish; }

    /**
     * n이 기존 capacity() 보다 크면 capacity를 2배로 하여 재할당한다.
     */
    void reserve(size_type n) {
        if (n <= size() || n <= capacity())
            return ;
        if (n < capacity() * 2)
            n = capacity() * 2;
        size_type prev_size = size();
        size_type prev_capacity = capacity();
        pointer new_start = _alloc.allocate(n);
        std::copy(_start, _finish, new_start);
        _destroy(_start);
        _alloc.deallocate(_start, prev_capacity);
        _start = new_start;
        _finish = new_start + prev_size;
        _end_of_storage = _start + n;
    }

    /* [ Element access ] operator[], at, front, back */
    reference operator[](size_type n) {
        return _start[n];
    }
    const_reference operator[](size_type n) const {
        return _start[n];
    }

    reference at(size_type n) {
        if (n >= size()) {
            throw std::out_of_range("ft::vector at error");
        }
        return _start[n];
    }
    const_reference at(size_type n) const {
        if (n >= size()) {
            throw std::out_of_range("ft::vector at error");
        }
        return _start[n];
    }

    reference front() { return *_start; }
    const_reference front() const { return *_start; }
    reference back() { return *(_finish - 1); }
    const_reference back() const { return *(_finish - 1); }


    /* [ Modifiers ] assign, push_back, pop_back, insert, erase, swap, clear */
    template<class InputIterator>
    void assign(InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft::nil) {
        size_type n = std::distance(first, last);
        if (n > capacity()) {
            reserve(n);
        }
        std::copy(first, last, _start);
        _finish = _start + n;
    }

    void assign(size_type n, const value_type& val) {
        if (n > capacity())
            reserve(n);
        std::fill_n(_start, n, val);
        _finish = _start + n;
    }

    void push_back(const value_type& val) {
        size_type n = size() + 1;
        if (n > capacity())
            reserve(n);
        _alloc.construct(_finish++, val);
    }

    void pop_back() {
        _alloc.destroy(--_finish);
    }

    iterator insert(iterator position, const value_type& val) {
        difference_type diff = position - begin();
        if (size() + 1 > capacity())
            reserve(size() + 1);
        pointer pos = _start + diff;
        _construct(1); // _finish++;
        std::copy_backward(pos, _finish - 1, _finish);
        *pos = val;
        return iterator(pos);
    }

    void insert(iterator position, size_type n, const value_type& val) {
        difference_type diff = position - begin();
        if (size() + n > capacity())
            reserve(size() + n);
        pointer pos = _start + diff;
        _construct(n);
        std::copy_backward(pos, _finish - n, _finish);
        for (size_type i = 0; i < n; i++)
            pos[i] = val;
    }

    template<class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft::nil) {
        size_type n = std::distance(first, last);
        difference_type diff = position - begin();
        if (size() + n > capacity())
            reserve(n);
        pointer pos = _start + diff;
        _construct(n);
        std::copy_backward(pos, _finish - n, _finish);
        for (InputIterator it = first; it != last; it++, pos++)
            *pos = *it;
    }

    iterator erase(iterator position) {
        difference_type diff = position - begin();
        pointer pos = _start + diff;
        std::copy(pos + 1, _finish, pos);
        _destroy(1);
        return iterator(pos);
    }
    iterator erase(iterator first, iterator last) {
        size_type n = std::distance(first, last);
        std::copy(last, end(), first);
        _destroy(n);
        return first;
    }

    void swap (vector& x) {
        std::swap(_start, x._start);
        std::swap(_finish, x._finish);
        std::swap(_end_of_storage, x._end_of_storage);
        std::swap(_alloc, x._alloc);
    }

    void clear() {
        _destroy(_start);
    }

    /* Allocator */
    allocator_type get_allocator() const { return _alloc; }


};

/** Non-member function  */
template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{ return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

template <class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{ return !(lhs == rhs); }

template <class T, class Alloc>
bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

template <class T, class Alloc>
bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{ return lhs > rhs; }

template <class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{ return !(lhs > rhs); }

template <class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{ return !(lhs < rhs); }

template <class T, class Alloc>
void swap (ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
{ lhs.swap(rhs); }

}   // namespace ft

#endif  // VECTOR_HPP