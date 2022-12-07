/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:16:54 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:36:36 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
/*
template <typename T>
class Array {
private:
	unsigned int size_;
	T *arr_;

public:
	Array() : size_(0), arr_(NULL) {}
	Array(unsigned int n) : size_(n), arr_(new T[n]) {}
	Array(const Array &array) {
		this->size_ = array.size();
		this->arr_ = new T[this->size_];
		for (unsigned int i = 0; i < this->size_; i++) {
			(*this)[i] = array[i];
		}
	}
	~Array() {
		if (this->arr_ != NULL) {
			delete[] this->arr_;
			this->arr_ = NULL;
		}
	}

	Array& operator=(const Array &array) {
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

	const unsigned int& size() const {
		return (this->size_);
	}

	T& operator[](unsigned int idx) {
		if (idx >= this->size_)
			throw Array::OutOfRange();
		return (this->arr_[idx]);
	}

	const T& operator[](unsigned int idx) const{
		if (idx >= this->size_)
			throw Array::OutOfRange();
		return (this->arr_[idx]);
	}

	class OutOfRange : public std::exception {
	public:
		const char* what() const throw() {
			return ("Out of range!!");
		}
	};
};
*/

template <typename T>
class Array {
private:
	unsigned int size_;
	T *arr_;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &array);
	~Array();

	Array& operator=(const Array &array);

	const unsigned int& size() const;

	T& operator[](unsigned int idx);
	const T& operator[](unsigned int idx) const;

	class OutOfRange : public std::exception {
	public:
		const char* what() const throw();
	};
};

#include "Array.tpp"

#endif
