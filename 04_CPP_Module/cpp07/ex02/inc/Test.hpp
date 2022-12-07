/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:16:55 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:17:30 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

class Test {
private:
	int value_;

public:
	Test();
	Test(int value);
	Test(const Test &t);
	~Test();
	Test& operator=(const Test &t);

	const int& getValue() const;
};

#endif
