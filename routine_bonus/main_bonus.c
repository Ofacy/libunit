/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:21:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 19:33:35 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "routine_bonus.h"

int	main(void)
{
	int	ret;

	ret = 0;
	if (signal_bonus_launcher() == -1)
		ret = -1;
	return (ret);
}
