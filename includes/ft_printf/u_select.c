/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_select.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:49:22 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:36 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u_cons(t_pf_data *data, char *a)
{
	if (data->flag.sizeend > (int)ft_strlen(a) && !data->flag.signminus)
		a = ft_strjoin(ft_chartostr(data->flag.cmpltchar, data->flag.sizeend
			- ft_strlen(a)), a, 3);
	else if (data->flag.sizeend > (int)ft_strlen(a) && data->flag.signminus)
		a = ft_strjoin(a, ft_chartostr(' ', data->flag.sizeend
			- ft_strlen(a)), 3);
	return (a);
}

char	*select_u(t_pf_data *data, va_list ap)
{
	t_uintmax	n;
	t_uintmax	gh;
	char		*a;

	if (data->modif.l || data->modif.ll || data->modif.j || data->modif.z)
	{
		n = va_arg(ap, t_uintmax);
		gh = 1000000000;
		gh *= 10000000000;
		a = (n > gh) ? ft_strjoin(ft_strdup("1"), ft_itoa_base(n - gh, 10),
			3) : ft_itoa_base(n, 10);
	}
	else if (data->modif.h && !data->modif.z)
		a = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), 10);
	else if (data->modif.hh && !data->modif.z)
		a = ft_itoa_base((unsigned char)va_arg(ap, int), 10);
	else
		a = ft_itoa_base(va_arg(ap, unsigned int), 10);
	return (ft_u_cons(data, precision_nb(data, &a)));
}
