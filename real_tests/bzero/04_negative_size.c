/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_negative_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:11:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/27 18:00:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "libunit.h"

int	bzero_negative_size(void)
{
	ft_bzero(NULL, -8);
	return (TEST_OK);
}
