/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showtabint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:11:26 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:13:52 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_tab_show(int *a, int nb_nb, char *tabname, int rev)
{
	int i;

	i = -1;
	ft_printf("\n");
	if (nb_nb > 0 && rev)
	{
		i = nb_nb;
		while (--i >= 0)
		{
			ft_printf("  {lyellow}%s{lred}[{lcyan}%03d{lred}]", tabname, i);
			ft_printf("{eoc} = {lgreen}%03d{eoc}\n", a[i]);
		}
	}
	while (!rev && ++i < nb_nb)
	{
		ft_printf("  {lyellow}%s{lred}[{lcyan}%03d{lred}]", tabname, i);
		ft_printf("{eoc} = {lgreen}%03d{eoc}\n", a[i]);
	}
	if (nb_nb == 0)
		ft_printf("  {lyellow}%s {lcyan}➜ {lred} 0 element{eoc}\n", tabname);
	ft_printf("\n");
}
