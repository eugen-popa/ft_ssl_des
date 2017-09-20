/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:28 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrtostr(wchar_t *str)
{
	char	*result;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	result = ft_strnew(0);
	while (str[i])
		result = ft_strjoin(result, ft_wchrtostr(str[i++]), 3);
	return (result);
}
