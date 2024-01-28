/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:23 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 16:40:14 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include "expected_signal_bonus.h"

int	expected_signal_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test_param(&test, "OK (expected SIGSEV)", test_ok, \
	param_init(0, NULL, SIGSEGV));
	add_test(&test, "KO", test_ko);
	add_test_param(&test, "Expected Segmentation Fault", test_segfault, \
	param_init(0, NULL, SIGSEGV));
	add_test_param(&test, "Expected Bus Error", test_buserror, \
	param_init(0, NULL, SIGBUS));
	add_test_param(&test, "Expected Bus Error", test_kosegfault, \
	param_init(0, NULL, SIGBUS));
	return (run_tests("EXPECTED_BONUS", test));
}
