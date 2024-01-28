/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:02 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/28 11:19:02 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "split.h"

int	split_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "Basic test", split_basic_test);
	add_test(&test, "Multiple separators", split_multiple_sep);
	add_test(&test, "Separator before string", split_sep_start);
	add_test(&test, "Separator after string", split_sep_end);
	add_test(&test, "Multiple sep at start and end", split_mult_start_end);
	add_test(&test, "Separator absent in string", split_no_sep);
	add_test(&test, "Empty string", split_empty);
	return (run_tests("SPLIT", test));
}
