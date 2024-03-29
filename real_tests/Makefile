# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 00:31:16 by ibertran          #+#    #+#              #
#    Updated: 2024/01/28 16:19:21 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = real_tests

# *** FILES ****************************************************************** #

SRCS = \
	main.c \
	$(addprefix $(ATOI_DIR), $(ATOI_SRC)) \
	$(addprefix $(BZERO_DIR), $(BZERO_SRC)) \
	$(addprefix $(SPLIT_DIR), $(SPLIT_SRC)) \
	$(addprefix $(LSTNEW_DIR), $(LSTNEW_SRC)) \

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
	
LSTNEW_DIR = lstnew/
LSTNEW_SRC = \
		00_launcher.c \
		01_char_pointer.c \
		02_int_pointer.c \
		03_void_pointer.c \
		04_null_content.c \

BZERO_DIR = bzero/
BZERO_SRC = \
		00_launcher.c \
		01_basic_test.c \
		02_size_zero.c \
		03_null.c \
		04_negative_size.c \

SPLIT_DIR = split/
SPLIT_SRC = \
		00_launcher.c \
		01_basic_test.c \
		02_mult_sep.c	\
		03_sep_start.c	\
		04_sep_end.c	\
		05_mult_start_end.c	\
		06_no_sep.c		\
		07_empty_string.c	\

BUILD_DIR := .build/$(MODULE_DIR)

OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)

DEPS = $(OBJS:%.o=%.d)

# *** LIBRARIES ************************************************************** #

LIB_NAME	=	ft \
				unit
LIB_PATH 	=	../libft/libft.a \
				../framework/libunit.a

HEADERS	= tests.h

INCLUDES	=	$(HEADERS_DIR) \
				../framework/includes \
				$(dir $(LIB_PATH)) \
				../libft/incs \
				$(dir $(HEADERS)) \

# *** TRACE ****************************************************************** #

TRACE_DIR = .trace/
ALL_TRACE = $(TRACE_DIR)all_
ATOI_TRACE = $(TRACE_DIR)atoi_
BZERO_TRACE = $(TRACE_DIR)bzero_
SPLIT_TRACE = $(TRACE_DIR)split_
LSTNEW_TRACE = $(TRACE_DIR)lstnew_

ifeq ($(MODE), ATOI)
TRACE =	$(ATOI_TRACE)
else ifeq ($(MODE), BZERO)
TRACE =	$(BZERO_TRACE)
else ifeq ($(MODE), SPLIT)
TRACE =	$(SPLIT_TRACE)
else ifeq ($(MODE), LSTNEW)
TRACE =	$(LSTNEW_TRACE)
else
TRACE = $(ALL_TRACE)
endif

MODULE = \
	ATOI \
	BZERO \
	SPLIT \
	LSTNEW \

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
	-@./$(NAME) ; echo -n

$(NAME) : $(LIB_PATH) $(OBJS) $(addsuffix $(NAME), $(TRACE))
	$(CC) $(CC_FLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
ifdef MODE
	$(RM) $(ALL_TRACE)$(NAME)
endif
ifneq ($(MODE), ATOI)
	@$(RM) $(ATOI_TRACE)$(NAME)
endif
ifneq ($(MODE), BZERO)
	@$(RM) $(BZERO_TRACE)$(NAME)
endif
ifneq ($(MODE), SPLIT)
	@$(RM) $(SPLIT_TRACE)$(NAME)
endif
ifneq ($(MODE), LSTNEW)
	@$(RM) $(LSTNEW_TRACE)$(NAME)
endif
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(DEFINE_MODE) $(CPPFLAGS) -c $< -o $@

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
	$(RM) $(NAME) $(NAME_BONUS) $(TRACE)
	$(MAKE) $@ -C $(dir ../libft/libft.a)
	$(MAKE) $@ -C $(dir ../framework/libunit.a)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	rm -rf $(BUILD_DIR) $(TRACE_DIR)
	$(RM) $(NAME) $(NAME_BONUS) 
	$(MAKE) $@ -C $(dir ../libft/libft.a)
	$(MAKE) $@ -C $(dir ../framework/libunit.a)
	echo "$(YELLOW) $(NAME) all files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : $(MODULE)
$(MODULE) :
	@$(MAKE) test MODE=$@ DEFINE_MODE="-D TEST_ALL=0 -D TEST_$@=1" MODULE_DIR="$@/"

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
