/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_buserror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:38:26 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 14:10:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit.h"

size_t	ft_strlen(const char *s);

int	strlen_buserror(void)
{
	const char	*str = (const char *)0xFFFFFFFFFFFFF;

	if (ft_strlen(str) == strlen(str))
		return (TEST_OK);
	return (TEST_KO);
}
