/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:33:35 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 18:58:07 by lcottet          ###   ########.fr       */
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
	else
		res = MSG_KO_NOCOLOR;
	if (dprintf(total->logfd, "%s: %s: %s\n", funcname, testname, res) == -1)
		return (TESTER_FAILED);
	return (result);
}

int	result(int result, char *funcname, char *testname, t_unit_total *total)
{
	char	*res;

	if (result == TEST_OK)
	{
		res = MSG_OK;
		total->ok++;
	}
	else
		total->ko++;
	if (result == SIGSEGV)
		res = MSG_SEGV;
	else if (result == SIGBUS)
		res = MSG_BUSE;
	else if (result != TEST_OK)
		res = MSG_KO;
	if (ft_printf("%s: %s: %s\n", funcname, testname, res) == -1)
		return (TESTER_FAILED);
	return (result_log(result, funcname, testname, total));
}
