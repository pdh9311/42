/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:24:31 by donpark           #+#    #+#             */
/*   Updated: 2021/11/15 20:24:32 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env_lst(t_lst *lst)
{
	while (lst != NULL)
	{
		ft_putendl_fd(lst->content, 1);
		lst = lst->next;
	}
}

int	pp_env(t_lst **env_lst)
{
	if (env_lst == NULL)
	{
		g_data.exit_status = 126;
		return (EXIT_FAILURE);
	}
	print_env_lst(*env_lst);
	g_data.exit_status = 0;
	return (EXIT_SUCCESS);
}
