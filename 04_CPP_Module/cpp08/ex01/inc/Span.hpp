/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:14:47 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:18:31 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <iostream>

class Span{
private:
	unsigned int N_;
	std::vector<int> vec_;

	Span();

public:
	Span(unsigned int N);
	Span(const Span &sp);
	~Span();

	Span& operator=(const Span &sp);

	void addNumber(int num);
	void addNumber(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);
	long shortestSpan();
	long longestSpan();

	const unsigned int& getN() const;
	const std::vector<int>& getVector() const;

	class ElementFullException : public std::exception {
	public:
		const char* what() const throw();
	};

	class ElementCountException : public std::exception {
	public:
		const char* what() const throw();
	};

};

#endif
