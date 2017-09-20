/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:47:55 by eupopa            #+#    #+#             */
/*   Updated: 2017/09/20 13:05:25 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"


int		check_commands(char *command)
{
	VAR(int, i, -1);
	while (g_commands[++i])
	{
		if (!ft_strcmp(g_commands[i], command))
			return (i);
	}
	return (-1);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		write(1, "is working\n", 11);
		// VAR(int, cmd, check_commands(av[1]));
		// if (cmd < 0)
		// 	ft_putendl("ERROR");
		// else if (cmd == 0)
		// 	sd_base64(ac, av);
	}
	else
		write(1, "yes\n", 4);
		//ft_putendl(USAGE);
	return (0);
}

