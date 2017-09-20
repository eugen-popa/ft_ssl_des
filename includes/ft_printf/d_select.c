/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_select.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:48:03 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:11:47 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d_cons_nbplus(t_pf_data *data, char **a)
{
	if (data->flag.signplus && data->flag.cmpltchar == ' ')
		*a = ft_strjoin("+", *a, 2);
	if (data->flag.signplus && data->flag.cmpltchar != ' ')
		data->flag.sizeend--;
	if (data->flag.sizeend > (int)LEN(*a))
		*a = ft_strjoin(ft_chartostr(data->flag.cmpltchar, data->flag.sizeend
			- LEN(*a)), *a, 3);
	if (data->flag.signplus && data->flag.cmpltchar != ' ')
		*a = ft_strjoin("+", *a, 2);
	(data->space) ? (*a = ft_strjoin(" ", *a, 2)) : 0;
}

void	ft_d_cons_nbminus(t_pf_data *data, char **a)
{
	if (data->flag.cmpltchar != ' ')
	{
		ft_delcharinstr(a, '-', 1);
		data->flag.sizeend--;
	}
	if (data->flag.sizeend > (int)LEN(*a))
		*a = ft_strjoin(ft_chartostr(data->flag.cmpltchar, data->flag.sizeend
			- LEN(*a)), *a, 3);
	(data->flag.cmpltchar != ' ') ? (*a = ft_strjoin("-", *a, 2)) : 0;
}

void	ft_d_cons_m(t_pf_data *data, char **a)
{
	if (data->flag.signplus && *a[0] != '-')
		*a = ft_strjoin("+", *a, 2);
	if (data->flag.sizeend > (int)LEN(*a))
		*a = ft_strjoin(*a, ft_chartostr(' ', data->flag.sizeend
			- LEN(*a)), 3);
	(*a[0] != '-' && data->space) ? (*a = ft_strjoin(" ", *a, 2)) : 0;
}

char	*ft_d_cons(t_pf_data *data, char *a)
{
	(data->space) ? (data->flag.sizeend -= 1) : 0;
	if (!data->flag.signminus)
		if (a[0] != '-')
			ft_d_cons_nbplus(data, &a);
		else
			ft_d_cons_nbminus(data, &a);
	else
		ft_d_cons_m(data, &a);
	return (a);
}

char	*select_d(t_pf_data *data, va_list ap)
{
	char	*a;

	if (data->modif.z)
		a = ft_itoa_base(va_arg(ap, size_t), 10);
	else if (data->modif.ll || data->modif.j)
		a = ft_itoa_base(va_arg(ap, long long int), 10);
	else if (data->modif.l)
		a = ft_itoa_base(va_arg(ap, long int), 10);
	else if (data->modif.h)
		a = ft_itoa_base((short)va_arg(ap, int), 10);
	else if (data->modif.hh)
		a = ft_itoa_base((char)va_arg(ap, int), 10);
	else
		a = ft_itoa_base(va_arg(ap, int), 10);
	return (ft_d_cons(data, precision_nb(data, &a)));
}
