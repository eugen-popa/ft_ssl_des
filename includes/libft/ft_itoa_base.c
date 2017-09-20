/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:34:17 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(t_intmax n, int base)
{
	static char	itoa_num[] = "0123456789abcdef\0";
	char		*alpha;
	t_uintmax	nb;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	alpha = ft_strnew(0);
	if (n < 0)
		nb = (base == 10) ? (t_uintmax)(-n) : ((t_uintmax)n);
	while (nb > 0)
	{
		alpha = ft_strjoin(alpha, ft_chartostr(itoa_num[nb % base], 1), 3);
		nb /= base;
	}
	(n < 0 && base == 10) ? (alpha = ft_strjoin(alpha, "-", 1)) : 0;
	ft_delcharinstr(&alpha, '0', 0);
	return (alpha);
}
