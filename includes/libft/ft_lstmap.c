/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:30 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l_tmp;
	t_list	*l_result;

	if (!lst || !f)
		return (NULL);
	l_result = f(lst);
	l_tmp = l_result;
	lst = lst->next;
	while (lst)
	{
		l_tmp->next = f(lst);
		l_tmp = l_tmp->next;
		lst = lst->next;
	}
	return (l_result);
}
