/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:15:01 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:15:08 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack() : MutantStack<T>::stack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &mstack)
	: MutantStack<T>::stack(mstack) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &mstack) {
	MutantStack<T>::stack::operator=(mstack);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const {
	return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return (this->c.rbegin());
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const {
	return (this->c.rbegin());
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const {
	return (this->c.rend());
}
