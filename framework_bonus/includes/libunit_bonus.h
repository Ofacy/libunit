/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:17:00 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 20:42:19 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

# include <stddef.h>
# include <signal.h>

# define TESTER_FAILED -2
# define TEST_KO -1
# define TEST_OK 0

# define MSG_OK "\033[32m[OK]\033[0m"
# define MSG_KO "\033[31m[KO]\033[0m"
# define MSG_SEGV "\033[33m[SEGV]\033[0m"
# define MSG_BUSE "\033[33m[BUSE]\033[0m"
# define MSG_SIGABRT "\033[33m[SIGABRT]\033[0m"
# define MSG_SIGFPE "\033[33m[SIGFPE]\033[0m"
# define MSG_SIGPIPE "\033[33m[SIGPIPE]\033[0m"
# define MSG_SIGILL "\033[33m[SIGILL]\033[0m"

# define MSG_OK_NOCOLOR "[OK]"
# define MSG_KO_NOCOLOR "[KO]"
# define MSG_SEGV_NOCOLOR "[SEGV]"
# define MSG_BUSE_NOCOLOR "[BUSE]"

typedef struct s_param
{
	unsigned int	timeout;
	char			*stdout;
}	t_param;

typedef struct s_test
{
	char			*name;
	int				(*test)(void);
	struct s_test	*next;
	t_param			param;
}	t_test;

typedef struct s_unit_total
{
	int	ok;
	int	ko;
	int	logfd;
}	t_unit_total;

t_param	param_init(unsigned int timeout, char *stdout);
int		add_test(t_test **test, char *name, int (*testm)(void));
int		add_test_param(t_test **test, char *name, int (*testm)(void), \
t_param param);
int		run_tests(char *funcname, t_test *test);

void	test_list_clear(t_test **test);

int		run_test_stdout(t_test *test, t_test *head, t_unit_total total);
int		result(int result, char *funcname, char *testname, t_unit_total *total);

#endif
