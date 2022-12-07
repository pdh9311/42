/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:16:52 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:17:29 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

Test::Test() : value_(0) {}

Test::Test(int value) {
	this->value_ = value;
}

Test::Test(const Test &t) {
	*this = t;
}

Test::~Test() {}

Test& Test::operator=(const Test &t) {
	this->value_ = t.getValue();
	return (*this);
}

const int& Test::getValue() const {
	return (this->value_);
}