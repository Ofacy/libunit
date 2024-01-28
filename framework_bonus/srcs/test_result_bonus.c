/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:33:35 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 14:07:52 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libunit_bonus.h"
#include "libft.h"

int	result_log(int result, char *funcname, char *testname, t_unit_total *total)
{
	char	*res;

	if (result == TEST_OK)
		res = MSG_OK_NOCOLOR;
	else if (result == SIGSEGV)
		res = MSG_SEGV_NOCOLOR;
	else if (result == SIGBUS)
		res = MSG_BUSE_NOCOLOR;
	else if (result == SIGABRT)
		res = MSG_SIGABRT_NOCOLOR;
	else if (result == SIGFPE)
		res = MSG_SIGFPE_NOCOLOR;
	else if (result == SIGPIPE)
		res = MSG_SIGPIPE_NOCOLOR;
	else if (result == SIGILL)
		res = MSG_SIGILL_NOCOLOR;
	else if (result == TEST_TIMEOUT)
		res = MSG_TIMEOUT_NOCOLOR;
	else
		res = MSG_KO_NOCOLOR;
	if (dprintf(total->logfd, "%s: %s: %s\n", funcname, testname, res) == -1)
		return (TESTER_FAILED);
	return (result);
}

int	increment_total(int *result, char *func, t_test *test, t_unit_total *total)
{
	if (test->param.expectedsignal != -1)
	{
		if (*result == test->param.expectedsignal)
		{
			total->ok++;
			expected_signal(*result, func, test);
			return (1);
		}
		else
		{
			total->ko++;
			*result = TEST_KO;
			return (0);
		}
	}
	if (*result == TEST_OK)
		total->ok++;
	else
		total->ko++;
	return (0);
}

int	result(int result, char *funcname, t_test *test, t_unit_total *total)
{
	char	*res;

	res = MSG_KO;
	if (increment_total(&result, funcname, test, total))
		return (result_log(result, funcname, test->name, total));
	if (result == SIGSEGV)
		res = MSG_SEGV;
	else if (result == SIGBUS)
		res = MSG_BUSE;
	else if (result == SIGABRT)
		res = MSG_SIGABRT;
	else if (result == SIGFPE)
		res = MSG_SIGFPE;
	else if (result == SIGPIPE)
		res = MSG_SIGPIPE;
	else if (result == SIGILL)
		res = MSG_SIGILL;
	else if (result == TEST_TIMEOUT)
		res = MSG_TIMEOUT;
	else if (result == TEST_OK)
		res = MSG_OK;
	if (ft_printf("%s: %s: %s\n", funcname, test->name, res) == -1)
		return (TESTER_FAILED);
	return (result_log(result, funcname, test->name, total));
}
