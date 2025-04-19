/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:02:02 by tony              #+#    #+#             */
/*   Updated: 2025/04/19 18:08:03 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H
# include "utils/header/libft.h"
# include "utils/header/ft_printf.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	char	*path;
	char	*path_cmd;
	char	*path_cmd1;
}	t_pipe;


int 	check_acces(char **argv);
char	*get_path(char *str, char **env);
char	*find_cmd(char *cmd, char **env, t_pipe *pipe);
void	ft_free(char **str);
void	parsing(char **argv, char **env, t_pipe *pipe);
void	init_struct(t_pipe *pipe);
#endif
