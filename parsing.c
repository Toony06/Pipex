/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:46:18 by toroman           #+#    #+#             */
/*   Updated: 2025/04/17 18:57:08 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void parsing(char **argv)
{
	int	fd_in;
	int	fd_out;

	fd_in = open(argv[1], O_RDONLY, 0777);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);

	if (access(argv[1], R_OK) == -1)
	{
		ft_putstr_fd("error read its impossible", 2);
		exit(EXIT_FAILURE);
	}
	if (access(argv[4], W_OK) == -1)
	{
		ft_putstr_fd("error write its impossible", 2);
		exit(EXIT_FAILURE);
	}
	close(fd_in);
	close(fd_out);

}

char	*get_path(char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strcnmp(env[i], str, ft_strlen(str) == 0))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
