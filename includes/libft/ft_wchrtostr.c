/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:48 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wchrtostr(wchar_t chr)
{
	char *str;

	str = ft_strnew(0);
	if (chr <= 0x7F)
		str = ft_strjoin(str, ft_chartostr(chr, 1), 3);
	else if (chr <= 0x7FF)
	{
		str = ft_strjoin(str, ft_chartostr((chr >> 6) + 0xC0, 1), 3);
		str = ft_strjoin(str, ft_chartostr((chr & 0x3F) + 0x80, 1), 3);
	}
	else if (chr <= 0xFFFF)
	{
		str = ft_strjoin(str, ft_chartostr((chr >> 12) + 0xE0, 1), 3);
		str = ft_strjoin(str, ft_chartostr(((chr >> 6) & 0x3F) + 0x80, 1), 3);
		str = ft_strjoin(str, ft_chartostr((chr & 0x3F) + 0x80, 1), 3);
	}
	else if (chr <= 0x10FFFF)
	{
		str = ft_strjoin(str, ft_chartostr((chr >> 18) + 0xF0, 1), 3);
		str = ft_strjoin(str, ft_chartostr(((chr >> 12) & 0x3F) + 0x80, 1), 3);
		str = ft_strjoin(str, ft_chartostr(((chr >> 6) & 0x3F) + 0x80, 1), 3);
		str = ft_strjoin(str, ft_chartostr((chr & 0x3F) + 0x80, 1), 3);
	}
	return (str);
}
