/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:46:20 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/07 17:12:23 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reinbow2(char **finstr)
{
	*finstr = ft_replace("{lblack}", "\033[90m", *finstr, 1);
	*finstr = ft_replace("{lred}", "\033[91m", *finstr, 1);
	*finstr = ft_replace("{lgreen}", "\033[92m", *finstr, 1);
	*finstr = ft_replace("{lyellow}", "\033[93m", *finstr, 1);
	*finstr = ft_replace("{lblue}", "\033[94m", *finstr, 1);
	*finstr = ft_replace("{lpink}", "\033[95m", *finstr, 1);
	*finstr = ft_replace("{lcyan}", "\033[96m", *finstr, 1);
	*finstr = ft_replace("{lwhite}", "\033[97m", *finstr, 1);
	*finstr = ft_replace("{bglblack}", "\033[100m", *finstr, 1);
	*finstr = ft_replace("{bglred}", "\033[101m", *finstr, 1);
	*finstr = ft_replace("{bglgreen}", "\033[102m", *finstr, 1);
	*finstr = ft_replace("{bglyellow}", "\033[103m", *finstr, 1);
	*finstr = ft_replace("{bglblue}", "\033[104m", *finstr, 1);
	*finstr = ft_replace("{bglpink}", "\033[105m", *finstr, 1);
	*finstr = ft_replace("{bglcyan}", "\033[106m", *finstr, 1);
	*finstr = ft_replace("{bglwhite}", "\033[107m", *finstr, 1);
}

void		reinbow(char **finstr)
{
	*finstr = ft_replace("{eoc}", "\033[0m", *finstr, 1);
	*finstr = ft_replace("{black}", "\033[30m", *finstr, 1);
	*finstr = ft_replace("{red}", "\033[31m", *finstr, 1);
	*finstr = ft_replace("{green}", "\033[32m", *finstr, 1);
	*finstr = ft_replace("{yellow}", "\033[33m", *finstr, 1);
	*finstr = ft_replace("{blue}", "\033[34m", *finstr, 1);
	*finstr = ft_replace("{pink}", "\033[35m", *finstr, 1);
	*finstr = ft_replace("{cyan}", "\033[36m", *finstr, 1);
	*finstr = ft_replace("{white}", "\033[37m", *finstr, 1);
	*finstr = ft_replace("{bgblack}", "\033[40m", *finstr, 1);
	*finstr = ft_replace("{bgred}", "\033[41m", *finstr, 1);
	*finstr = ft_replace("{bggreen}", "\033[42m", *finstr, 1);
	*finstr = ft_replace("{bgyellow}", "\033[43m", *finstr, 1);
	*finstr = ft_replace("{bgblue}", "\033[44m", *finstr, 1);
	*finstr = ft_replace("{bgpink}", "\033[45m", *finstr, 1);
	*finstr = ft_replace("{bgcyan}", "\033[46m", *finstr, 1);
	*finstr = ft_replace("{bgwhite}", "\033[47m", *finstr, 1);
	reinbow2(finstr);
}
