/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:32:27 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 13:59:32 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeout_bonus.h"

int	timeout_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	add_test_param(&testlist, "Basic", timeout_basic, param_init(1, NULL, -1));
	add_test_param(&testlist, "OK", timeout_ok, param_init(1, NULL, -1));
	return (run_tests("TIMEOUT", testlist));
}
