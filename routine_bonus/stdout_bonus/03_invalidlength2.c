/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_invalidlength2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:50:16 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 20:53:08 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libunit_bonus.h"

int	stdout_invalid_length2_test(void)
{
	write(1, "O", 1);
	return (TEST_OK);
}
