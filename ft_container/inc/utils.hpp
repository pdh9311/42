#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {

/** nullptr     <cstddef>
 *  // 템플릿 형변환
 *  operatorT*() const      // 이녀석은 모든 클래스 T나 자료형 T에 대한 포인터가 될수가 있어야 한다.
 *  operator T C::*() const // 이건 모든 클래스나 자료형 C의 내부에서 생길수 있는 주소값 T에 대한 포인터로 형변환.
 *  operator&() const       // 정의해 놓음으로해서 절대로 주소값을 알지 못하게 한다.
 *  nil = {};               // 곧바로 값을 선언함으로해서 단 1개의 nullptr만이 사용가능하게 한다.
 */
const class nullptr_t {
public:
    template <class T>
    operator T*() const { return 0; }

    template<class T, class C>
    operator T C::*() const { return 0; }

private:
    void operator&() const;
} nil = {};

/* pair */
template <class T1, class T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;

    first_type  first;
    second_type second;

    pair() : first(first_type()), second(second_type()) {}
    pair(const first_type& a, const second_type& b) : first(a), second(b) {}
    template<class U, class V>
    pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
    pair& operator=(const pair& pr) {
        if (this != & pr) {
            first = pr.first;
            second = pr.second;
        }
        return *this;
    }
};

template <class T1, class T2>
bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return lhs.first == rhs.first && lhs.second == rhs.second; }

template <class T1, class T2>
bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <class T1, class T2>
bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(rhs < lhs); }

template <class T1, class T2>
bool operator>  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(lhs < rhs); }

/* make_pair */
template <class T1,class T2>
pair<T1, T2> make_pair (T1 x, T2 y)
{ return pair<T1, T2>(x,y); }

}   // namespace ft
#endif  // UTILS_HPP