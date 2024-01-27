/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:11:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 16:43:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "libunit.h"

int	bzero_basic_test(void)
{
	char	*ptr1;
	char	*ptr2;
	int		status;

	ptr1 = malloc(10);
	if (!ptr1)
		return (TESTER_FAILED);
	ptr2 = malloc(10);
	if (!ptr2)
	{
		free(ptr1);
		return (TESTER_FAILED);
	}
	memset(ptr1, '*', 10);
	memset(ptr2, '*', 10);
	ft_bzero(ptr1, 3);
	bzero(ptr2, 3);
	bzero(ptr2, 3);
	if (!ft_strncmp(ptr1, ptr2, 10))
		status = TEST_OK;
	else
		status = TEST_KO;
	free(ptr1);
	free(ptr2);
	return (status);
}
