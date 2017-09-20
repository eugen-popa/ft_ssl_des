/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:47:18 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:11 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_nb(t_pf_data *data, char **a)
{
	char	*tmp;

	if (data->precision > 0)
	{
		data->flag.cmpltchar = ' ';
		if ((*a)[0] != '-' && data->precision > (int)ft_strlen((*a)))
			(*a) = ft_strjoin(ft_chartostr('0',
				data->precision - ft_strlen((*a))), (*a), 3);
		else if ((*a)[0] == '-' && data->precision > (int)ft_strlen((*a)) - 1)
		{
			tmp = (*a);
			(*a) = ft_strjoin(ft_chartostr('0', data->precision -
				ft_strlen((*a)) + 1), &(*a)[1], 1);
			(*a) = ft_strjoin("-", (*a), 2);
			ft_strdel(&tmp);
		}
		(data->specif == 'o') ? (data->flag.pound = 0) : 0;
	}
	else if (data->precision < 0 && ft_strcmp("0", *a) == 0 &&
		(data->flag.cmpltchar = ' '))
	{
		(data->specif == 'x') ? (data->flag.pound = 0) : 0;
		ft_strclr(*a);
	}
	return ((*a));
}

char	*ft_str_cons(t_pf_data *data, char *a)
{
	if (a && data->flag.sizeend > (int)ft_strlen(a))
		a = (data->flag.signminus) ? (ft_strjoin(a, ft_chartostr(' '
			, data->flag.sizeend - ft_strlen(a)), 3)) : (ft_strjoin(
			ft_chartostr(data->flag.cmpltchar,
				data->flag.sizeend - ft_strlen(a)), a, 3));
	return (a);
}
