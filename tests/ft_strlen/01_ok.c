/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:59:02 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 15:05:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit.h"

size_t	ft_strlen(const char *s);

int	test_ok(void)
{
	const char	*str = "Hello World!";

	if (ft_strlen(str) == strlen(str))
		return (TEST_OK);
	return (TEST_KO);
}
