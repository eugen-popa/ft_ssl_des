/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 00:22:19 by eupopa            #+#    #+#             */
/*   Updated: 2017/09/25 15:58:19 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

#include "libft.h"
#include "ft_printf.h"

static const char g_base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const char *g_commands[5] = {"base64", "des", "des-ecd", "des-cbc", NULL};

typedef struct		s_base64
{
	char			*decoded;
	char			*encoded;
	char 			e;
	char 			d;
	char			i;
	char			*input_path;
	char 			o;
	char 			*output_path;
}					t_base64;


void ft_incript	(char *line);
void ft_decript	(char *line);

#endif

