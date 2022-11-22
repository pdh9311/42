/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:35:33 by donpark           #+#    #+#             */
/*   Updated: 2021/11/15 20:35:36 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_process(t_exe *exe, pid_t pid, int i)
{
	int	status;

	status = 0;
	if (i == 0 && exe->pip_cnt == 0)
	{
	}
	else if (i % 2 == 0 && exe->pip_cnt == 0)
		close(exe->b[READ]);
	else if (i % 2 != 0 && exe->pip_cnt == 0)
		close(exe->a[READ]);
	else if (i % 2 == 0 && exe->pip_cnt > 0)
	{
		close(exe->a[WRITE]);
		if (exe->flag_b != 0)
			close(exe->b[READ]);
	}
	else if (i % 2 != 0 && exe->pip_cnt > 0)
	{
		close(exe->a[READ]);
		close(exe->b[WRITE]);
	}
	waitpid(pid, &status, 0);
	g_data.exit_status = status >> 8;
	if (status == 0)
		g_data.exit_status = status;
}
