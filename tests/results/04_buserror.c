/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_buserror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:38:26 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 17:52:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>
#include "libunit.h"

int	test_buserror(void)
{
	char	*ptr;
	FILE	*f;

	f = tmpfile();
	ptr = mmap(NULL, 45, PROT_WRITE, MAP_PRIVATE, fileno(f), 0);
	*ptr = 0;
	return (TEST_OK);
}
