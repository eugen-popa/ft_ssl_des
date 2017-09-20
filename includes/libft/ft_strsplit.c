/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:47 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_str_find_next(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			ft_str_count_splits(const char *str, char seps)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_next(str, seps, 1);
		if (*str != '\0')
		{
			i++;
			str = ft_str_find_next(str, seps, 0);
		}
	}
	return (i);
}

static char			**ft_tabledel(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(ret[i]);
	free(ret);
	return (NULL);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**result;
	int			i;
	const char	*next;

	if (str == NULL)
		return (NULL);
	result = (char**)malloc(sizeof(char*) * (ft_str_count_splits(str, c) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_next(str, c, 1);
		if (*str != '\0')
		{
			next = ft_str_find_next(str, c, 0);
			result[i] = ft_strsub(str, 0, next - str, 0);
			if (result[i] == NULL)
				return (ft_tabledel(result, i));
			i++;
			str = next;
		}
	}
	result[i] = 0;
	return (result);
}
