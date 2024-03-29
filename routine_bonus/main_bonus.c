/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:21:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 13:57:33 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine_bonus.h"

int	main(void)
{
	int	ret;

	ret = 0;
	if (stdout_launcher() == -1)
		ret = -1;
	if (signal_bonus_launcher() == -1)
		ret = -1;
	if (timeout_launcher() == -1)
		ret = -1;
	if (expected_signal_launcher() == -1)
		ret = -1;
	return (ret);
}
