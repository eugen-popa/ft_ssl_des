/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:31 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*bfr;
	t_list	*bfr2;

	if (!lst || !*lst)
		return ;
	bfr = NULL;
	while (*lst)
	{
		bfr2 = (*lst)->next;
		(*lst)->next = bfr;
		bfr = *lst;
		*lst = bfr2;
	}
	*lst = bfr;
}
