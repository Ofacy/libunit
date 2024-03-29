/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 20:34:25 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include "signals_bonus.h"

int	signal_bonus_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "Signal Abort", test_sigabrt);
	add_test(&test, "Floating-Point Exception", test_sigfpe);
	add_test(&test, "Broken Pipe", test_sigpipe);
	add_test(&test, "Illegal Instruction", test_sigill);
	return (run_tests("SIGNALS", test));
}
