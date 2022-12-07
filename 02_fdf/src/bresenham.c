/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:06:08 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:06:08 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham_init(t_bresenham *b, t_point point, t_fdf *data)
{
	b->x = point.x0;
	b->y = point.y0;
	b->x1 = point.x1;
	b->y1 = point.y1;
	b->z = data->z_matrix[point.y0][point.x0];
	b->z1 = data->z_matrix[point.y1][point.x1];
}

static void	bresenham_1458(t_bresenham *b, int x1, t_fdf *data)
{
	b->det = (2 * b->h) - b->w;
	while (b->x != x1)
	{
		set_color(b, data);
		if (b->det < 0)
			b->det += (2 * b->h);
		else
		{
			b->y += b->y_step;
			b->det += (2 * b->h - 2 * b->w);
		}
		if (b->x >= 0 && b->x <= data->width && \
			b->y >= 0 && b->y <= data->height)
			my_mlx_pixel_put(data, b->x, b->y, data->color);
		b->x += b->x_step;
	}
}

static void	bresenham_2367(t_bresenham *b, int y1, t_fdf *data)
{
	b->det = (2 * b->w) - b->h;
	while (b->y != y1)
	{
		set_color(b, data);
		if (b->det < 0)
			b->det += (2 * b->w);
		else
		{
			b->x += b->x_step;
			b->det += (2 * b->w - 2 * b->h);
		}
		if (b->x >= 0 && b->x <= data->width && \
			b->y >= 0 && b->y <= data->height)
			my_mlx_pixel_put(data, b->x, b->y, data->color);
		b->y += b->y_step;
	}
}

static void	set_bresenham(t_bresenham *b)
{
	if (b->y1 < b->y)
		b->y_step = -1;
	else
		b->y_step = 1;
	if (b->x1 < b->x)
		b->x_step = -1;
	else
		b->x_step = 1;
	b->w = abs(b->x1 - b->x);
	b->h = abs(b->y1 - b->y);
	b->l = sqrt(pow(b->w, 2) + pow(b->h, 2));
}

void	bresenham(t_point point, t_fdf *data)
{
	t_bresenham	*b;

	b = (t_bresenham *)malloc(sizeof(t_bresenham));
	if (b == NULL)
		print_error("malloc error");
	bresenham_init(b, point, data);
	zoom(b, data->control);
	if (data->control->is_iso == 1)
		iso(b, data->control);
	rotate_x(b, data->control->alpha);
	rotate_y(b, data->control->beta);
	rotate_z(b, data->control->gamma);
	shift(b, data->control);
	set_bresenham(b);
	if (b->w > b->h)
		bresenham_1458(b, b->x1, data);
	else
		bresenham_2367(b, b->y1, data);
	free(b);
}
