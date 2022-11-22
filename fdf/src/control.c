/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:06:03 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:06:04 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_control(t_fdf *data)
{
	int	move;

	move = 10;
	if (data->control->left == 1)
		data->control->shift_x -= move;
	else if (data->control->right == 1)
		data->control->shift_x += move;
	else if (data->control->up == 1)
		data->control->shift_y -= move;
	else if (data->control->down == 1)
		data->control->shift_y += move;
}

void	zoom_control(t_fdf *data)
{
	int	zoom;

	zoom = 1;
	if (data->control->zoom_in == 1)
		data->control->zoom += zoom;
	else if (data->control->zoom_out == 1)
		data->control->zoom -= zoom;
}

void	rotate_control(t_fdf *data)
{
	int	degree;

	degree = 1;
	if (data->control->rotate_x1 == 1)
		data->control->alpha += degree;
	else if (data->control->rotate_x2 == 1)
		data->control->alpha -= degree;
	if (data->control->rotate_y1 == 1)
		data->control->beta += degree;
	else if (data->control->rotate_y2 == 1)
		data->control->beta -= degree;
	if (data->control->rotate_z1 == 1)
		data->control->gamma += degree;
	else if (data->control->rotate_z2 == 1)
		data->control->gamma -= degree;
}

void	z_matrix_control(t_fdf *data)
{
	int	z_value;
	int	i;
	int	j;

	z_value = 7;
	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (data->z_matrix[i][j] != 0 && \
				data->control->z_value_up == 1)
				data->z_matrix[i][j] += z_value;
			else if (data->z_matrix[i][j] != 0 && \
				data->control->z_value_down == 1)
				data->z_matrix[i][j] -= z_value;
			j++;
		}
		i++;
	}
}
