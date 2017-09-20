/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:23:21 by eupopa            #+#    #+#             */
/*   Updated: 2017/07/06 21:29:10 by eupopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "get_next_line.h"

typedef struct	s_modif
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			m;
}				t_modif;

typedef struct	s_flag
{
	int			pound;
	int			signplus;
	int			signminus;
	int			sizeend;
	char		cmpltchar;
}				t_flag;

typedef struct	s_pf_data
{
	char		*setting;
	t_flag		flag;
	int			i;
	int			size;
	int			space;
	int			precision;
	t_modif		modif;
	char		specif;
	int			adjusting;
	char		*ox;
	char		*invalidspe;
}				t_pf_data;

typedef struct	s_ret
{
	char		*finalstr;
	int			*posb;
	int			return_val;
}				t_ret;

int				ft_printf(char const *s, ...);
char			*precision_nb(t_pf_data *data, char **a);
char			*select_c(t_pf_data *data, va_list ap, t_ret *retval);
char			*select_s(t_pf_data *data, va_list ap);
char			*select_d(t_pf_data *data, va_list ap);
char			*select_e(t_pf_data *data, va_list ap);
char			*select_n(va_list ap, t_ret *retval);
char			*select_p(t_pf_data *data, va_list ap);
char			*select_u(t_pf_data *data, va_list ap);
char			*select_o(t_pf_data *data, va_list ap);
char			*select_x(t_pf_data *data, va_list ap);
void			reinbow(char **finstr);
void			pf_select(t_pf_data *data, va_list ap, t_ret *retval);
int				pf_initdata(t_pf_data *data, va_list ap);
int				check_specif(char s);
char			*ft_str_cons(t_pf_data *data, char *a);
void			info_size_end(t_pf_data *data);
void			initpreset(t_pf_data *data, va_list ap);
int				start(int nbarg, ...);
void			ft_termcaps_downline(int nbline);
void			ft_termcaps_leftcurs(int nbcol);
void			ft_termcaps_lineclear(void);
void			ft_termcaps_poscurs(int line, int col);
void			ft_termcaps_restorecurs(void);
void			ft_termcaps_rightcurs(int nbcol);
void			ft_termcaps_savecurs(void);
void			ft_termcaps_screenclear(void);
void			ft_termcaps_upline(int nbline);

#endif
