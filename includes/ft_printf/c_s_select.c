/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_s_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:47:49 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:11:44 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*select_c(t_pf_data *data, va_list ap, t_ret *retval)
{
	int n;
	int pos;

	pos = 0;
	if (data->modif.l)
		n = va_arg(ap, int);
	else
		n = (char)va_arg(ap, int);
	if (n == 0)
	{
		while (retval->posb[pos] > -1)
			pos++;
		retval->posb[pos] = (data->flag.sizeend == 0 ||
			data->flag.signminus) ? LEN(retval->finalstr) : (LEN(
				retval->finalstr) + data->flag.sizeend - 1);
		data->adjusting++;
		n = 'a';
	}
	return (ft_str_cons(data, ft_wchrtostr(n)));
}

char	*select_s(t_pf_data *data, va_list ap)
{
	char *a;

	if ((data->modif.l || data->modif.ll) && data->precision >= 0)
		a = ft_nwstrtostr(va_arg(ap, wchar_t*), data->precision);
	else if (data->precision >= 0)
		a = ft_strndup(va_arg(ap, char*), data->precision);
	else
		a = ft_strdup("");
	return (ft_str_cons(data, a));
}
