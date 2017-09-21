/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:47:55 by eupopa            #+#    #+#             */
/*   Updated: 2017/09/20 17:35:52 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"


int		main(int ac, char **av)
{
	
	int i;
	char *new_line;

	i = 0;

	if (ac > 1 && av[0])
	{
		while(g_commands[i] && ft_strcmp(av[1], g_commands[i]))
			i++;
		if (i < 4)
		{
			get_next_line(0, &new_line);
			ft_printf("%s\n", new_line);			
		}
		else
		{
			ft_printf("%s\n", "NO");
		}
	}
	else
	{
		ft_printf("%s\n", "ERROR");
	}		
	return (0);
}

