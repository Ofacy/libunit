/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:23 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 14:24:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int	strlen_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "OK", strlen_ok);
	add_test(&test, "KO", strlen_ko);
	add_test(&test, "Segfault", strlen_segfault);
	add_test(&test, "Bus error", strlen_buserror);
	return (run_tests("ft_strlen", test));
}
