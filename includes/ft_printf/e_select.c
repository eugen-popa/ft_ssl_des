/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_select.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:48:27 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:11:50 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*select_e(t_pf_data *data, va_list ap)
{
	char			*a;
	long double		nb;
	long double		nb2;
	int				i;

	nb = va_arg(ap, long double);
	i = 0;
	nb2 = nb;
	if (nb < 0)
		nb2 = -nb;
	while (nb2 / ft_pwe(10, i) > 10)
	{
		nb2 /= 10;
		i++;
	}
	a = ft_strjoin(ft_ftoa(nb2, 6), ft_strjoin(
		(data->modif.m) ? "E+" : "e+", (i > 10) ? ft_itoa_base(i, 10) :
		ft_strjoin("0", ft_itoa_base(i, 10), 2), 2), 3);
	return ((nb < 0) ? ft_strjoin("-", a, 2) : a);
}
