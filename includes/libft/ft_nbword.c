/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:35 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbword(const char *s, const char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	if (s && c)
	{
		if (s[0] && s[0] != c)
			count = 1;
		else
			count = 0;
		i = 1;
		while (s[0] && s[i])
		{
			if (s[i - 1] == c && s[i] != c)
				count++;
			i++;
		}
	}
	return (count);
}
