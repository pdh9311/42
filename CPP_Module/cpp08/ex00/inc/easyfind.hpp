/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:14:32 by donpark           #+#    #+#             */
/*   Updated: 2022/03/29 10:16:47 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASEFIND_HPP
# define EASEFIND_HPP

# include <exception>
# include <iterator>
# include <algorithm>

class OutOfRangeException : public std::exception {
public:
	const char* what() const throw() {
		return ("OutOfRangeException");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw OutOfRangeException();
	return (iter);
}

#endif
