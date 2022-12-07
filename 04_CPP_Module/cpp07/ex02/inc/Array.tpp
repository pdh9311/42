/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:42:59 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:43:40 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : size_(0), arr_(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n), arr_(new T[n]) {}

template <typename T>
Array<T>::Array(const Array &array) {
	this->size_ = array.size();
	this->arr_ = new T[this->size_];
	for (unsigned int i = 0; i < this->size_; i++) {
		(*this)[i] = array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	if (this->arr_ != NULL) {
		delete[] this->arr_;
		this->arr_ = NULL;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &array) {
	this->~Array();
	this->size_ = array.size();
	if (this->size_ != 0) {
		this->arr_ = new T[this->size_];
		for (unsigned int i = 0; i < this->size_; i++) {
			(*this)[i] = array[i];
		}
	}
	return (*this);
}

template <typename T>
const unsigned int& Array<T>::size() const {
	return (this->size_);
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= this->size_)
		throw Array<T>::OutOfRange();
	return (this->arr_[idx]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const{
	if (idx >= this->size_)
		throw Array<T>::OutOfRange();
	return (this->arr_[idx]);
}

template <typename T>
const char* Array<T>::OutOfRange::what() const throw() {
		return ("Out of range!!");
}