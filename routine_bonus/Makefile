# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 00:31:16 by ibertran          #+#    #+#              #
#    Updated: 2024/01/28 12:48:41 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = real_tests

# *** FILES ****************************************************************** #

SRCS = \
	main_bonus.c \
	$(addprefix $(STDOUT_DIR), $(STDOUT_SRC)) \
	$(addprefix $(SIGNAL_DIR), $(SIGNAL_SRC))

SIGNAL_DIR = signals_bonus/
SIGNAL_SRC = \
		00_launcher.c \
		01_test_sigabrt.c \
		02_test_sigfpe.c \
		03_test_sigpipe.c \
		04_test_sigill.c \

STDOUT_DIR = stdout_bonus/
STDOUT_SRC = \
		00_launcher.c \
		01_basic.c \
		02_invalidlength.c \
		03_invalidlength2.c \
		04_empty.c

BUILD_DIR := .build/

OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)

DEPS = $(OBJS:%.o=%.d)

# *** LIBRARIES ************************************************************** #

LIB_NAME	=	ft \
				unit_bonus \
				m
LIB_PATH 	=	../libft/libft.a \
				../libunit_bonus.a

HEADERS	= tests.h

INCLUDES	=	$(HEADERS_DIR) \
				../framework_bonus/includes \
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

MAKEFLAGS	= --no-print-directory

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

.PHONY : test
test : $(NAME)
	-@./$(NAME)

$(NAME) : $(LIB_PATH) $(OBJS) 
	$(CC) $(CC_FLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

../libunit.a : FORCE
	@$(MAKE) -C $(@D) bonus

../libft/libft.a: FORCE 
	@$(MAKE) -C $(@D)
	
$(TRACE)% :
	@$(MKDIR)
	@touch $@

.PHONY : bonus
bonus : $(NAME)

-include $(DEPS)

.PHONY : clean
clean :
	@$(MAKE) $@ -C $(dir ../libft/libft.a)
	@$(MAKE) $@ -C $(dir ../libunit_bonus.a)
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	@$(MAKE) $@ -C $(dir ../libft/libft.a)
	@$(MAKE) $@ -C $(dir ../libunit_bonus.a)
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME) $(NAME_BONUS) $(TRACE_DIR)
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