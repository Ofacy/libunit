/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:52:54 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 13:08:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.a"

int	test_template(void)
{
	int	is_success;

	is_success = 1;
	if (is_success)
		return (TEST_OK);
	return (TEST_KO);
}

