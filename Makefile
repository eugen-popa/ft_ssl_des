# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 00:57:05 by eupopa            #+#    #+#              #
#    Updated: 2017/09/20 13:19:15 by eupopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ssl_des

SRC = main.c

SRC_PATH = src/
INCLUDES_PATH	= includes/
OBJ_PATH 		= obj/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_SRC))


SRC_OBJ = $(addprefix $(SRC_L) $(INCLUDES_PATH))

 
OBJ_SRC= $(SRC:.c=.o)


INC = $(addprefix -I,$(INCLUDES_PATH))

CC		=	gcc -g
CFLAGS	+=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(INCLUDES_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)

clean:
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -rf $(NAME)

re: fclean all
