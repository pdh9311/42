/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:15:02 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:15:08 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void) {
	std::cout << "=========== default Test ===========" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}

	std::cout << std::endl << "=========== copy Test ===========" << std::endl;
	MutantStack<int> mcopy(mstack);
	mcopy.pop();
	mcopy.pop();
	mcopy.push(10);
	mcopy.push(11);
	mcopy.push(12);
	while (!mcopy.empty()) {
		std::cout << mcopy.top() << " ";
		mcopy.pop();
	}

	std::cout << std::endl << "=========== assignment Test ===========" << std::endl;
	MutantStack<int> massign = mstack;
	massign.pop();
	massign.push(20);
	massign.push(21);
	massign.push(22);
	while (!massign.empty()) {
		std::cout << massign.top() << " ";
		massign.pop();
	}

	std::cout << std::endl << "=========== reverse_iterator Test ===========" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	for (MutantStack<int>::reverse_iterator it = rit; it != rite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return (0);
}
