/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:16:45 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:16:46 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"
#include "Color.hpp"

void vectorTest() {
	std::cout << C_AQUA << "[vector Test]" << C_NC << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << C_AQUA << *it << " ";
	}
	std::cout << C_NC << std::endl;

	try {
		std::vector<int>::iterator p1 = easyfind(vec, 2);
		std::cout << *p1 << std::endl;

		std::vector<int>::iterator p2 = easyfind(vec, 10);
		std::cout << *p2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

}

void dequeTest() {
	std::cout << C_AQUA << "[deque Test]" << C_NC << std::endl;
	std::deque<int> dq;
	for (int i = 0; i < 10; i++) {
		dq.push_back(i + 10);
	}
	for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
		std::cout << C_AQUA << *it << " ";
	}
	std::cout << C_NC << std::endl;

	try {
		std::deque<int>::iterator p3 = easyfind(dq, 2);
		std::cout << *p3 << std::endl;

		std::deque<int>::iterator p4 = easyfind(dq, 10);
		std::cout << *p4 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void listTest() {
	std::cout << C_AQUA << "[list Test]" << C_NC << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 10; i++) {
		lst.push_back(i);
	}
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << C_AQUA << *it << " ";
	}
	std::cout << C_NC << std::endl;

	try {
		std::list<int>::iterator p5 = easyfind(lst, 2);
		std::cout << *p5 << std::endl;

		std::list<int>::iterator p6 = easyfind(lst, 10);
		std::cout << *p6 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	vectorTest();
	dequeTest();
	listTest();
	return (0);
}
