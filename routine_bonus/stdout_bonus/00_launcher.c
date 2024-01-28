/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:35:07 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 16:50:44 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdout_bonus.h"

int	stdout_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	add_test_param(&testlist, "Basic", stdout_basic_test, \
	param_init(0, "OK", -1));
	add_test_param(&testlist, "Invalid length", \
	stdout_invalid_length_test, param_init(0, "OK", -1));
	add_test_param(&testlist, "Invalid length 2", \
	stdout_invalid_length2_test, param_init(0, "OK", -1));
	add_test_param(&testlist, "Empty KO", stdout_empty_test, \
	param_init(0, "OK", -1));
	add_test_param(&testlist, "Empty OK", stdout_empty_test, \
	param_init(0, "", -1));
	add_test_param(&testlist, "Uninitialized", stdout_uninitialized_test, \
	param_init(0, "Hi", -1));
	return (run_tests("STDOUT", testlist));
}
