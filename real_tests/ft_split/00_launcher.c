/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:02 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/27 16:05:41 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "../real_tests.h"

int	test_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "Basic test", split_basic_test());
	return (run_tests("test", test));
}
