/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:33:35 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 22:11:21 by ibertran         ###   ########lyon.fr   */
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
	else
		res = MSG_KO_NOCOLOR;
	if (dprintf(total->logfd, "%s: %s: %s\n", funcname, testname, res) == -1)
		return (TESTER_FAILED);
	return (result);
}

int	result(int result, char *funcname, char *testname, t_unit_total *total)
{
	char	*res;

	res = MSG_OK;
	if (result == TEST_OK)
		total->ok++;
	else
		total->ko++;
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
	else
		res = MSG_KO;
	if (ft_printf("%s: %s: %s\n", funcname, testname, res) == -1)
		return (TESTER_FAILED);
	return (result_log(result, funcname, testname, total));
}
