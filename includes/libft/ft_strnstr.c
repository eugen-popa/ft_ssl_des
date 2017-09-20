/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:46 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	n2;
	int		lastresult;

	if (*s2 == '\0')
		return ((char*)s1);
	n2 = ft_strlen(s2);
	lastresult = 1;
	while (n2 <= n && *s1 != '\0'
		&& (lastresult = ft_strncmp(s1, s2, n2)))
	{
		n--;
		s1++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)s1);
}
