/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:45:27 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 20:13:08 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intercept.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

t_method intercept_methods[] = {
	KEYS_DEF
};

int	intercept_enabled = 0;

int	init_intercept(void)
{
	for (int i = 0; i <= method_open; i++)
	{
		ft_vector_init(&intercept_methods[i].tofail, sizeof(t_error));
	}
	return (0);
}

int	free_intercept(void)
{
	intercept_enabled = 0;
	for (int i = 0; i <= method_open; i++)
	{
		ft_vector_free(&intercept_methods[i].tofail);
	}
	return (0);
}

t_error *get_error(int methodid)
{
	t_method	*method;
	t_error		*error;
	t_error		*temperror;

	
	if (!intercept_enabled)
		return (NULL);
	intercept_enabled = 0;
	intercept_enabled = 1;
	method = &intercept_methods[methodid];
	error = NULL;
	for (unsigned long i = 0; i < method->tofail.total; i++)
	{
		temperror = ft_vector_get(&method->tofail, i);
		if (temperror->callindex == method->callcount)
		{
			error = temperror;
			break;
		}
	}
	if (intercept_methods[methodid].hook)
		error = intercept_methods[methodid].hook(methodid, error);
	intercept_methods[methodid].callcount++;
	return (error);
}

t_error	new_error(unsigned long callindex, int err, int ret)
{
	t_error	error;

	error.callindex = callindex;
	error.errnooverride = err;
	error.returnvalue = ret;
	return (error);
}

int	add_error(int methodid, unsigned long callindex, int err, int ret)
{
	t_error	error;

	error = new_error(callindex, err, ret);
	ft_vector_add(&intercept_methods[methodid].tofail, &error);
	return (0);
}