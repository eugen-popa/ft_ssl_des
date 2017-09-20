/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_caps_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:50:19 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:33 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_termcaps_rightcurs(int nbcol)
{
	ft_printf("\033[%dC", nbcol);
}

void	ft_termcaps_savecurs(void)
{
	ft_putstr("\033[s");
}

void	ft_termcaps_screenclear(void)
{
	ft_putstr("\e[0;0H\e[2J");
}

void	ft_termcaps_upline(int nbline)
{
	ft_printf("\033[%dA", nbline);
}
