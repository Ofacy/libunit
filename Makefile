# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by alermolo          #+#    #+#              #
#    Updated: 2024/01/27 10:43:33 by alermolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	libunit.a
DEBUG		=	no
BONUS		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR			=	includes/
B_INC_DIR		=	bonus/includes_bonus/
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
	$(CC) $^ $(CFLAGS) $(LIBFT) -o $@

ifeq ($(BONUS), no)
$(OBJ_DIR)/%.o: %.c $(HEADERS) $(LIBFT)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
else
$(OBJ_DIR)/%.o: %.c $(HEADERS_BONUS) $(LIBFT)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
endif


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
