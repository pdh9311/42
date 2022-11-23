/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:14:59 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:15:09 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {
private:

public:
	MutantStack();
	MutantStack(const MutantStack<T> &mstack);
	~MutantStack();
	MutantStack<T>& operator=(const MutantStack<T> &mstack);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator cbegin() const;
	const_iterator cend() const;

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"

#endif
