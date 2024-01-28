/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarm_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:29:04 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 12:46:48 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>	
#include "libunit_bonus.h"

static void	alarm_handler(int sig)
{
	(void)sig;
	exit(TEST_TIMEOUT);
}

int	setup_alarm(t_test *test)
{
	signal(SIGALRM, alarm_handler);
	if (test->param.timeout > 0)
		alarm(test->param.timeout);
	return (0);
}
