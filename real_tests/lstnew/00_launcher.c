/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:42:16 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 11:19:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "lst_new.h"

int	lst_new_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "char pointer", lstnew_char_pointer);
	add_test(&test, "int pointer", lstnew_int_pointer);
	add_test(&test, "void pointer", lstnew_void_pointer);
	add_test(&test, "null content", lstnew_null_content);
	return (run_tests("LSTNEW", test));
}
