/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delcharinstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:33:09 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delcharinstr(char **alpha, char c, int s)
{
	size_t		i;
	char		*new_alpha;
	int			len;

	i = 0;
	len = ft_strlen(*alpha);
	if (s == 0)
		*alpha = ft_strrev(*alpha);
	while ((*alpha)[i] == c)
		i++;
	if (i == 0)
		return (0);
	new_alpha = ft_strnew(len - i);
	ft_strcpy(new_alpha, &(*alpha)[i]);
	ft_strdel(alpha);
	(*alpha) = new_alpha;
	return (i);
}
