# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 00:57:05 by eupopa            #+#    #+#              #
#    Updated: 2017/09/20 14:38:39 by eupopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ssl_des

SRC = main.c

SRC_PATH = src/
INCLUDES	= includes/
INCLUDES_PATH	= includes/includes/

OBJ_PATH 		= obj/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_SRC))


SRC_OBJ = $(addprefix $(SRC_L) $(INCLUDES_PATH))

 
OBJ_SRC= $(SRC:.c=.o)


INC = $(addprefix -I,$(INCLUDES_PATH))

CC		=	gcc -g
CFLAGS	+=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -I$(INCLUDES) -o $(NAME)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_PATH) -o $@ -c $< 


clean:
		rm -rf $(OBJ_PATH)
		make -C $(INCLUDES) clean
fclean: clean
		rm -rf $(NAME)
		make -C $(INCLUDES) fclean

re: fclean all
