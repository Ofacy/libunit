# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by alermolo          #+#    #+#              #
#    Updated: 2024/01/28 16:16:09 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	libunit.a

ifeq ($(BONUS), yes)
NAME = libunit_bonus.a
endif

DEBUG		=	no
BONUS		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR			=	includes/
B_INC_DIR		=	includes/
LIBFT_DIR		=	../libft/
HEADERS 		=	includes/libunit.h
HEADERS_BONUS 	= 	include/libnunit_bonus.h

#--sources & objects-----------------------------------------------------------#

SRC_DIR			=	srcs/

SOURCES = \
	srcs/framework.c	\
	srcs/test_list_clear.c \
	srcs/test_result.c \

SOURCES_BONUS	= \
	srcs/framework_bonus.c \
	srcs/test_list_clear_bonus.c \
	srcs/test_result_bonus.c \
	srcs/param_bonus.c \
	srcs/stdout_bonus.c \
	srcs/logfile_bonus.c \
	srcs/total_bonus.c \
	srcs/alarm_bonus.c \
	srcs/expected_signal_bonus.c \

OBJ_DIR = .objects

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -I$(LIBFT_DIR)/incs -I $(INC_DIR)

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
DEPS =		$(OBJECTS:%.o=%.d)

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

MAKEFLAGS = --no-print-directory

#--compilation rules-----------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJECTS)
	cp $(LIBFT) ./$(NAME)
	ar rs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: %.c $(LIBFT)
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
	@$(MAKE) BONUS=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -rf $(OBJ_DIR)

fclean:
	$(MAKE) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) libunit_bonus.a

-include $(DEPS)

#--norminette------------------------------------------------------------------#

norm:
	norminette $(INC_DIR) $(LIBFT_DIR) $(SRC_DIR) $(B_INC_DIR) $(SRC_DIR_BONUS)

#--PHONY-----------------------------------------------------------------------#

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))

.PHONY: all libs debug bonus re clean fclean norm FORCE
