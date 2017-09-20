/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:37:30 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l_new;

	l_new = (t_list*)malloc(sizeof(t_list));
	if (!l_new)
		return (NULL);
	if (!content)
	{
		l_new->content = NULL;
		l_new->content_size = 0;
	}
	else
	{
		l_new->content = (void *)malloc(sizeof(char) * content_size);
		ft_memcpy(l_new->content, content, content_size);
		l_new->content_size = content_size;
	}
	l_new->next = NULL;
	return (l_new);
}
