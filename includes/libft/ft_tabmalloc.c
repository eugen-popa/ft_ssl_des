/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:48 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	ft_tabmalloc(size_t side, char i)
{
	t_tab	tab;
	size_t	j;

	tab = (t_tab)malloc(sizeof(char *) * (side + 1));
	if (!tab)
		return (NULL);
	tab[side] = NULL;
	j = 0;
	while (j < side)
	{
		tab[j] = ft_strnew(side);
		if (!tab[j])
			return (NULL);
		ft_memset(tab[j], i, side);
		tab[j][side] = '\0';
		j++;
	}
	return (tab);
}
