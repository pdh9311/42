/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:16:50 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:17:29 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Test.hpp"

int main(void) {
	int size = 10;

	int *irr = new int[size];
	for (int i = 0; i < size; i++)
		irr[i] = i;
	::iter(irr, size, ::print);

	double drr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	::iter(drr, sizeof(drr) / sizeof(double), ::print);

	std::string *srr = new std::string[size];
	for (int i = 0; i < size; i ++)
		srr[i] = 'a' + i;
	::iter(srr, size, ::print);

	Test *trr = new Test[size];
	for (int i = 0; i < size; i ++) {
		Test tmp(i + size);
		trr[i] = tmp;
	}
	::iter(trr, size, testPrint);

	delete[] trr;
	delete[] srr;
	delete[] irr;
	return (0);
}