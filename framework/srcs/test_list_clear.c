/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:58:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 14:30:02 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
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
