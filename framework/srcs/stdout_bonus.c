/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:15:53 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 16:46:11 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "libft.h"
#include "libunit_bonus.h"

#define STDOUT_BUFFER_LEN 100

int	is_chunk_equal(t_stdout_checker *checker, char *stdout)
{
	int	i;

	i = 0;
	while (i < checker->chunklen)
	{
		if (checker->stdoutpos > checker->stdoutlen || \
			!stdout[checker->stdoutpos] || \
			checker->chunk[i] != stdout[checker->stdoutpos])
			return (TEST_KO);
		(checker->stdoutpos)++;
		i++;
	}
	return (TEST_OK);
}

int	is_stdout_equal(t_test *test, int fd)
{
	t_stdout_checker	checker;
	char				chunk[STDOUT_BUFFER_LEN];

	checker.result = TEST_OK;
	checker.stdoutlen = ft_strlen(test->param.stdout);
	checker.stdoutpos = 0;
	checker.chunklen = read(fd, chunk, STDOUT_BUFFER_LEN);
	while (checker.chunklen > 0)
	{
		checker.chunk = chunk;
		if (checker.result == TEST_OK && \
			is_chunk_equal(&checker, test->param.stdout) != TEST_OK)
			checker.result = TEST_KO;
		checker.chunklen = read(fd, chunk, STDOUT_BUFFER_LEN);
	}
	if (checker.chunklen == -1)
		checker.result = TEST_KO;
	if (checker.stdoutpos != checker.stdoutlen)
		checker.result = TEST_KO;
	return (checker.result);
}

int	run_stdout_test(int fd[2], t_test *test, t_test *head, t_unit_total total)
{
	int	(*tmp)(void);
	int	ret;

	tmp = test->test;
	test_list_clear(&head);
	if (close(total.logfd))
		exit(TESTER_FAILED);
	if (close(fd[0]))
		exit(TESTER_FAILED);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit(TESTER_FAILED);
	if (close(fd[1]))
		exit(TESTER_FAILED);
	ret = tmp();
	close(STDOUT_FILENO);
	exit(ret);
}

int	run_test_stdout(t_test *test, t_test *head, t_unit_total total)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (!pid)
	{
		setup_alarm(test);
		run_stdout_test(fd, test, head, total);
	}
	if (close(fd[1]) == -1)
		return (is_stdout_equal(test, fd[0]), TESTER_FAILED);
	return (is_stdout_equal(test, fd[0]));
}
