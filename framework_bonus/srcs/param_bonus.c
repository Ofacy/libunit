/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:22:57 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 19:11:17 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"

t_param	param_init(unsigned int timeout, char *stdout)
{
	t_param	param;

	param.timeout = timeout;
	param.stdout = stdout;
	return (param);
}
