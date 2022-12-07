/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:35 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:36 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *error)
{
	if (errno)
		perror(error);
	else
	{
		ft_putstr_fd(error, 2);
		write(2, "\n", 1);
	}
	exit(1);
}
