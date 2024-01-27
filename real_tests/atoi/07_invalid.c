/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_invalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:12:33 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 16:12:48 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"

int	atoi_invalid_test(void)
{
	if (ft_atoi("	 -invalid") == atoi("	 -invalid"))
		return (TEST_OK);
	return (TEST_KO);
}
