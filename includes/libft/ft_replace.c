/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:42 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_select_len_res(char *search, char *r, char *str)
{
	size_t	len_str;
	size_t	len_search;
	size_t	len_r;

	len_str = ft_strlen(str);
	len_search = ft_strlen(search);
	len_r = ft_strlen(r);
	return (len_str + (len_r - len_search));
}

char			*ft_replace(char *search, char *r, char *str, int f)
{
	char	*result;
	char	*ftstrstr;
	int		i;
	size_t	j;

	result = str;
	while (str != NULL && ft_strstr(str, search))
	{
		result = ft_strnew(ft_select_len_res(search, r, str));
		ftstrstr = ft_strstr(str, search);
		i = -1;
		while (ft_strcmp(&str[++i], ftstrstr) != 0)
			result[i] = str[i];
		ft_strcat(result, r);
		j = i + ft_strlen(r);
		i += ft_strlen(search);
		while (str[i] != '\0')
			result[j++] = str[i++];
		(f == 2 || f == 4 || f == 5) ? free(search) : 0;
		(f == 3 || f == 5 || f == 6) ? free(r) : 0;
		(f == 1 || f == 4 || f == 6) ? free(str) : 0;
		str = result;
	}
	return (result);
}
