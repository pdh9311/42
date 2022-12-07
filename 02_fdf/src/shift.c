/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:39 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:40 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift(t_bresenham *b, t_control *control)
{
	b->x += control->shift_x;
	b->y += control->shift_y;
	b->x1 += control->shift_x;
	b->y1 += control->shift_y;
}
