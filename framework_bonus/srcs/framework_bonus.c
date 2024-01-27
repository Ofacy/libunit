/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:29:13 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 20:21:09 by ibertran         ###   ########lyon.fr   */
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

int	run_test(t_test *test, t_test *head)
{
	pid_t	pid;
	int		(*tmp)(void);
	int		status;
	int		ret;

	ret = TEST_OK;
	if (!test->param.stdout)
	{
		pid = fork();
		if (!pid)
		{
			tmp = test->test;
			test_list_clear(&head);
			exit(tmp());
		}
		if (pid == -1)
			return (TESTER_FAILED);
	}
	else
		ret = run_test_stdout(test, head);
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
	char			*logfile;

	total.ok = 0;
	total.ko = 0;
	tmp = test;
	logfile = ft_strjoin(funcname, ".log");
	if (!logfile)
		return (TESTER_FAILED);
	total.logfd = open(logfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(logfile);
	if (total.logfd == -1)
		return (TESTER_FAILED);
	while (tmp)
	{
		if (result(run_test(tmp, test), funcname, tmp->name, &total)
			== TESTER_FAILED)
			return (TESTER_FAILED);
		tmp = tmp->next;
	}
	test_list_clear(&test);
	if (total.ko == 0)
		return (0);
	return (-1);
}
