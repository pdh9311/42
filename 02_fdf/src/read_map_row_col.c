/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_row_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:41 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:42 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_row(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error("file open error");
	while (get_next_line(fd, &line) > 0)
	{
		(data->row)++;
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	close(fd);
}

void	get_column(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error("file open error");
	get_next_line(fd, &line);
	data->column = ft_wordcnt(line, ' ');
	free(line);
	line = NULL;
	close(fd);
}
