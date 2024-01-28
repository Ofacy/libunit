/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:29:13 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 10:29:03 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"
#include "libunit.h"

int	add_test(t_test **test, char *name, int (*testm)(void))
{
	t_test	*new;
	t_test	*tmp;

	if (!test || !name || !testm)
		return (0);
	new = malloc(sizeof(t_test));
	if (!new)
		return (0);
	new->name = name;
	new->test = testm;
	new->next = NULL;
	if (!*test)
		*test = new;
	else
	{
		tmp = *test;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int	run_test(t_test *test, t_test *head)
{
	pid_t	pid;
	int		(*tmp)(void);
	int		status;

	pid = fork();
	if (pid == -1)
		return (TESTER_FAILED);
	if (!pid)
	{
		tmp = test->test;
		test_list_clear(&head);
		exit(tmp());
	}
	wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (TESTER_FAILED);
}

int	run_tests(char *funcname, t_test *test)
{
	t_unit_total	total;
	t_test			*tmp;

	total.ok = 0;
	total.ko = 0;
	tmp = test;
	while (tmp)
	{
		if (result(run_test(tmp, test), funcname, tmp->name, &total)
			== TESTER_FAILED)
			return (TESTER_FAILED);
		tmp = tmp->next;
	}
	test_list_clear(&test);
	if (total.ko == 0)
	{
		ft_printf("\n\033[32m%d/%d tests passed!\033[0m\n\n", \
			total.ok, total.ok + total.ko);
		return (0);
	}
	ft_printf("\n\033[33m%d/%d tests passed!\033[0m\n\n", \
		total.ok, total.ok + total.ko);
	return (-1);
}
