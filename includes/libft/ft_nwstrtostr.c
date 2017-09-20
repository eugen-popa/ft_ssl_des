/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwstrtostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:37 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nwstrtostrcheck(size_t j, size_t jcopy, wchar_t *str, size_t i)
{
	return ((jcopy == 0 || (str[i] <= 0x7F && j >= 1) ||
			(str[i] <= 0x7FF && j >= 2) || (str[i] <= 0xFFFF && j >= 3) ||
			(str[i] <= 0x10FFFF && j >= 4)) ? 1 : 0);
}

char	*ft_nwstrtostr(wchar_t *str, size_t j)
{
	char	*result;
	size_t	i;
	size_t	jcopy;

	if (!str)
		return (NULL);
	i = 0;
	jcopy = j;
	result = ft_strnew(0);
	while (str[i] && (0 < j || jcopy == 0))
	{
		if (ft_nwstrtostrcheck(j, jcopy, str, i))
			result = ft_strjoin(result, ft_wchrtostr(str[i]), 3);
		if (str[i] <= 0x7F && j >= 1)
			j -= 1;
		else if (str[i] <= 0x7FF && j >= 2)
			j -= 2;
		else if (str[i] <= 0xFFFF && j >= 3)
			j -= 3;
		else if (str[i] <= 0x10FFFF && j >= 4)
			j -= 4;
		i++;
	}
	return (result);
}
