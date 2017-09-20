/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_select.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:48:39 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:08 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*select_n(va_list ap, t_ret *retval)
{
	int *n;

	n = va_arg(ap, int*);
	if (n)
		*n = (int)ft_strlen(retval->finalstr);
	return (ft_strnew(0));
}
