/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:42:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 10:57:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "lst_new.h"

int	lst_new_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "basic test", lstnew_basic_test);
	add_test(&test, "null content", lstnew_null_contect);
	// add_test(&test, "null (should SEGV)", bzero_null);
	return (run_tests("LSTNEW", test));
}
