/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:11:56 by toroman           #+#    #+#             */
/*   Updated: 2025/04/18 14:20:05 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	main(int ac, char **av)
{

	if (ac == 5 && av[2][0] && av[3][0])
	{
		parsing(av);

	}
	else
		return (ft_printf("Arguments error\n"), 1);
	return (0);
}
