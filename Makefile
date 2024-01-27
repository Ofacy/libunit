# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by alermolo          #+#    #+#              #
#    Updated: 2024/01/27 13:25:12 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	libunit.a
DEBUG		=	no
BONUS		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR			=	framework/include/
B_INC_DIR		=	framework_bonus/include/
LIBFT_DIR		=	framework/libft/
HEADERS 		=	framework/include/libunit.h
HEADERS_BONUS 	= 	framework_bonus/include/libnunit_bonus.h

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=		framework/src/
B_SRC_DIR	=		framework_bonus/src/
OBJ_DIR		=		.objects
SOURCES 	=		framework/src/framework.c	\

#SOURCES_BONUS 	=

#--flags-----------------------------------------------------------------------#

ifeq ($(BONUS), no)
CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(INC_DIR)
else
CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(B_INC_DIR)
endif

DFLAGS		=	-g3 -fsanitize=address

#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a

#--objects---------------------------------------------------------------------#

ifeq ($(BONUS), no)
OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
else
OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES_BONUS:.c=.o))
endif

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) libs
	$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

ifeq ($(BONUS), no)
$(OBJ_DIR)/%.o: %.c $(HEADERS) $(LIBFT)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
else
$(OBJ_DIR)/%.o: %.c $(HEADERS_BONUS) $(LIBFT)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
endif

test:
	$(CC) -Iframework/include -Lframework/libft -L./ tests/main.c tests/ft_strlen/00_launcher.c tests/ft_strlen/01_basic_test.c -lunit -lft
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./a.out

#--libs, debugs & bonus--------------------------------------------------------#

libs:
	$(MAKE) -C $(LIBFT_DIR)

debug:
	$(MAKE) re DEBUG=yes

bonus:
	$(MAKE) BONUS=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -rf $(OBJECTS)

fclean:
	$(MAKE) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

#--norminette------------------------------------------------------------------#

norm:
	norminette $(INC_DIR) $(LIBFT_DIR) $(SRC_DIR) $(B_INC_DIR) $(B_SRC_DIR)

#--PHONY-----------------------------------------------------------------------#

.PHONY: all libs debug bonus re clean fclean norm
