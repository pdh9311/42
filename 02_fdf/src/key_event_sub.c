/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:58 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:59 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	direction_key(int keycode, t_fdf *data, int press_release)
{
	if (keycode == LEFT)
		data->control->left = press_release;
	else if (keycode == RIGHT)
		data->control->right = press_release;
	else if (keycode == UP)
		data->control->up = press_release;
	else if (keycode == DOWN)
		data->control->down = press_release;
}

void	zoom_key(int keycode, t_fdf *data, int press_release)
{
	if (keycode == PLUS || keycode == NUMPAD_PLUS)
		data->control->zoom_in = press_release;
	else if (keycode == MINUS || keycode == NUMPAD_MINUS)
		data->control->zoom_out = press_release;
}

void	rotate_key(int keycode, t_fdf *data, int press_release)
{
	if (keycode == NUM_1)
		data->control->rotate_x1 = press_release;
	else if (keycode == NUM_2)
		data->control->rotate_x2 = press_release;
	else if (keycode == NUM_3)
		data->control->rotate_y1 = press_release;
	else if (keycode == NUM_4)
		data->control->rotate_y2 = press_release;
	else if (keycode == NUM_5)
		data->control->rotate_z1 = press_release;
	else if (keycode == NUM_6)
		data->control->rotate_z2 = press_release;
}

void	z_value_key(int keycode, t_fdf *data, int press_release)
{
	if (keycode == RIGHT_ANGLE)
		data->control->z_value_up = press_release;
	else if (keycode == LEFT_ANGLE)
		data->control->z_value_down = press_release;
}

void	iso_plane_key(int keycode, t_fdf *data)
{
	if (keycode == LEFT_SQUARE)
	{
		data->control->is_iso = 1;
		data->control->alpha = 0;
		data->control->beta = 0;
		data->control->gamma = 0;
		data->control->iso_degree = 30;
	}
	else if (keycode == RIGHT_SQUARE)
	{
		data->control->is_iso = 0;
		data->control->alpha = 0;
		data->control->beta = 0;
		data->control->gamma = 0;
	}
}
