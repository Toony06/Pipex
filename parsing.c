/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:08:11 by tony              #+#    #+#             */
/*   Updated: 2025/04/21 14:20:55 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_acces(char **argv)
{
	int	fd_in;
	int	fd_out;

	fd_in = open(argv[1], O_RDONLY, 0777);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);

	if (access(argv[1], R_OK) == -1)
	{
		ft_putstr_fd("error read its impossible\n", 2);
		exit(EXIT_FAILURE);
		return(0);
	}
	if (access(argv[4], W_OK) == -1)
	{
		ft_putstr_fd("error write its impossible", 2);
		return(0);
	}
	close(fd_in);
	close(fd_out);
	return(1);

}

char	*get_path(char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str) == 0))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd(char *cmd, char **env, t_pipe *pipe)
{
	char	**path_split;
	char	*path_join;
	char	*tpm;
	int		i;

	pipe->path = get_path("PATH=", env);
	path_split = ft_split(pipe->path, ':');
	if (!path_split)
		return (NULL);
	i = 0;
	while (path_split[i])
	{
		tpm = ft_strjoin(path_split[i], "/");
		path_join = ft_strjoin(tpm, cmd);

		if (access(path_join, X_OK) == 0)
		{
			ft_free(path_split);
			return (path_join);
		}
		free(path_join);
		i++;
	}
	ft_free(path_split);
	return (NULL);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	parsing(char **argv, char **env, t_pipe *pipe)
{
	char	**cmd;
	char	**cmd1;

	cmd = ft_split(argv[2], ' ');
	cmd1 = ft_split(argv[3], ' ');
	pipe->path_cmd = find_cmd(cmd[0], env, pipe);
	pipe->path_cmd1 = find_cmd(cmd1[0], env, pipe);

	if (!check_acces(argv))
	{
		ft_printf("Error acces its impossible");
		exit(EXIT_FAILURE);
	}
	if ((!pipe->path_cmd) || !pipe->path_cmd1)
	{
		ft_free(cmd);
		ft_free(cmd1);
		exit(EXIT_FAILURE);
	}
	ft_free(cmd);
	ft_free(cmd1);
	pipe->args_cmd = handle_args2(argv, pipe);
	pipe->args_cmd1 = handle_args3(argv, pipe);
}
