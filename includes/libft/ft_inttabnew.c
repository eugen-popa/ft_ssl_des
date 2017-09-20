/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:33:42 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_inttabnew(size_t size)
{
	int	*dst;
	int	i;

	dst = (int *)malloc(sizeof(int) * (size + 1));
	if (dst)
	{
		i = size + 1;
		while (--i >= 0)
			dst[i] = -1;
		return (dst);
	}
	return (NULL);
}
