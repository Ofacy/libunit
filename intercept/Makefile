# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by alermolo          #+#    #+#              #
#    Updated: 2024/01/31 01:25:06 by lcottet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	intercept.so

DEBUG		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR			=	includes/
LIBFT_DIR		=	../libft/
HEADERS 		=	includes/intercept.h 

#--sources & objects-----------------------------------------------------------#

SRC_DIR			=	srcs/

SOURCES = \
	srcs/open.c \
	srcs/config.c \
	srcs/malloc.c \
	srcs/close.c \
	srcs/free.c \
	srcs/read.c \
	srcs/write.c \
	srcs/dup2.c \
	srcs/fork.c \
	srcs/wait.c \
	srcs/pipe.c \
	srcs/intercept.c \
	srcs/leakcheck.c \
	srcs/failtree.c \
	srcs/ld_preload.c \

OBJ_DIR = .objects

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -I$(LIBFT_DIR)/incs -I $(INC_DIR)

DFLAGS		=	-g3

#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
DEPS =		$(OBJECTS:%.o=%.d)

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

MAKEFLAGS = --no-print-directory

#--compilation rules-----------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJECTS)
	cp $(LIBFT) ./$(NAME)
	cc $(CFLAGS) -shared -o $(NAME) $(OBJECTS) ${LIBFT}

$(OBJ_DIR)/%.o: %.c $(LIBFT)
	@mkdir -p $(dir $@)
	$(CC) -fPIC $(CFLAGS) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#


$(LIBFT) : FORCE
	@$(MAKE) -C $(@D)

FORCE :


libs:
	$(MAKE) -C $(LIBFT_DIR)

debug:
	$(MAKE) re DEBUG=yes

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
