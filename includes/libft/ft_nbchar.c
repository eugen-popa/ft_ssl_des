/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:35 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbchar(const char *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	if (s && c)
	{
		while (s[i] && s[i++] != c)
			nb++;
	}
	return (nb);
}
