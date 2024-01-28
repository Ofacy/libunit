/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:44:53 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 10:44:52 by alermolo         ###   ########.fr       */
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
	if (TEST_ALL || TEST_SPLIT)
		if (split_launcher() == -1)
			ret = -1;
	return (ret);
}
