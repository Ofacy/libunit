/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:33:35 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 15:34:33 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

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
	return (result);
}
