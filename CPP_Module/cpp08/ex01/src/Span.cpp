/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:14:52 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:18:29 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : N_(N) {}

Span::Span(const Span &sp) {
	*this = sp;
}

Span::~Span() {}

Span& Span::operator=(const Span &sp) {
	N_ = sp.getN();
	vec_ = sp.getVector();
	return (*this);
}

void Span::addNumber(int num) {
	if (vec_.size() == N_)
		throw Span::ElementFullException();
	vec_.push_back(num);
}

void Span::addNumber(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end) {
	int d = std::distance(begin, end);
	if (static_cast<int>(N_ - vec_.size()) < d)
		throw Span::ElementFullException();
	vec_.insert(vec_.end(), begin, end);
}

long Span::shortestSpan() {
	if (vec_.size() < 2)
		throw Span::ElementCountException();
	std::vector<int> tmp = vec_;

	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator prevIter = tmp.begin();
	std::vector<int>::iterator nextIter = ++tmp.begin();
	long shortest = static_cast<long>(*nextIter) - static_cast<long>(*prevIter);
	while (nextIter != tmp.end()) {
		if (static_cast<long>(*nextIter) - static_cast<long>(*prevIter) < shortest)
			shortest = static_cast<long>(*nextIter) - static_cast<long>(*prevIter);
		++prevIter;
		++nextIter;
	}
	return (shortest);
}

long Span::longestSpan() {
	if (vec_.size() < 2)
		throw Span::ElementCountException();
	long longest = static_cast<long>(*std::max_element(vec_.begin(), vec_.end()))
				- static_cast<long>(*std::min_element(vec_.begin(), vec_.end()));
	return (longest);
}

const unsigned int& Span::getN() const {
	return (N_);
}

const std::vector<int>& Span::getVector() const {
	return (vec_);
}

const char* Span::ElementFullException::what() const throw() {
	return ("ElementFullException");
}

const char* Span::ElementCountException::what() const throw() {
	return ("ElementCountException");
}
