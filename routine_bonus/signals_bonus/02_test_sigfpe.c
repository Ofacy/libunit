/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_sigfpe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:33:02 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 19:20:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include <math.h>

int	test_sigfpe(void)
{
	int		lets_sigfpe1;
	float 	lets_sigfpe2;
	double	lets_sigfpe3;

	lets_sigfpe1 = 10 / 0;
	lets_sigfpe2 = FLT_MAX * 2.0;
	lets_sigfpe3 = sqrt(-1.0);
	return (TEST_OK);
}
