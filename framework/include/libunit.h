/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:17:00 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 11:52:42 by ibertran         ###   ########lyon.fr   */
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

int	add_test(t_test **test, char *name, int (*testm)(void));
int	run_tests(t_test *test);

#endif
