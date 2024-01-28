/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_ko_segfault.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:09:06 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 14:09:44 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit_bonus.h"

size_t	ft_strlen(const char *s);

int	test_kosegfault(void)
{
	const char	*str = NULL;

	if (ft_strlen(str) == strlen(str))
		return (TEST_OK);
	return (TEST_KO);
}
