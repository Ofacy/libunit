/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:15:53 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 12:31:41 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "libunit_bonus.h"
#include "libft.h"

int	is_chunk_equal(char *chunk, char *stdout, size_t *stdoutchar, size_t len)
{
	size_t	i;

	i = 0;
	while (chunk[i])
	{
		if (*stdoutchar > len || !stdout[*stdoutchar] || \
			chunk[i] != stdout[*stdoutchar])
			return (TEST_KO);
		(*stdoutchar)++;
		i++;
	}
	return (TEST_OK);
}

int	is_stdout_equal(t_test *test, int fd)
{
	char	*line;
	size_t	charcnt;
	int		ret;
	int		gnlstatus;
	size_t	stdoutlen;

	ret = TEST_OK;
	charcnt = 0;
	gnlstatus = get_next_line(fd, &line);
	stdoutlen = ft_strlen(test->param.stdout);
	while (line)
	{
		if (ret == TEST_OK && \
			is_chunk_equal(line, test->param.stdout, &charcnt, stdoutlen) \
				!= TEST_OK)
			ret = TEST_KO;
		free(line);
		gnlstatus = get_next_line(fd, &line);
	}
	if (close(fd) == -1 || gnlstatus == -1)
		ret = TESTER_FAILED;
	if (charcnt != stdoutlen)
		ret = TEST_KO;
	return (ret);
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
