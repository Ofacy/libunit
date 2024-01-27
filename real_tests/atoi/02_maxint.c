/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_maxint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:54 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 16:05:37 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

int	atoi_maxint_test(void)
{
	if (ft_atoi("2147483647") == atoi("2147483647"))
		return (TEST_OK);
	return (TEST_KO);
}
