/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coltostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:33:01 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_coltostr(char **array, size_t c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_strnew(4);
	while (array[i])
	{
		str[i] = array[i][c];
		i++;
	}
	return (str);
}
