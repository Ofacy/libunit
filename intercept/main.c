/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:21:01 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:14:55 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intercept.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*ptr;

	if (init_intercept())
	{
		return (1);
	}
	init_failtree();
	intercept_enabled = 1;
	ptr = malloc(sizeof(int));
	if (ptr)
	{
		*ptr = 42;
		free(ptr);
	}
	intercept_enabled = 0;
	print_potential_leaks();
	if (free_intercept())
	{
		perror("Failed to free intercept");
	}
	return (0);
}
