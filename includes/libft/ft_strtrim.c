/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:48 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	if (s)
	{
		len = ft_without_space_len(s);
		if (len > 0)
		{
			i = 0;
			result = ft_strnew(len);
			if (result)
			{
				while (s[i] && ft_isspace(s[i]))
					i++;
				if (!*(s + i))
					return (ft_strnew(0));
				ft_strncpy(result, &s[i], len);
			}
			return (result);
		}
	}
	return (ft_strnew(0));
}
