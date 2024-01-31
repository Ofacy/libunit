/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leakcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:02:08 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/31 01:26:10 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intercept.h"
#include <stdio.h>

int	has_potential_leaks(void)
{
	if (intercept_methods[method_fork].successfullcall > intercept_methods[method_wait].successfullcall)
	{
		return (1);
	}
	if (intercept_methods[method_malloc].successfullcall > intercept_methods[method_free].successfullcall)
	{
		return (1);
	}
	if (intercept_methods[method_open].successfullcall > intercept_methods[method_close].successfullcall)
	{
		return (1);
	}
	return (0);
}

int		print_potential_leaks(void)
{
	if (intercept_methods[method_fork].successfullcall > intercept_methods[method_wait].successfullcall)
	{
		return (printf("Potential process leaks detected, %ld fork for %ld wait\n", intercept_methods[method_fork].successfullcall, intercept_methods[method_wait].successfullcall));
	}
	if (intercept_methods[method_malloc].successfullcall > intercept_methods[method_free].successfullcall)
	{
		return (printf("Potential memory leaks detected, %ld malloc for %ld free\n", intercept_methods[method_malloc].successfullcall, intercept_methods[method_free].successfullcall));
	}
	if (intercept_methods[method_open].successfullcall + (intercept_methods[method_pipe].successfullcall * 2) > intercept_methods[method_close].successfullcall)
	{
		return (printf("Potential FD leaks detected, %ld open and %ld pipe for %ld close\n", intercept_methods[method_open].successfullcall, intercept_methods[method_pipe].successfullcall, intercept_methods[method_close].successfullcall));
	}
	return (0);
}