/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leakcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:02:08 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:12:49 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intercept.h"
#include <stdio.h>

int		print_potential_leaks(void)
{
	if (intercept_methods[method_malloc].successfullcall > intercept_methods[method_free].successfullcall)
	{
		return (printf("Potential memory leaks detected, %ld malloc for %ld free\n", intercept_methods[method_malloc].successfullcall, intercept_methods[method_free].successfullcall));
	}
	if (intercept_methods[method_open].successfullcall > intercept_methods[method_close].successfullcall)
	{
		return (printf("Potential FD leaks detected, %ld open for %ld close\n", intercept_methods[method_open].successfullcall, intercept_methods[method_close].successfullcall));
	}
	return (0);
}