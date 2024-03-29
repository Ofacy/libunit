/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_underflow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:14:42 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 16:18:33 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

int	atoi_underflow_test(void)
{
	if (ft_atoi("-2147483649") == atoi("-2147483649"))
		return (TEST_OK);
	return (TEST_KO);
}
