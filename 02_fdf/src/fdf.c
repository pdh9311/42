/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:06:00 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:06:01 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_control(t_fdf *data)
{
	data->color = 0x00FFFFFF;
	data->control->zoom_in = 0;
	data->control->zoom_out = 0;
	data->control->zoom = data->width / data->column / 3;
	data->control->left = 0;
	data->control->right = 0;
	data->control->up = 0;
	data->control->down = 0;
	data->control->shift_x = \
		(data->width / 2) - (data->column / 2 * data->control->zoom);
	data->control->shift_y = \
		(data->height / 2) - (data->row / 2 * data->control->zoom);
	data->control->rotate_x1 = 0;
	data->control->rotate_x2 = 0;
	data->control->rotate_y1 = 0;
	data->control->rotate_y2 = 0;
	data->control->rotate_z1 = 0;
	data->control->rotate_z2 = 0;
	data->control->alpha = 0;
	data->control->beta = 0;
	data->control->gamma = 0;
	data->control->is_iso = 1;
	data->control->iso_degree = 30;
	data->control->z_value_up = 0;
	data->control->z_value_down = 0;
}

static void	set_mlx(t_fdf *data)
{
	data->mlx = mlx_init();
	data->width = 1400;
	data->height = 1000;
	data->title = "FDF_donpark";
	data->win = mlx_new_window(data->mlx, data->width, \
								data->height, data->title);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
							&data->line_length, &data->endian);
	init_control(data);
}

static int	main_loop(t_fdf *data)
{
	init_win(data);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	move_control(data);
	zoom_control(data);
	rotate_control(data);
	z_matrix_control(data);
	return (0);
}

static void	mlx_hook_and_loop(t_fdf *data)
{
	mlx_hook(data->win, KEY_PRESS, 1L << 0, key_press, data);
	mlx_hook(data->win, KEY_RELEASE, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, main_loop, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	if (argc != 2)
		print_error("Usage : ./fdf <filename>");
	fdf_memory_allocate(&data);
	read_file(argv[1], data);
	z_matrix_print(data);
	set_mlx(data);
	mlx_hook_and_loop(data);
	final_free(data);
	return (0);
}
