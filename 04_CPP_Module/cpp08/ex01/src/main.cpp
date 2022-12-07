/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:14:52 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:22:40 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

void defaultTest() {
	std::cout << "====== default Test ======" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test1() {
	std::cout << "====== Test1 ======" << std::endl;
	try {
		Span sp = Span(10000);

		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(rand() % 10000);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.addNumber(rand() % 10000);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void countExceptionTest1() {
	std::cout << "====== count Exception Test1 ======" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void countExceptionTest2() {
	std::cout << "====== count Exception Test2 ======" << std::endl;
	try {
		Span sp = Span(5);
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void iterTest1() {
	std::cout << "====== iter Test1 ======" << std::endl;
	try {
		Span sp(10);
		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(rand() % 100);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void iterTest2() {
	std::cout << "====== iter Test2 ======" << std::endl;
	try {
		Span sp(10);
		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(rand() % 100);

		sp.addNumber(1);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	std::srand(std::time(NULL));
	defaultTest();
	test1();
	countExceptionTest1();
	countExceptionTest2();
	iterTest1();
	iterTest2();
	return 0;
}
