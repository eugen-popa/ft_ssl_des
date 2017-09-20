/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:44 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int i)
{
	char	*result;

	if (s1 && s2)
	{
		result = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (result)
		{
			ft_strcpy(result, s1);
			ft_strcat(result, s2);
		}
		else
			result = NULL;
	}
	else
		result = NULL;
	if (i == 1 || i == 3)
		ft_strdel((char **)&s1);
	if (i == 2 || i == 3)
		ft_strdel((char **)&s2);
	return (result);
}
