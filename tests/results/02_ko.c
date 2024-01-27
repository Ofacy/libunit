/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:39:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 15:03:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit.h"

size_t	ft_strlen(const char *s);

int	test_ko(void)
{
	const char	*str = "Hello World!";

	if (ft_strlen(str) == (size_t)-9)
		return (TEST_OK);
	return (TEST_KO);
}
