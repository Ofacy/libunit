/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_uninitialized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:49:34 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 16:51:23 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libunit.h"

int	stdout_uninitialized_test(void)
{
	char	str[20];

	str[0] = 'H';
	str[1] = 'i';
	str[2] = '\0';
	write(1, str, 20);
	return (TEST_OK);
}
