/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:05:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 16:49:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "bzero.h"

int	bzero_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "basic test", bzero_basic_test);

	return (run_tests("test", test));
}
