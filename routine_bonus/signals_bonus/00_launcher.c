/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 19:34:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	signal_bonus_launcher(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "SIGABRT", test_sigabrt);
}
