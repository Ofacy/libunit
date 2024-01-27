/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:35:07 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 20:55:47 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdout_bonus.h"

int	stdout_launcher(void)
{
	t_test	*testlist;

	testlist = NULL;
	add_test_param(&testlist, "Basic", stdout_basic_test, \
	param_init(0, "OK"));
	add_test_param(&testlist, "Invalid length", \
	stdout_invalid_length_test, param_init(0, "OK"));
	add_test_param(&testlist, "Invalid length 2", \
	stdout_invalid_length2_test, param_init(0, "OK"));
	add_test_param(&testlist, "Empty KO", stdout_empty_test, \
	param_init(0, "OK"));
	add_test_param(&testlist, "Empty OK", stdout_empty_test, \
	param_init(0, ""));
	return (run_tests("STDOUT", testlist));
}
