#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "utils.hpp"

namespace ft {

template <class T>
class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T> {
public:
    typedef T*                                                                              iterator_type;
    typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category   iterator_category;
    typedef typename std::iterator<std::random_access_iterator_tag, T>::value_type          value_type;         // T
    typedef typename std::iterator<std::random_access_iterator_tag, T>::difference_type     difference_type;    // ptridff_t : 두 포인터 사이의 차이 (부호 있는 정수값: long)
    typedef typename std::iterator<std::random_access_iterator_tag, T>::pointer             pointer;            // T*
    typedef typename std::iterator<std::random_access_iterator_tag, T>::reference           reference;          // T&

private:
    pointer _ptr;

public:
    /* canoncial form */
    random_access_iterator() : _ptr(ft::nil) {}
    random_access_iterator(pointer ptr) : _ptr(ptr) {}
    template <class U>
    random_access_iterator(const random_access_iterator<U>& rai) : _ptr(rai.base()) {}
    template <class U>
    random_access_iterator& operator=(const random_access_iterator<U>& rai) {
        if (this != &rai)
            this->_ptr = rai.base();
        return *this;
    }
    ~random_access_iterator() {}

    /* member function */
    const pointer base() const { return _ptr; }
    /* operator */  // ++, --, +, -, +=, -=, *, ->, []
    random_access_iterator& operator++() {
        ++_ptr;
        return *this;
    }
    random_access_iterator& operator--() {
        --_ptr;
        return *this;
    }
    random_access_iterator operator++(int) {
        random_access_iterator tmp = *this;
        ++_ptr;
        return tmp;
    }
    random_access_iterator operator--(int) {
        random_access_iterator tmp = *this;
        --_ptr;
        return tmp;
    }
    random_access_iterator operator+(difference_type n) const {
        return random_access_iterator(_ptr + n);
    }
    random_access_iterator operator-(difference_type n) const {
        return random_access_iterator(_ptr - n);
    }
    random_access_iterator& operator+=(difference_type n) {
        _ptr += n;
        return *this;
    }
    random_access_iterator& operator-=(difference_type n) {
        _ptr -= n;
        return *this;
    }
    reference operator*() const {
        return *_ptr;
    }
    pointer operator->() const {
        return _ptr;
    }
    reference operator[](difference_type n) const {
        return _ptr[n];
    }
};

/* Non-member function */    //  ==, !=, <, >, <=, >=
template <class T1, class T2>
bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() == rhs.base(); }

template <class T1, class T2>
bool operator!=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() != rhs.base(); }

template <class T1, class T2>
bool operator<(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() < rhs.base(); }

template <class T1, class T2>
bool operator>(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() > rhs.base(); }

template <class T1, class T2>
bool operator<=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() <= rhs.base(); }

template <class T1, class T2>
bool operator>=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() >= rhs.base(); }

template <class T1>
typename random_access_iterator<T1>::difference_type operator+(
        typename random_access_iterator<T1>::difference_type n,
        const random_access_iterator<T1>& iter) {
    return random_access_iterator<T1>(iter.base() + n);
}

template <class T1, class T2>
typename random_access_iterator<T1>::difference_type operator-(
        const random_access_iterator<T1>& lhs,
        const random_access_iterator<T2>& rhs) {
    return (lhs.base() - rhs.base());
}

}   // namespace ft

#endif  // RANDOM_ACCESS_ITERATOR_HPP