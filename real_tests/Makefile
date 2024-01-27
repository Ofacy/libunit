# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 00:31:16 by ibertran          #+#    #+#              #
#    Updated: 2024/01/27 16:54:14 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = real_tests

# *** FILES ****************************************************************** #

SRCS = \
	main.c \
	$(addprefix $(FT_STRLEN_DIR), $(FT_STRLEN_SRC)) \
	$(addprefix $(ATOI_DIR), $(ATOI_SRC)) \
	$(addprefix $(BZERO_DIR), $(BZERO_SRC)) \

# FT_STRLEN_DIR = split/
# FT_STRLEN_SRC = \
# 			00_launcher.c \

# ATOI_DIR = atoi/
# ATOI_SRC = \
# 			00_launcher.c \

ATOI_DIR = atoi/
ATOI_SRC = \
		00_launcher.c \
		01_basic.c \
		02_maxint.c \
		03_minint.c \
		04_zero.c \
		05_space.c \
		06_space_more.c \
		07_invalid.c \
		08_overflow.c \
		09_underflow.c

BZERO_DIR =
BZERO_DIR = bzero/
BZERO_SRC = \
			00_launcher.c \
			01_basic_test.c \

BUILD_DIR := .build/

OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)

DEPS = $(OBJS:%.o=%.d)

# *** LIBRARIES ************************************************************** #

LIB_NAME	=	ft \
				unit 
LIB_PATH 	=	../framework/libft/libft.a \
				../libunit.a

HEADERS	= tests.h

INCLUDES	=	$(HEADERS_DIR) \
				../framework/includes \
				$(dir $(LIB_PATH)) \
				$(dir $(HEADERS)) \

# *** TRACE ****************************************************************** #

TRACE_DIR = .trace/
STD_TRACE = $(TRACE_DIR)
DEBUG_TRACE = $(TRACE_DIR)debug_

TRACE :=	$(STD_TRACE)

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP
CPPFLAGS 	= 	$(addprefix -I, $(INCLUDES))
LDFLAGS		=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS		=	$(addprefix -l, $(LIB_NAME))

CC_FLAGS = $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

MKDIR 		= 	mkdir -p $(@D)

# MAKEFLAGS	= --no-print-directory

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

.PHONY : test
test : $(NAME)
	-@./$(NAME)

$(NAME) : $(MLX_PATH) $(LIB_PATH) $(OBJS) 
	$(CC) $(CC_FLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

%.a: FORCE 
	@$(MAKE) -C $(@D)
	
$(TRACE)% :
	@$(MKDIR)
	@touch $@

.PHONY : bonus
bonus : $(NAME)

-include $(DEPS)

.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME) $(NAME_BONUS) $(TRACE)
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE)


.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))
	
# *** SPECIAL TARGETS ******************************************************** #

.SILENT : clean fclean re debug %debug norminette

.PHONY : FORCE
FORCE :

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m

# **************************************************************************** #