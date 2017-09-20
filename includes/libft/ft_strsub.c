/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:47 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len, size_t f)
{
	char	*result;

	if (len <= 0)
		return (ft_strnew(0));
	result = ft_strnew(len);
	if (s && result && ft_strlen(s) >= len)
		ft_strncpy(result, s + start, len);
	(f == 1) ? free((char *)s) : 0;
	return (result);
}
