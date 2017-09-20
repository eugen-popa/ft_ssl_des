/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:58:31 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:11:59 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_specif(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == 'l' || s[i] == 'h' ||
	s[i] == 'z' || s[i] == 'j' || s[i] == '.' || s[i] == '#' || s[i] == '+' ||
	s[i] == '-' || s[i] == ' ' || s[i] == '*' || s[i] == 'L'))
		i++;
	return (i + 1);
}

void	pf_setting(char **setting, char const *s, int i)
{
	int	size;

	size = pf_specif(&s[i + 1]);
	*setting = ft_strnew(size);
	ft_strncpy(*setting, &s[i + 1], size);
}

void	pf_fill(char const *s, va_list ap, t_ret *retval, t_pf_data *data)
{
	data->i = 0;
	data->adjusting = 0;
	retval->posb = ft_inttabnew(ft_countchar(s, '%'));
	while (s[data->i] != '\0')
	{
		if (s[data->i] == '%')
		{
			pf_setting(&((*data).setting), s, data->i);
			if (data->setting[0] != '\0' && pf_initdata(data, ap))
				pf_select(data, ap, retval);
			else if (data->setting[0] == '\0')
				free((*data).setting);
		}
		else
			retval->finalstr = ft_strjoin(retval->finalstr,
				ft_chartostr(s[data->i], 1), 3);
		data->i++;
	}
}

void	ft_putstrerror(t_ret *retval)
{
	int pos;
	int i;

	pos = 0;
	i = 0;
	while (retval->finalstr[i])
	{
		if (retval->posb[pos] == i)
		{
			pos++;
			ft_putchar('\0');
		}
		else
			ft_putchar(retval->finalstr[i]);
		i++;
	}
	retval->return_val = ft_strlen(retval->finalstr);
}

int		ft_printf(char const *s, ...)
{
	va_list		ap;
	t_pf_data	data;
	t_ret		retval;

	if (!s)
		return (0);
	retval.finalstr = ft_strnew(pf_specif(s));
	data.ox = NULL;
	va_start(ap, s);
	pf_fill(s, ap, &retval, &data);
	va_end(ap);
	reinbow(&(retval.finalstr));
	if (retval.posb[0] > -1)
		ft_putstrerror(&retval);
	else
		retval.return_val = ft_putstr(retval.finalstr);
	ft_strdel(&retval.finalstr);
	free(retval.posb);
	return (retval.return_val);
}
