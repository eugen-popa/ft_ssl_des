/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabsorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:33:45 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_inttabsorted(int *tab, int size)
{
	int i;
	int rev;

	i = -1;
	rev = 0;
	while (++i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			rev = 1;
			break ;
		}
	}
	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			if (rev)
				return (0);
			rev = -1;
			break ;
		}
	}
	return (rev);
}
