/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_signal_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:45:51 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 13:54:59 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit_bonus.h"

int	expected_signal(int result, char *func, t_test *test)
{
	char	*res;

	res = MSG_KO;
	if (result == SIGSEGV)
		res = MSG_OKSEGV;
	else if (result == SIGBUS)
		res = MSG_OKBUSE;
	else if (result == SIGABRT)
		res = MSG_OKSIGABRT;
	else if (result == SIGFPE)
		res = MSG_OKSIGFPE;
	else if (result == SIGPIPE)
		res = MSG_OKSIGPIPE;
	else if (result == SIGILL)
		res = MSG_OKSIGILL;
	else if (result == TEST_TIMEOUT)
		res = MSG_OKTIMEOUT;
	if (ft_printf("%s: %s: %s\n", func, test->name, res) == -1)
		return (TESTER_FAILED);
	return (result);
}
