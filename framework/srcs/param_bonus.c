/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:22:57 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 13:41:22 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"

t_param	param_init(unsigned int timeout, char *stdout, int expectedsignal)
{
	t_param	param;

	param.timeout = timeout;
	param.stdout = stdout;
	param.expectedsignal = expectedsignal;
	return (param);
}
