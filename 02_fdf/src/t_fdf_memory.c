/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdf_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:37 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:38 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_memory_allocate(t_fdf **data)
{
	(*data) = (t_fdf *)malloc(sizeof(t_fdf));
	(*data)->control = (t_control *)malloc(sizeof(t_control));
	if ((*data) == NULL || (*data)->control == NULL)
		print_error("malloc error");
	(*data)->row = 0;
	(*data)->column = 0;
}

/**	[ in Linux or Ubuntu ]
 * mlx_destroy_window(data->mlx, data->win);
 * + mlx_destroy_image(data->mlx, data->img);
 * + mlx_destroy_display(data->mlx);
 * + free(data->mlx);
 * ...
 */
void	final_free(t_fdf *data)
{
	int	i;

	mlx_destroy_window(data->mlx, data->win);
	// mlx_destroy_image(data->mlx, data->img);
	// mlx_destroy_display(data->mlx);
	// free(data->mlx);
	i = 0;
	while (i < data->row)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data->control);
	free(data);
}
