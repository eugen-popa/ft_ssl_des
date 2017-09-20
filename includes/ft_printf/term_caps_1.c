/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_caps_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:50:11 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:29 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_termcaps_downline(int nbline)
{
	ft_printf("\033[%dB", nbline);
}

void	ft_termcaps_leftcurs(int nbcol)
{
	ft_printf("\033[%dD", nbcol);
}

void	ft_termcaps_lineclear(void)
{
	ft_putstr("\033[K");
}

void	ft_termcaps_poscurs(int line, int col)
{
	ft_printf("\033[%d;%dH", line, col);
}

void	ft_termcaps_restorecurs(void)
{
	ft_putstr("\033[u");
}
