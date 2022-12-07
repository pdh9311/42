/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:33 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:34 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_bresenham *b, t_control *control)
{
	b->x *= control->zoom;
	b->y *= control->zoom;
	b->x1 *= control->zoom;
	b->y1 *= control->zoom;
}
