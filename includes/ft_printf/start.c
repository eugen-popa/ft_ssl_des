/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:45:55 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:26 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	start(int nbarg, ...)
{
	va_list	ap;
	int		i;
	int		min;
	int		tmp;

	i = nbarg;
	if (nbarg <= 0)
		return (0);
	va_start(ap, nbarg);
	min = va_arg(ap, int);
	while (i-- > 1)
	{
		tmp = va_arg(ap, int);
		if (tmp < min)
			min = tmp;
	}
	va_end(ap);
	return (min);
}
