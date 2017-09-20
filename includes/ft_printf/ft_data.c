/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:46:51 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:11:53 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modif_info(t_pf_data *data)
{
	size_t	deleted;

	data->modif.hh = 0;
	data->modif.h = 0;
	data->modif.l = 0;
	data->modif.ll = 0;
	data->modif.j = 0;
	data->modif.z = 0;
	data->modif.m = 0;
	while (ft_strstr(data->setting, "z") || ft_strstr(data->setting, "h")
		|| ft_strstr(data->setting, "j") || ft_strstr(data->setting, "l"))
	{
		if ((deleted = ft_delcharinstr(&(data->setting), 'l', 1)) > 0)
			(deleted % 2 == 1) ? (data->modif.l = 1) :
		(data->modif.ll = 1);
		if ((deleted = ft_delcharinstr(&(data->setting), 'h', 1)) > 0)
			(deleted % 2 == 1) ? (data->modif.h = 1) :
		(data->modif.hh = 1);
		if (ft_delcharinstr(&(data->setting), 'j', 1))
			data->modif.j = 1;
		if (ft_delcharinstr(&(data->setting), 'z', 1))
			data->modif.z = 1;
	}
}

int		check_specif(char s)
{
	if (s == 's' || s == 'S' || s == 'p' || s == 'd' || s == 'D' || s == 'i'
		|| s == 'o' || s == 'O' || s == 'u' || s == 'U' || s == 'x' || s == 'X'
		|| s == 'c' || s == 'C' || s == '%' || s == 'h' || s == 'l' || s == 'j'
		|| s == 'z' || s == 'f' || s == 'F' || s == ' ')
		return (1);
	return (0);
}

void	initprec(t_pf_data *data)
{
	char *prec;

	prec = ft_strdup(&data->setting[ft_nbchar(data->setting, '.') + 1]);
	data->setting = ft_strsub(data->setting, 0,
		ft_nbchar(data->setting, '.'), 1);
	data->precision = ft_atoi(prec);
	if (data->precision == 0)
		data->precision = -1;
	else if (data->precision < 0)
		data->precision = 0;
	ft_strdel(&prec);
}

int		pf_initdata2(t_pf_data *data)
{
	data->flag.cmpltchar = ' ';
	if (ft_delcharinstr(&(data->setting), '0', 1) > 0 && !data->flag.signminus)
		data->flag.cmpltchar = '0';
	info_size_end(data);
	modif_info(data);
	ft_strcpy((data->ox = ft_strnew(2)),
		(ft_isupper(data->specif)) ? "0X" : "0x");
	if (ft_isupper(data->specif))
	{
		data->modif.l = (data->specif != 'X' || data->modif.l) ? 1 : 0;
		data->modif.m = 1;
		data->specif = ft_tolower(data->specif);
	}
	(data->specif == 'o') ? (data->ox[1] = '\0') : 0;
	ft_strdel(&data->setting);
	return (1);
}

int		pf_initdata(t_pf_data *data, va_list ap)
{
	initpreset(data, ap);
	if (ft_strchr(data->setting, '.') != 0)
		initprec(data);
	if (data->specif == 'p' || ft_strchr(data->setting, '#') != 0)
	{
		if (data->specif == 'O' || data->specif == 'x' ||
			data->specif == 'X' || data->specif == 'o' ||
			data->specif == 'p')
			data->flag.pound = 1;
		data->setting = ft_replace("#", "", data->setting, 1);
	}
	if (ft_strchr(data->setting, '+') != 0)
		data->flag.signplus = 1;
	if (ft_strchr(data->setting, ' ') != 0)
		data->space = (data->flag.signplus) ? 0 : 1;
	else if (ft_strchr(data->setting, '-') != 0)
		data->flag.signminus = 1;
	data->setting = ft_replace(" ", "", data->setting, 1);
	data->setting = ft_replace("-", "", data->setting, 1);
	data->setting = ft_replace("+", "", data->setting, 1);
	return (pf_initdata2(data));
}
