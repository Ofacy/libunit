# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by alermolo          #+#    #+#              #
#    Updated: 2024/01/27 22:11:46 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	libunit.a
DEBUG		=	no
BONUS		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR			=	framework/includes/
B_INC_DIR		=	framework_bonus/includes/
LIBFT_DIR		=	libft/
HEADERS 		=	framework/includes/libunit.h
HEADERS_BONUS 	= 	framework_bonus/include/libnunit_bonus.h

#--sources & objects-----------------------------------------------------------#

SRC_DIR			=	framework/srcs/
SRC_DIR_BONUS	=	framework_bonus/srcs/
SOURCES_BONUS	=	framework_bonus/srcs/framework_bonus.c \
					framework_bonus/srcs/test_list_clear_bonus.c \
					framework_bonus/srcs/test_result_bonus.c \
					framework_bonus/srcs/param_bonus.c \
					framework_bonus/srcs/stdout_bonus.c \
					
OBJ_DIR		=		.objects
SOURCES 	=		framework/srcs/framework.c	\
					framework/srcs/test_list_clear.c \
					framework/srcs/test_result.c \

#SOURCES_BONUS 	=

#--flags-----------------------------------------------------------------------#

ifeq ($(BONUS), no)
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_DIR)/incs -I $(INC_DIR)
else
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_DIR)/incs -I $(B_INC_DIR)
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

all: $(NAME)

$(NAME): $(OBJECTS)
	cp $(LIBFT) ./$(NAME)
	ar rs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: %.c $(HEADERS) $(LIBFT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#


$(LIBFT) : FORCE
	@$(MAKE) -C $(@D)

FORCE :


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
	norminette $(INC_DIR) $(LIBFT_DIR) $(SRC_DIR) $(B_INC_DIR) $(SRC_DIR_BONUS)

#--PHONY-----------------------------------------------------------------------#

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))

.PHONY: all libs debug bonus re clean fclean norm FORCE
