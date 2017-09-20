/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:33:12 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ftoa_cdt(char **bb, char **b, t_intmax *ent, size_t prec)
{
	char	*b_copy;
	char	*bb_copy;

	b_copy = *b;
	bb_copy = ft_strsub(b_copy, 0, prec, 0);
	if (b_copy[prec] >= '5')
		bb_copy[prec - 1] += 1;
	while (prec > 0 && bb_copy[prec - 1] == ':')
	{
		bb_copy[prec - 2] += 1;
		bb_copy[prec - 1] = '0';
		prec--;
	}
	if (!prec)
		*ent += 1;
	*bb = bb_copy;
	*b = b_copy;
	return (prec);
}

char		*ft_ftoa_init(t_intmax *ent, double *f)
{
	t_intmax ent2;

	(*ent) = (t_intmax)(*f);
	ent2 = *ent;
	(*f) = (*f) - (*ent);
	if ((*ent) < 0)
	{
		(*ent) = -(*ent);
		(*f) = -(*f);
	}
	return (ft_strdup((ent2 < 0) ? "-" : ""));
}

char		*ft_ftoa(double f, size_t precision)
{
	char		*a;
	char		*b;
	char		*bb;
	t_intmax	ent;

	if (f == 0)
		return (ft_strjoin("0.", ft_chartostr('0', precision), 2));
	a = ft_ftoa_init(&ent, &f);
	while (f - (t_intmax)f > 0)
		f *= 10;
	b = ft_itoa_base((t_intmax)f, 10);
	if ((bb = b) && ft_strlen(b) > precision)
		precision = ft_ftoa_cdt(&bb, &b, &ent, precision);
	else
		bb = ft_strjoin(bb, ft_chartostr('0', precision - ft_strlen(bb)), 3);
	a = ft_strjoin(ft_strjoin(a, ft_itoa_base(ent, 10), 3), ".", 1);
	a = ft_strjoin(a, bb, 3);
	return (a);
}
