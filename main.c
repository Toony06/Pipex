/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:11:56 by toroman           #+#    #+#             */
/*   Updated: 2025/04/21 14:21:50 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipe	pipe;

	if (ac == 5 && av[2][0] && av[3][0])
	{
		init_struct(&pipe);
		parsing(av, env, &pipe);
	}
	else
		ft_printf("Arguments error\n");
	return (0);
}

void	init_struct(t_pipe *pipe)
{
	pipe->path_cmd = NULL;
	pipe->path_cmd1 = NULL;
	pipe->args_cmd = NULL;
	pipe->args_cmd1 = NULL;
}
