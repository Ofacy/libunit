/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_preload.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:47:11 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 19:55:33 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intercept.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	exit_handle(void)
{
	intercept_enabled = 0;
	print_potential_leaks();
	free_intercept();
}

__attribute__((constructor)) void runs_first(void) {
	init_intercept();
	init_failtree();
	intercept_enabled = 1;
	if (atexit(exit_handle))
	{
		perror("Failed to register exit handle");
	}
};
