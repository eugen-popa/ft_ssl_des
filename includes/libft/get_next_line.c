/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:28:24 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_line(t_line *list, char **line)
{
	char	*temp;
	char	*linecopy;
	int		i;

	temp = NULL;
	i = 0;
	linecopy = list->line;
	while (linecopy[i])
	{
		if (linecopy[i] == '\n')
		{
			*line = ft_strsub(linecopy, 0, i, 0);
			temp = linecopy;
			linecopy = ft_strdup(linecopy + (i + 1));
			free(temp);
			return (linecopy);
		}
		i++;
	}
	*line = ft_strdup(linecopy);
	ft_strclr(linecopy);
	ft_strclr(list->line);
	return (linecopy);
}

static int		read_file(int fd, t_line *list)
{
	char	*temp;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	temp = NULL;
	ret = -2;
	while (!ft_strchr(list->line, '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buf[ret] = '\0';
			temp = list->line;
			if (!(list->line = ft_strjoin(list->line, buf, 0)))
				return (-1);
			free(temp);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

static void		add_element(t_line *list, t_line *newlist)
{
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = newlist;
			newlist->next = NULL;
		}
		list = list->next;
	}
}

static t_line	*list_init(const int fd)
{
	t_line	*newlist;

	if (!(newlist = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	newlist->fd = fd;
	newlist->line = ft_strnew(0);
	newlist->next = NULL;
	return (newlist);
}

int				get_next_line(int const fd, char **line)
{
	static	t_line		*file;
	t_line				*temp;
	int					ret;

	if (!file)
		file = list_init(fd);
	temp = file;
	if (fd < 0 || !line)
		return (-1);
	while (temp)
	{
		if (temp->fd == fd)
			break ;
		if (temp->next == NULL)
			add_element(temp, list_init(fd));
		temp = temp->next;
	}
	if ((ret = read_file(fd, temp)) == -1)
		return (-1);
	temp->line = get_line(temp, line);
	if (!ft_strlen(temp->line) && !ft_strlen(*line) && !ret)
		return (0);
	else
		return (1);
}
