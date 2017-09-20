/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:47:26 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:02 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	concfinal(t_ret *retval, char **a, t_pf_data *data)
{
	if (*a == NULL)
		ft_strcpy((*a = ft_strnew(6)), "(null)");
	retval->finalstr = ft_strjoin(retval->finalstr, (*a), 3);
	ft_strdel(&data->ox);
}

static void	select_2(t_pf_data *data, va_list ap, t_ret *retval, char **a)
{
	if (data->specif == 'd' || (data->specif == 'i' &&
		!data->modif.m))
		(*a) = select_d(data, ap);
	else if ((*a) == NULL && data->specif == '%')
		(*a) = ft_str_cons(data, ft_chartostr('%', 1));
	else if ((*a) == NULL && data->specif == 's')
		(*a) = select_s(data, ap);
	else if ((*a) == NULL && data->specif == 'c')
		(*a) = select_c(data, ap, retval);
	else if ((*a) == NULL && data->specif == 'p' && !data->modif.m)
		(*a) = select_p(data, ap);
	else if ((*a) == NULL && data->specif == 'u')
		(*a) = select_u(data, ap);
	else if ((*a) == NULL && data->specif == 'o')
		(*a) = select_o(data, ap);
	else if ((*a) == NULL && data->specif == 'f')
		(*a) = ft_ftoa(va_arg(ap, double), (data->precision == 0) ? 6 :
			data->precision);
	else if ((*a) == NULL && data->specif == 'x')
		(*a) = select_x(data, ap);
	else if ((*a) == NULL && data->invalidspe != NULL)
		(*a) = ft_str_cons(data, data->invalidspe);
	concfinal(retval, a, data);
}

void		pf_select(t_pf_data *data, va_list ap, t_ret *retval)
{
	char	*a;

	a = ((data->specif == 'j' || data->specif == 'z' ||
		data->specif == 'l' || data->specif == 'h'
		|| data->specif == ' ') && !data->modif.m) ? ft_strnew(0) : NULL;
	if (data->specif == 'n' && !data->modif.m)
		a = select_n(ap, retval);
	else if (data->specif == 'e')
		a = select_e(data, ap);
	select_2(data, ap, retval, &a);
	data->i += data->size;
}
