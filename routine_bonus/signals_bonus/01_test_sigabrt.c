/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_sigabrt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:33:02 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 19:08:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit_bonus.h"

int	test_sigabrt(void)
{
	abort();
	return (TEST_OK);
}
