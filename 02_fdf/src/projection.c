/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:46 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:46 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_bresenham *b, double alpha)
{
	int	prev_y;
	int	prev_z;
	int	prev_y1;
	int	prev_z1;

	prev_y = b->y;
	prev_z = b->z;
	prev_y1 = b->y1;
	prev_z1 = b->z1;
	b->y = prev_y * cos(alpha * PI / 180) - prev_z * sin(alpha * PI / 180);
	b->z = prev_y * sin(alpha * PI / 180) + prev_z * cos(alpha * PI / 180);
	b->y1 = prev_y1 * cos(alpha * PI / 180) - prev_z1 * sin(alpha * PI / 180);
	b->z1 = prev_y1 * sin(alpha * PI / 180) + prev_z1 * cos(alpha * PI / 180);
}

void	rotate_y(t_bresenham *b, double beta)
{
	int	prev_x;
	int	prev_z;
	int	prev_x1;
	int	prev_z1;

	prev_x = b->x;
	prev_z = b->z;
	prev_x1 = b->x1;
	prev_z1 = b->z1;
	b->x = prev_x * cos(beta * PI / 180) + prev_z * sin(beta * PI / 180);
	b->z = -prev_x * sin(beta * PI / 180) + prev_z * cos(beta * PI / 180);
	b->x1 = prev_x1 * cos(beta * PI / 180) + prev_z1 * sin(beta * PI / 180);
	b->z1 = -prev_x1 * sin(beta * PI / 180) + prev_z1 * cos(beta * PI / 180);
}

void	rotate_z(t_bresenham *b, double gamma)
{
	int	prev_x;
	int	prev_y;
	int	prev_x1;
	int	prev_y1;

	prev_x = b->x;
	prev_y = b->y;
	prev_x1 = b->x1;
	prev_y1 = b->y1;
	b->x = prev_x * cos(gamma * PI / 180) - prev_y * sin(gamma * PI / 180);
	b->y = prev_x * sin(gamma * PI / 180) + prev_y * cos(gamma * PI / 180);
	b->x1 = prev_x1 * cos(gamma * PI / 180) - prev_y1 * sin(gamma * PI / 180);
	b->y1 = prev_x1 * sin(gamma * PI / 180) + prev_y1 * cos(gamma * PI / 180);
}

/**
 * PI radian = 180 degree
 * 1 rad = (180 / PI) deg
 * 1 deg = (PI / 180) rad
 * 30 deg * (PI rad / 180 deg) = ... rad
 */
void	iso(t_bresenham *b, t_control *control)
{
	int	prev_x;
	int	prev_y;
	int	prev_x1;
	int	prev_y1;

	prev_x = b->x;
	prev_y = b->y;
	prev_x1 = b->x1;
	prev_y1 = b->y1;
	b->x = (prev_x - prev_y) * cos(control->iso_degree * PI / 180);
	b->y = (prev_x + prev_y) * sin(control->iso_degree * PI / 180) - b->z;
	b->x1 = (prev_x1 - prev_y1) * cos(control->iso_degree * PI / 180);
	b->y1 = (prev_x1 + prev_y1) * sin(control->iso_degree * PI / 180) - b->z1;
}
