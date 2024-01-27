# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2024/01/27 18:37:15 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** FILES  ***************************************************************** #

include libft_srcs.mk

BUILD_DIR := .build/

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)

DEPS = $(OBJS:%.o=%.d)

HEADERS = incs/

# *** TRACE ****************************************************************** #

TRACE_DIR = .trace/

STD_TRACE = $(TRACE_DIR)

TRACE =	$(STD_TRACE)

# *** COMPILER *************************************************************** #

CFLAGS = -Wall -Wextra -Werror -MMD -MP

CPPFLAGS = $(addprefix -I, $(HEADERS))

# *** CONFIG ***************************************************************** #

AR = ar rc

MKDIR = mkdir -p $(@D)

MAKEFLAGS = --no-print-directory

# *** DEBUG ****************************************************************** #

ifeq ($(DEBUG),1)
BUILD_DIR := $(BUILD_DIR)debug/

CFLAGS := $(filter-out -O3,$(CFLAGS)) -g3

TRACE = $(DEBUG_TRACE)
endif

DEBUG_TRACE = $(TRACE_DIR)debug_

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS) $(addsuffix $(NAME), $(TRACE))
	$(AR) $(NAME) $(OBJS)
ifeq ($(DEBUG),1)
	@$(RM) $(STD_TRACE)$@
	@echo "$(BLUE) $(NAME)(DEBUG) has been built! $(RESET)"
else
	@$(RM) $(DEBUG_TRACE)$@
	@echo "$(BLUE) $(NAME) has been built! $(RESET)"
endif

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TRACE)% :
	@$(MKDIR)
	@touch $@

-include $(DEPS)

.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(TRACE_DIR)
	$(RM) norminette.log
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	$(RM) $(NAME)
	rm -rf $(BUILD_DIR)
	rm -rf $(TRACE_DIR)
	$(RM) norminette.log
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE) all

.PHONY : debug
debug :
	$(MAKE) DEBUG=1

.PHONY : %debug
%debug :
	$(MAKE) $(patsubst %debug,%,$@) DEBUG=1

.PHONY : norminette
norminette :
	norminette $(HEADERS) $(SRCS_DIR) > norminette.log; echo -n
	if [ $$(< norminette.log grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < norminette.log grep Error; fi

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))

test :
	make debug
	cc -g3 -Iincs/ vector_test_main.c libft.a
	valgrind ./a.out

# *** SPECIAL TARGETS ******************************************************** #

.SILENT : clean fclean re debug %debug norminette

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m