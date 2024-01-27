/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_segfault.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:38:28 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 14:10:32 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit.h"

size_t	ft_strlen(const char *s);

int	strlen_segfault(void)
{
	const char	*str = NULL;

	if (ft_strlen(str) == strlen(str))
		return (TEST_OK);
	return (TEST_KO);
}
