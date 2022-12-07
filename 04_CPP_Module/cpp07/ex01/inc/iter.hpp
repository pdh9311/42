/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:16:47 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:17:28 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstddef>
#include "Test.hpp"

template <typename T>
void print(T &t) {
	std::cout << t << " ";
}

void testPrint(Test &t) {
	std::cout << t.getValue() << " ";
}

template <typename T>
void iter(T *arr, std::size_t size, void (*fn)(T &elem)) {
	for (std::size_t i = 0; i < size; i++) {
		fn(arr[i]);
	}
	std::cout << std::endl;
}

#endif