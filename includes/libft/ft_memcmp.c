/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:32 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			n2;
	unsigned char	*c1;
	unsigned char	*c2;

	n2 = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (n2 < n)
	{
		if (c1[n2] != c2[n2])
			return (c1[n2] - c2[n2]);
		n2++;
	}
	return (0);
}
