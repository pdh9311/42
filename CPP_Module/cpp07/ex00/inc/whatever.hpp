/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:16:42 by donpark           #+#    #+#             */
/*   Updated: 2022/03/26 13:17:26 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& min(T &a, T &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T& max(T &a, T &b) {
	if (a > b)
		return (a);
	return (b);
}

#endif
