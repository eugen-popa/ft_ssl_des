/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:32:27 by eupopa            #+#    #+#             */
/*   Updated: 2017/09/26 14:47:47 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ssl.h"

void	ft_function(int i, char  *line, int c)
{
		c = line[i] >> 2;
		ft_putchar(g_base64[c]);
		c = ((line[i] & 0x3) << 4) | (line[i + 1] >> 4);
		ft_putchar(g_base64[c]);
		c = ((line[i + 1] & 0xF) << 2) | (line [i + 2] >> 6);
		ft_putchar(g_base64[c]);
		c = (line[i + 2] & 0x3F);
		ft_putchar(g_base64[c]);
}

void	ft_incript(char *line)
{	
	int i;
	int lin;
	int c;

	c = 0;
	i = 0;

	lin = ft_strlen(line);
	while(i < lin - 2)
	{
		ft_function(i, line, c);
		i += 3;
	}
	if(line[i])
	{
		ft_putchar(g_base64[line[i] >> 2]);
		if (line[i + 1])
		{	
			c = ((line[i] & 0x3) << 4 | (line[i + 1] >> 4));
			ft_putchar(g_base64[c]);
			c = ((line[i + 1] & 0xF) << 2);
			ft_putchar(g_base64[c]);
		}
		else
		{
			c = ((line[i] & 0x3) << 4);
			ft_putchar(g_base64[c]);
			ft_putchar('=');
		}
		ft_putchar('=');
	}
}

