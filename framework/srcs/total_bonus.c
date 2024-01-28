/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:02:47 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 23:03:34 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"

t_unit_total	init_total(void)
{
	t_unit_total	total;

	total.ko = 0;
	total.ok = 0;
	return (total);
}
