/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:23 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 15:04:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int	test_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "OK", test_ok);
	add_test(&test, "KO", test_ko);
	add_test(&test, "Segmentation Fault", test_segfault);
	add_test(&test, "Bus Error", test_buserror);
	return (run_tests("test", test));
}
