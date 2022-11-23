#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
public:
    typedef T           value_type;
    typedef Container   container_type;
    typedef size_t      size_type;

protected :
    container_type c;

public:
    /* construct & destruct & assignment */
    explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}
    stack(const stack& s) : c(s.c) {}
    stack& operator=(const stack& s) {
        if (this != s) {
            c = s.c;
        }
        return *this;
    }
    ~stack() {}

    /* member function */
    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }
    value_type& top() { return c.back(); }
    const value_type& top() const { return c.back(); }
    void push(const value_type& val) { return c.push_back(val); }
    void pop() { return c.pop_back(); }
};

/* non-member function */
template <class T, class Container>
bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return lhs.c == rhs.c; }

template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return !(lhs == rhs); }

template <class T, class Container>
bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return lhs.c < rhs.c; }

template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return !(lhs == rhs); }

template <class T, class Container>
bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return lhs > rhs; }

template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return !(lhs < rhs); }

}   // namespace ft

#endif  // STACK_HPP