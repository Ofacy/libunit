/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:57:02 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 16:14:04 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

int	atoi_basic_test(void)
{
	if (ft_atoi("42") == atoi("42"))
		return (TEST_OK);
	return (TEST_KO);
}
