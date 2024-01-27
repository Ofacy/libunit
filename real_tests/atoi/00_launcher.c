/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:57:52 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 17:53:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

int	atoi_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "Basic", atoi_basic_test);
	add_test(&test, "Max int", atoi_maxint_test);
	add_test(&test, "Min int", atoi_minint_test);
	add_test(&test, "Zero", atoi_zero_test);
	add_test(&test, "Basic (single space start)", atoi_space_test);
	add_test(&test, "Basic (multiple space start)", atoi_space_more_test);
	add_test(&test, "Invalid", atoi_invalid_test);
	add_test(&test, "Overflow", atoi_overflow_test);
	add_test(&test, "Underflow", atoi_underflow_test);
	return (run_tests("ATOI", test));
}
