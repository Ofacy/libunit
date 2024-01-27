/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:15:53 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 19:55:18 by lcottet          ###   ########.fr       */
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

int	is_stdout_equal(t_test *test, int *existatus, pid_t pid, int fd)
{
	char	*line;
	int		stdoutchar;
	int		ret;
	int		gnlstatus;
	size_t	i;

	ret = 1;
	stdoutchar = TEST_OK;
	gnlstatus = get_next_line(fd, &line);
	while (gnlstatus == 0 && line && waitpid(pid, existatus, WNOHANG) == 0)
	{
		i = 0;
		while (ret == TEST_OK && line[i])
		{
			if (line[i] != test->param.stdout[stdoutchar])
				ret = TEST_KO;
			stdoutchar++;
			i++;
		}
		free(line);
		gnlstatus = get_next_line(fd, &line);
	}
	if (gnlstatus == -1)
		ret = TESTER_FAILED;
	return (ret);
}

int	run_test_stdout(t_test *test, int *exitstatus, t_test *head)
{
	int		fd[2];
	pid_t	pid;
	int		(*tmp)(void);

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (!pid)
	{
		tmp = test->test;
		test_list_clear(&head);
		if (close(fd[0]))
			exit(TESTER_FAILED);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			exit(TESTER_FAILED);
		if (close(fd[1]))
			exit(TESTER_FAILED);
		exit(tmp());
	}
	close(fd[1]);
	return (is_stdout_equal(test, exitstatus, pid, fd[0]));
}
