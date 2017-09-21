# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 19:21:49 by nshuklin          #+#    #+#              #
#    Updated: 2017/09/20 17:09:40 by eupopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC_L = ft_atoi.c \
			ft_bzero.c \
			ft_chartostr.c \
			ft_coltostr.c \
			ft_countchar.c \
			ft_delcharinstr.c \
			ft_ftoa.c \
			ft_gather.c \
			ft_intinarray.c \
			ft_intlen.c \
			ft_intswap.c \
			ft_inttabdup.c \
			ft_inttabjoin.c \
			ft_inttabmax.c \
			ft_inttabmin.c \
			ft_inttabnew.c \
			ft_inttabsorted.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_itoa_base.c \
			ft_lstadd_push_back.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstrev.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_nbchar.c \
			ft_nbword.c \
			ft_nreplace.c \
			ft_nwstrtostr.c \
			ft_putchar_fd.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_putendl.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putnstr_fd.c \
			ft_putnstr.c \
			ft_putstr_fd.c \
			ft_putstr.c \
			ft_putwchar_fd.c \
			ft_putwchar.c \
			ft_pwe.c \
			ft_replace.c \
			ft_show_tab.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_strisdigit.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnrev.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtoupper.c \
			ft_strtrim.c \
			ft_tablen.c \
			ft_tabmalloc.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wchrtostr.c \
			ft_without_space_len.c \
			ft_wstrtostr.c \
			get_next_line.c 

SRC_P = c_s_select.c \
			d_select.c \
			e_select.c \
			ft_data.c \
			ft_data2.c \
			ft_printf.c \
			ft_select.c \
			ft_showtabint.c \
			n_select.c \
			nb_precision.c \
			o_x_select.c \
			p_select.c \
			putmess.c \
			reinbow.c \
			start.c \
			term_caps_1.c \
			term_caps_2.c \
			u_select.c 


INCLUDES_PATH	= includes/
FT_PRINTF_PATH 	= ft_printf/
LIBFT_PATH 		= libft/
OBJ_PATH 		= obj/

SRC_OBJ = $(addprefix $(SRC_L) $(INCLUDES_PATH))

OBJ_SRC_L= $(SRC_L:.c=.o) 
OBJ_SRC_P= $(SRC_P:.c=.o)

OBJ_P = $(addprefix $(OBJ_PATH),$(OBJ_SRC_P))
OBJ_L = $(addprefix $(OBJ_PATH),$(OBJ_SRC_L))

INC = $(addprefix -I,$(INCLUDES_PATH))

CC		=	gcc -g
CFLAGS	+=	-Wall -Wextra -Werror

all: $(NAME)

$(OBJ_PATH)%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(FT_PRINTF_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ_P) $(OBJ_L)
	@ar -rc $(NAME) $?
	@ranlib $(NAME)

clean:
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -rf $(NAME)

re: fclean all
