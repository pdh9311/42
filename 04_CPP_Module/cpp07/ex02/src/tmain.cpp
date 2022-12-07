/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:17:00 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:17:31 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Test.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

# define SIZE 10

void test1() {
	Array<std::string> array(SIZE);

	for (int i = 0; i < SIZE; i++) {
		array[i] = 'a' + i;
	}

	for (int i =0 ; i < SIZE; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void test2() {
	Array<Test> array(SIZE);

	for (int i = 0; i < SIZE; i++) {
		Test tmp(i);
		array[i] = tmp;
	}

	for (int i = 0; i < SIZE; i++) {
		std::cout << array[i].getValue() << " ";
	}
	std::cout << std::endl;
}

int main(void) {
	test1();
	test2();
	return (0);
}
