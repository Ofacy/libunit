/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_clear_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:58:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 18:20:23 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <stdlib.h>

void	test_list_clear(t_test **test)
{
	t_test	*tmp;

	while (*test)
	{
		tmp = *test;
		*test = (*test)->next;
		free(tmp);
	}
}
