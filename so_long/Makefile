# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 22:56:26 by ppeapod           #+#    #+#              #
#    Updated: 2021/12/29 22:56:29 by ppeapod          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./include/
SRCS_DIR	= ./src/

INCS_BONUS_DIR	= ./include/
SRCS_BONUS_DIR	= ./src/

INCS		= -I include
MLX_FLAGS	= -lmlx -framework OpenGL -framework Appkit

SRC		=	main.c init.c read_map.c render.c errors.c get_next_line_utils.c get_next_line.c render_dop.c

SRC_BONUS	=	main.c init.c read_map.c render.c errors.c get_next_line_utils.c get_next_line.c render_dop.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)

SRCS_BONUS	=	$(addprefix $(SRCS_BONUS_DIR), $(SRC_BONUS))
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)


.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR) -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : clean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) -I $(INCS_BONUS_DIR) -lmlx -fsanitize=address -framework OpenGL -framework Appkit

PHONY	: all clean fclean re bonus
