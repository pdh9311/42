/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:43 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:44 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		nums[i] = NULL;
		i++;
	}
	free(nums);
	nums = NULL;
}

static void	z_matrix_allocate(t_fdf *data)
{
	int	i;

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->row));
	if (data->z_matrix == NULL)
		print_error("malloc error");
	i = 0;
	while (i < data->row)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) *(data->column));
		if (data->z_matrix[i] == NULL)
			print_error("malloc error");
		i++;
	}
}

static void	get_z_matrix(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	z_matrix_allocate(data);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error("file open error");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		line = NULL;
		i++;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	close(fd);
}

void	read_file(char *file_name, t_fdf *data)
{
	get_row(file_name, data);
	get_column(file_name, data);
	get_z_matrix(file_name, data);
}
