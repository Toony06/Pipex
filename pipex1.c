/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:34:36 by toroman           #+#    #+#             */
/*   Updated: 2025/04/21 15:09:17 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**handle_args2(char **av, t_pipe *pipe)
{
	char	**ac;

	ac = ft_split(av[2], ' ');
	if (!ac)
		return(NULL);
	free(ac[0]);
	ac[0] = ft_strdup(pipe->path_cmd);
	if (!ac[0])
	{
		ft_free(ac);
		return(NULL);
	}
	return(ac);
}

char	**handle_args3(char **av, t_pipe *pipe)
{
	char	**ac;

	ac = ft_split(av[3], ' ');
	if (!ac)
		return(NULL);
	free(ac[0]);
	ac[0] = ft_strdup(pipe->path_cmd1);
	if (!ac)
	{
		ft_free(ac);
		return(NULL);
	}
	return(ac);
}

void	cmd_exec(char **argv, t_pipe *pipex, char **env)
{
	int	pipefd[2];

	pipe(pipefd);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	pipex->process1 = fork();
	if(pipex->process1 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close_pipe(pipefd[0], pipefd[1], pipe);
	}
}

void	close_pipe(int	pipefd1, int pipefd2, t_pipe *pipe)
{
	close(pipefd1);
	close(pipefd2);
	close(pipe->infile);
	close(pipe->outfile);
}
