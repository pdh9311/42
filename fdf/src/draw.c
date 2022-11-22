/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:06:02 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:06:02 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data)
{
	t_point	point;

	point.y0 = 0;
	while (point.y0 < data->row)
	{
		point.x0 = 0;
		while (point.x0 < data->column)
		{
			if (point.x0 < data->column - 1)
			{
				point.x1 = point.x0 + 1;
				point.y1 = point.y0;
				bresenham(point, data);
			}
			if (point.y0 < data->row - 1)
			{
				point.x1 = point.x0;
				point.y1 = point.y0 + 1;
				bresenham(point, data);
			}
			(point.x0)++;
		}
		(point.y0)++;
	}
}
