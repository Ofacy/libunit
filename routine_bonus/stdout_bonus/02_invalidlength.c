/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_invalidlength.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:50:16 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 20:52:03 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libunit_bonus.h"

int	stdout_invalid_length_test(void)
{
	write(1, "OKthat'stoomany", 15);
	return (TEST_OK);
}
