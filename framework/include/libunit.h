/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:17:00 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 13:44:25 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stddef.h>
# include <signal.h>

# define TESTER_FAILED -2
# define TEST_KO -1
# define TEST_OK 0

typedef struct s_test
{
	char			*name;
	int				(*test)(void);
	struct s_test	*next;
}	t_test;

typedef struct s_unit_total
{
	int		ok;
	int		ko;
}	t_unit_total;

int		add_test(t_test **test, char *name, int (*testm)(void));
int		run_tests(char *funcname, t_test *test);

void	test_list_clear(t_test **test);

int	result(int result, char *funcname, char *testname, t_unit_total *total);

#endif
