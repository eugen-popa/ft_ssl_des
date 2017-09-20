/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:46:58 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:11:56 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*del_chraround(char *set, int pos, int arg)
{
	int poscopy;

	poscopy = pos;
	while (--pos >= 0 && set[pos] != ' ' && set[pos] != '#' && set[pos] != '-'
		&& set[pos] != '+' && set[pos] != '.')
		set[pos] = '}';
	pos = poscopy;
	if (set[++pos] != '\0' && set[pos] != '.' && set[pos] != '#' &&
		set[pos] != '-' && set[pos] != '+' && set[pos] != ' ')
		set[poscopy] = (arg < 0) ? '-' : '}';
	return (ft_replace("}", "", set, 1));
}

char	*transform(char *set, va_list ap)
{
	int nbr;
	int ar;

	while (ft_strstr(set, "*"))
	{
		nbr = ft_nbchar(set, '*');
		ar = va_arg(ap, int);
		set = del_chraround(set, nbr, ar);
		if (ft_strstr(set, "*"))
			set = (ar != 0) ? ft_nreplace("*", ft_itoa_base(ar, 10),
				set, 6) : ft_nreplace("*", "", set, 3);
	}
	return (set);
}

void	info_size_end(t_pf_data *data)
{
	char *bfr;

	data->flag.sizeend = ft_atoi(data->setting);
	if (data->flag.sizeend > 0)
	{
		bfr = data->setting;
		data->setting = ft_strsub(data->setting, ft_intlen(data->flag.sizeend),
			LEN(data->setting) - ft_intlen(data->flag.sizeend), 0);
		ft_strdel(&bfr);
	}
}

void	initpreset(t_pf_data *data, va_list ap)
{
	data->size = LEN(data->setting);
	data->specif = data->setting[data->size - 1];
	data->setting[data->size - 1] = '\0';
	if (check_specif(data->specif))
		data->invalidspe = NULL;
	else
		data->invalidspe = ft_chartostr(data->specif, 1);
	data->flag.sizeend = 0;
	data->flag.signminus = 0;
	data->flag.pound = 0;
	data->flag.signplus = 0;
	data->precision = 0;
	data->space = 0;
	data->setting = transform(data->setting, ap);
	while (ft_strstr(data->setting, ".."))
		data->setting = ft_replace("..", ".", data->setting, 1);
}
