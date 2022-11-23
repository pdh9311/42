#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
public:
    typedef Iterator                                                        iterator_type;
    typedef typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;
    typedef typename ft::iterator_traits<iterator_type>::value_type         value_type;
    typedef typename ft::iterator_traits<iterator_type>::difference_type    difference_type;
    typedef typename ft::iterator_traits<iterator_type>::pointer            pointer;
    typedef typename ft::iterator_traits<iterator_type>::reference          reference;

private:
    Iterator iterator;

public:
    /* canoncial form */
    reverse_iterator() : iterator(iterator_type()) {}
    explicit reverse_iterator(iterator_type it) : iterator(it) {}
    template <class Iter>
    reverse_iterator(const reverse_iterator<Iter>& rev_it) : iterator(rev_it.base()) {}
    ~reverse_iterator() {}
    template <class Iter>
    reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it) {
        iterator = rev_it.base();
        return *this;
    }

    /* member function */
    iterator_type base() const { return iterator; }

    /* operator */  // ++, --, +, -, +=, -=, *, ->, []
    reverse_iterator& operator++() {
        --iterator;
        return *this;
    }
    reverse_iterator& operator--() {
        ++iterator;
        return *this;
    }
    reverse_iterator operator++(int) {
        reverse_iterator tmp(*this);
        --iterator;
        return tmp;
    }
    reverse_iterator operator--(int) {
        reverse_iterator tmp(*this);
        ++iterator;
        return tmp;
    }
    reverse_iterator operator+(difference_type n) const {
        return reverse_iterator(iterator - n);
    }
    reverse_iterator operator-(difference_type n) const {
        return reverse_iterator(iterator + n);
    }
    reverse_iterator& operator+=(difference_type n) {
        iterator -= n;
        return *this;
    }
    reverse_iterator& operator-=(difference_type n) {
        iterator += n;
        return *this;
    }
    reference operator*() const {
        Iterator tmp = iterator;
        return *(--tmp);
    }
    pointer operator->() const {
        return &(operator*());
    }
    reference operator[](difference_type n) const {
        return *(*this + n);    // operator* -> operator+ -> operator*
    }
};

/* Non-member function */
template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{ return lhs.base() == rhs.base(); }
template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{ return lhs.base() != rhs.base(); }
template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{ return lhs.base() > rhs.base(); }
template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{ return lhs.base() >= rhs.base(); }
template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{ return lhs.base() < rhs.base(); }
template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{ return lhs.base() <= rhs.base(); }

template <class Iterator>
reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>& rev_it) {
    return reverse_iterator<Iterator>(rev_it.base() - n);
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
        const reverse_iterator<Iterator1>& lhs,
        const reverse_iterator<Iterator2>& rhs) {
    return rhs.base() - lhs.base();
}

}   // namespace ft

#endif  // REVERSE_ITERATOR_HPP