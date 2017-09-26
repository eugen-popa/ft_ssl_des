/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:47:55 by eupopa            #+#    #+#             */
/*   Updated: 2017/09/25 20:45:32 by eupopa           ###   ########.fr       */
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
			if (i == 0)
			{
				if(ac > 2 && !ft_strcmp(av[2], "-d")) 
				{
					get_next_line(0, &new_line);	
				//	ft_decript(new_line);
					ft_printf("%s\n", new_line);
				}
				else
				{
					get_next_line(0, &new_line);
					ft_incript(new_line);
				//	ft_printf("%s\n", new_line);
				}
			}
		}
	}
	else
		ft_printf("%s\n", "ERROR");
		
	return (0);
}

