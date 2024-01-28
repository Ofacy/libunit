/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:44:53 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 10:55:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int	main(void)
{
	int	ret;

	ret = 0;
	if (TEST_ALL || TEST_ATOI)
		if (atoi_launcher() == -1)
			ret = -1;
	if (TEST_ALL || TEST_BZERO)
		if (bzero_launcher() == -1)
			ret = -1;
	if (TEST_ALL || TEST_LSTNEW)
		if (lst_new_launcher() == -1)
			ret = -1;
	return (ret);
}
