/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:05:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 14:09:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "bzero.h"

int	bzero_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "basic test", bzero_basic_test);
	add_test(&test, "size 0", bzero_size_zero);
	add_test(&test, "null", bzero_null);
	add_test(&test, "negative size", bzero_negative_size);
	return (run_tests("BZERO", test));
}
