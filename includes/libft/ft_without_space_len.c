/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_without_space_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:48 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_without_space_len(const char *str)
{
	unsigned int space_len;
	unsigned int len;
	unsigned int i;

	space_len = 0;
	i = 0;
	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		while (str[i] && ft_isspace(str[i++]))
			space_len++;
		if (i < len)
		{
			i = len - 1;
			while (str[i] && ft_isspace(str[i--]))
				space_len++;
		}
	}
	return (len - space_len);
}
