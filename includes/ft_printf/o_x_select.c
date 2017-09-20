/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_x_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:48:55 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:14 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_x_cons(t_pf_data *data, char *a)
{
	if (data->flag.pound && ft_strcmp("0", a))
	{
		if (data->flag.cmpltchar == ' ')
			a = ft_strjoin(data->ox, a, 2);
		else
			data->flag.sizeend -= 2;
	}
	if (a && data->flag.sizeend > (int)ft_strlen(a))
		a = (data->flag.signminus) ? (ft_strjoin(a, ft_chartostr(' ',
			data->flag.sizeend - ft_strlen(a)), 3)) : (ft_strjoin(
			ft_chartostr(data->flag.cmpltchar, data->flag.sizeend -
				ft_strlen(a)), a, 3));
	(data->flag.pound &&
		ft_strcmp("0", a) && data->flag.cmpltchar == '0') ?
	(a = ft_strjoin(data->ox, a, 2)) : 0;
	return (a);
}

char	*select_x(t_pf_data *data, va_list ap)
{
	char		*a;
	t_uintmax	nb;

	if (data->modif.l && !data->modif.hh && !data->modif.ll
		&& !data->modif.j && !data->modif.z)
		nb = va_arg(ap, unsigned long int);
	else if ((data->modif.ll || data->modif.j || data->modif.z))
		nb = va_arg(ap, unsigned long long int);
	if (data->modif.hh)
		nb = (unsigned char)va_arg(ap, int);
	else if (!data->modif.l && !data->modif.ll
		&& !data->modif.j && !data->modif.z)
		nb = va_arg(ap, unsigned int);
	a = ft_itoa_base(nb, 16);
	if (data->modif.m)
		ft_strtoupper(&a);
	return (ft_x_cons(data, precision_nb(data, &a)));
}

char	*select_o(t_pf_data *data, va_list ap)
{
	char		*a;

	if (data->modif.ll
		|| data->modif.j || data->modif.z)
		a = ft_itoa_base(va_arg(ap, t_uintmax), 8);
	else if (data->modif.l)
		a = ft_itoa_base(va_arg(ap, long int), 8);
	else if (data->modif.h)
		a = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), 8);
	else if (data->modif.hh)
		a = ft_itoa_base((unsigned char)va_arg(ap, int), 8);
	else
		a = ft_itoa_base(va_arg(ap, unsigned int), 8);\
	return (ft_x_cons(data, precision_nb(data, &a)));
}
