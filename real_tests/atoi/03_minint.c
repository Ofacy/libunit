/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:03:24 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 16:05:18 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

int	atoi_minint_test(void)
{
	if (ft_atoi("-2147483648") == atoi("-2147483648"))
		return (TEST_OK);
	return (TEST_KO);
}
