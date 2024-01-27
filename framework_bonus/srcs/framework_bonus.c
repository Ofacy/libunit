/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:29:13 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 23:07:01 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "libft.h"
#include "libunit_bonus.h"

int	add_test(t_test **test, char *name, int (*testm)(void))
{
	return (add_test_param(test, name, testm, param_init(0, NULL)));
}

int	add_test_param(t_test **test, char *name, int (*testm)(void), t_param param)
{
	t_test	*new;
	t_test	*tmp;

	new = malloc(sizeof(t_test));
	if (!new)
		return (0);
	new->name = name;
	new->test = testm;
	new->next = NULL;
	new->param = param;
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

void	fork_normal_test(t_test *test, t_test *head, t_unit_total total)
{
	int	(*tmp)(void);

	tmp = test->test;
	test_list_clear(&head);
	close(total.logfd);
	exit(tmp());
}

int	run_test(t_test *test, t_test *head, t_unit_total total)
{
	pid_t	pid;
	int		status;
	int		ret;

	ret = TEST_OK;
	if (!test->param.stdout)
	{
		pid = fork();
		if (!pid)
			fork_normal_test(test, head, total);
		if (pid == -1)
			return (TESTER_FAILED);
	}
	else
		ret = run_test_stdout(test, head, total);
	wait(&status);
	if (WIFEXITED(status) && ret == TEST_OK)
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (ret);
}

int	run_tests(char *funcname, t_test *test)
{
	t_unit_total	total;
	t_test			*tmp;

	total = init_total();
	tmp = test;
	total.logfd = open_logfile(&total, funcname);
	if (total.logfd == -1)
		return (test_list_clear(&test), TESTER_FAILED);
	while (tmp)
	{
		if (result(run_test(tmp, test, total), funcname, tmp->name, &total)
			== TESTER_FAILED)
			return (test_list_clear(&test), TESTER_FAILED);
		tmp = tmp->next;
	}
	test_list_clear(&test);
	if (close(total.logfd) == -1)
		return (TESTER_FAILED);
	if (total.ko == 0)
	{
		ft_printf("\n\033[32mAll tests passed!\033[0m\n\n");
		return (0);
	}
	return (ft_printf("\n\033[33m%d/%d tests passed!\033[0m\n\n", \
	total.ok, total.ok + total.ko), -1);
}
