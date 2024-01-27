/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:33:35 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 13:52:34 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	result(int result, char *funcname, char *testname, t_unit_total *total)
{
	char	*res;

	if (result == TEST_OK)
	{
		res = "\033[32m[OK]\033[0m\n";
		total->ok++;
	}
	else
		total->ko++;
	if (result == SIGSEGV)
		res = "\033[33m[SEGV]\033[0m\n";
	else if (result == SIGBUS)
		res = "\033[33m[BUSE]\033[0m\n";
	else if (result != TEST_OK)
		res = "\033[31m[KO]\033[0m\n";
	if (ft_printf("%s: %s: %s", funcname, testname, res) == -1)
		return (TESTER_FAILED);
	return (result);
}
