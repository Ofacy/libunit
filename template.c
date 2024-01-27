/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:52:54 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 16:18:53 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	test_template(void)
{
	int	is_success;

	is_success = 1;
	if (is_success)
		return (TEST_OK);
	return (TEST_KO);
}
