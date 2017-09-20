/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nreplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:36 by eupopa           ###   ########.fr       */
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

char			*ft_nreplace(char *search, char *r, char *str, int n)
{
	char	*result;
	char	*ftstrstr;
	int		i;
	size_t	j;

	if (str == NULL)
		return (NULL);\
	result = ft_strnew(ft_select_len_res(search, r, str));
	ftstrstr = ft_strstr(str, search);
	i = -1;
	while (ft_strcmp(&str[++i], ftstrstr) != 0)
		result[i] = str[i];
	ft_strcat(result, r);
	j = i + ft_strlen(r);
	i += ft_strlen(search);
	ft_strcpy(&result[j], &str[i]);
	if (n == 1 || n == 4 || n == 5 || n == 7)
		free(search);
	if (n == 2 || n == 4 || n == 5 || n == 6)
		free(r);
	if (n == 3 || n == 4 || n == 6 || n == 7)
		free(str);
	return (result);
}
