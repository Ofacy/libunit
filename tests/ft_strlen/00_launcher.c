/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:23 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 11:05:29 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	strlen_launcher(void)
{
	t_test	*test;

	test = NULL;
	return (run_tests(test));
}
